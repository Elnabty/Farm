/*
 * Test_modules_mega2560.c
 *
 * Created: 9/7/2019 11:07:27 PM
 * Author : aelnabty
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "timer.h"

unsigned char i = 1u;
int main(void)
{
    /* Replace with your application code */
	DDRB = 0xF0;
	PORTB &= ~(1<<PB7);
	timer1_init();
	sei();
    while (1) 
    {

		
		
		
		
		
    }
}

