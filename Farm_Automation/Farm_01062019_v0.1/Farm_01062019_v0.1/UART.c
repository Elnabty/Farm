/*
 * UART.c
 *
 * Created: 8/23/2018 7:42:22 PM
 *  Author: hmd-e
 */ 

#include "UART.h"


extern unsigned char gUartRFlag;
extern unsigned char gUartData;
void UART_int()
{
	//UCSRA=(1<<U2X); // set double speed
	UCSRB=(1<<RXCIE)|(1<<RXEN)|(1<<TXEN);   // enable Tx Rx and Rx interrupt
	UCSRC=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0); // 8 bit data
	_delay_us(10);
	UCSRC&=~(1<<URSEL);
	UBRRH = (unsigned char)(UBRRset>>8);
	UBRRL= (unsigned char)(UBRRset);
	
}

void UART_tx(unsigned char x)
{
	while( !( UCSRA & (1<<UDRE)));
	UDR=x;
}

ISR(USART_RXC_vect)
{
	cli();
	
	gUartRFlag=1;
	gUartData=UDR;

	sei();
	
}