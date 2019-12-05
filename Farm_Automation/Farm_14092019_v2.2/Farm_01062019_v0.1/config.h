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
#include "packetsConfig.h"
#include "UART.h"
#include "dht.h"
#include "GPIOcontrol.h"
#include "timer.h"


		float ftemperature = 0;
		float fhumidity = 0;
		int8_t temperature = 0;
		int8_t humidity = 0;
		
		unsigned char tempString[] = {'T','e','m','p',':','\0'};
		unsigned char humString[] =  {'H','u','m','d',':','\0'};
		unsigned char sensor0[] = {'S','e','n','s','o','r','1','\0'};
		unsigned char sensor1[] = {'S','e','n','s','o','r','2','\0'};
		unsigned char buffer[3]; //used in itoa



#endif /* CONFIG_H_ */