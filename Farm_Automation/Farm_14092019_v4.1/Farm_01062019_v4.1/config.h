/*
 * config.h
 *
 * Created: 9/19/2019 6:46:30 PM
 *  Author: aelnabty
 */ 


#ifndef CONFIG_H_
#define CONFIG_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "packetsConfig.h"
#include "UART.h"
#include "dht.h"
#include "GPIOcontrol.h"
#include "timer.h"
#include "usound.h"
#include "circularQueue.h"
#include "espATCommand.h"

#define FALSE 0U
#define TRUE 1U

		extern	float ftemperature ;
		extern float fhumidity ;
		extern int8_t temperature ;
		extern int8_t humidity ;
		
		extern unsigned char tempString[] ;
		extern unsigned char humString[] ;
		extern unsigned char sensor0[] ;
		extern unsigned char sensor1[] ;
		extern unsigned char buffer[4]; //used in itoa
		extern uint32_t waterLevel ;

		extern volatile uint8_t  newData ;
		extern volatile unsigned char receivedChars[31];

#endif /* CONFIG_H_ */