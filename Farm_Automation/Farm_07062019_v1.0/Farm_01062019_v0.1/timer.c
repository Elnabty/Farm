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
	TCNT1 = 44219u;   // for 1 sec at 11059200 MHz

	TCCR1A = 0x00;
	TCCR1B = (1<<CS10) | (1<<CS12);;  // Timer mode with 1024 prescler
	TIMSK = (1 << TOIE1) ;   // Enable timer1 overflow interrupt(TOIE1)
	
}


ISR (TIMER1_OVF_vect)    // Timer1 ISR
{
	
	TCNT1 = 44219u;   // for 1 sec at 11059200 MHz
	oneSec ++;
	
}