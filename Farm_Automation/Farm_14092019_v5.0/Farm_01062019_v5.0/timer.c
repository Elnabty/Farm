/*
 * timer.c
 *
 * Created: 9/2/2019 4:10:39 PM
 *  Author: aelnabty
 */ 
#include "timer.h"
volatile unsigned char oneSec = 0u;
volatile uint16_t number_of_rotation = 0u;
volatile uint8_t Medicine;

void timer1_init(void)
{


	TCCR1B |= (1<<CS12)|(1<<CS10)|(1<<WGM12);// prescaler 1024, timer compare
	TIMSK1 |= (1<<TOIE1)|(1<<OCIE1A);//timer compare interrupt enable , timer overflow interrupt enable
	OCR1AH = 0x3D; // 1 sec compare match
	OCR1AL = 0x09;
	

	
}

void timer0_init(void)
{

	TCCR0A |= (1<<WGM01);
	TCCR0B = (1<<CS01)|(1<<CS00);// no Prescaler
	OCR0A = 125;
	//TIMSK0 |= (1<<OCIE0A);

	
}


ISR (TIMER1_COMPA_vect)    // Timer1 ISR
{
	
	
	oneSec ++;
	
	
}

ISR (TIMER0_COMPA_vect)    // Timer0 ISR
{
	uint8_t buffer[5];
	itoa(number_of_rotation,buffer,10);

	switch(Medicine)
	{
		case 1: MED_1_TOGGLE;UART_string_tx("okM\n");number_of_rotation--;break;
		case 2: MED_2_TOGGLE;number_of_rotation--;break;
		default: break;
	}
	if(number_of_rotation == 0u)
	{
		UART_string_tx("okKKKK\n");
		A4899_DIS;
		TIMER0_INTER_DISABLE;
	}
	
}