/*
 * timer.c
 *
 * Created: 9/2/2019 4:10:39 PM
 *  Author: aelnabty
 */ 
#include "timer.h"
volatile unsigned char oneSec = 0u;

void timer1_init(void)
{


	TCCR1B |= (1<<CS12)|(1<<CS10)|(1<<WGM12);// prescaler 1024, timer compare
	TIMSK1 |= (1<<TOIE1)|(1<<OCIE1A);//timer compare interrupt enable , timer overflow interrupt enable
	OCR1AH = 0x3D; // 1 sec compare match
	OCR1AL = 0x09;
	

	
}


ISR (TIMER1_COMPA_vect)    // Timer1 ISR
{
	
	
	oneSec ++;
	
	
}