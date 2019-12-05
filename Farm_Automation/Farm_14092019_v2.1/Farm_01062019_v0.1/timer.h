/*
 * timer.h
 *
 * Created: 9/2/2019 4:10:17 PM
 *  Author: aelnabty
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#define F_CPU 16000000UL

#include <avr/io.h>

#include <avr/interrupt.h>

#include <stdlib.h>



void timer1_init(void); //1 sec




#endif /* TIMER_H_ */