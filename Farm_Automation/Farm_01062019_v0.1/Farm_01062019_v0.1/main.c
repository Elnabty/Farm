/*
 * Farm_01062019_v0.1.c
 *
 * Created: 6/1/2019 1:56:18 AM
 * Author : hmd-e
 */ 

#define F_CPU 11059200UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
 unsigned char gUartRFlag=0;
 unsigned char gUartData=0;
#include "UART.h"




int main(void)
{
    UART_int();
	_delay_ms(5);
	sei();
	unsigned char x=0;
    while (1) 
    {
		if( gUartRFlag == 1  )
		{
			UART_tx('E');
			UART_tx('S');
			UART_tx('S');
			UART_tx('A');
			UART_tx('M');
			
			gUartRFlag=0;
		}
		_delay_ms(1000);
		
		
    }
}

