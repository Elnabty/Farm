/*
 * timer.h
 *
 * Created: 9/2/2019 4:10:17 PM
 *  Author: aelnabty
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "config.h"

#define TIMER0_INTER_ENABLE TIMSK0|=(1<<OCIE0A);//timer compare interrupt enable , timer overflow interrupt enable
#define TIMER0_INTER_DISABLE TIMSK0&=~(1<<OCIE0A);
#define DEGREE_360 (200U) 
void timer1_init(void); //1 sec
void timer0_init(void);//500uSec



#endif /* TIMER_H_ */