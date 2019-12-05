/*
 * UART.c
 *
 * Created: 8/23/2018 7:42:22 PM
 *  Author: hmd-e
 */ 

#include "UART.h"


void UART_int()
{
	//UCSRA=(1<<U2X); // set double speed
	UCSR0B=(1<<RXCIE0)|(1<<RXEN0)|(1<<TXEN0);   // enable Tx Rx and Rx interrupt
	UCSR0C=(1<<UCSZ01)|(1<<UCSZ00); // 8 bit data
	_delay_us(10);
	UBRR0H = (unsigned char)(UBRRset>>8);
	UBRR0L= (unsigned char)(UBRRset);
	 
	
}

void UART_tx(unsigned char x)
{
	while( !( UCSR0A & (1<<UDRE0)));
	UDR0=x;
}

void UART_string_tx(unsigned char *x)
{
	unsigned char i=0;
	while(x[i] !='\0')
	{
		UART_tx( x[i] );
		i++;
	}
}

void recvWithStartEndMarkers(uint8_t Data)
{
	static uint8_t recvInProgress = FALSE;
	static uint8_t ndx = 0;
	char startMarker = '[';
	char endMarker = ']';
	

		char rc = Data;
		if (recvInProgress == TRUE)
		{
			if (rc != endMarker)
			{
				if (ndx < MAXDATALENGTH) { receivedChars[ndx] = rc; ndx++;  }
			}
			else
			{
				receivedChars[ndx] = '\0'; // terminate the string
				recvInProgress = FALSE;
				ndx = 0;
				newData = TRUE;
			}
		}
		else if (rc == startMarker) { recvInProgress = TRUE; }
	}
	


ISR(USART0_RX_vect)
{
	cli();
	
	

	
	recvWithStartEndMarkers(UDR0);

	sei();
	
}

