/*
 * timer.c
 *
 * Created: 9/2/2019 4:10:39 PM
 *  Author: aelnabty
 */ 
#include "timer.h"
volatile unsigned char oneSec = 0u;
volatile unsigned long timer1_counter;
extern unsigned char i;
void timer1_init(void)
{


  TCCR1B |= (1<<CS12)|(1<<CS10)|(1<<WGM12);
  TIMSK1 |= (1<<TOIE1)|(1<<OCIE1A);
  OCR1AH = 0x3D;
  OCR1AL = 0x09;
	

	
}


ISR (TIMER1_COMPA_vect)    // Timer1 ISR
{

	PORTB ^=(1<<PB7);
	
}

