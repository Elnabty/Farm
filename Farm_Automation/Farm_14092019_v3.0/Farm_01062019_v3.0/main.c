/*
 * Farm_01062019_v0.1.c
 *
 * Created: 6/1/2019 1:56:18 AM
 * Author : hmd-e
 */ 
//#define F_CPU 16000000UL
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
#include "usound.h"





extern volatile unsigned char oneSec;

int main(void)
{
	DDRB_CONFIG;
	PORTB_COMFIG;
	DDRC_CONFIG;
	PORTC_COMFIG;
	timer1_init();
	unsigned char oldTime = 0;
	unsigned char five_sec = 0;
	unsigned char sec_3 = 0u;
	
	
     UART_int();
	_delay_ms(5);
	



	//sei();
	cli();
	PORTB = 0u;
	usound_init();	
	_delay_ms(1000);
	_delay_ms(1000);
	_delay_ms(1000);
	_delay_ms(1000);
	_delay_ms(1000);
	oldTime = oneSec;
		
	sei();
	while(1){
			
		
		task_PERIODIC();
		
		if(oneSec != oldTime)
		{
			oldTime = oneSec;
			
			if(five_sec == 5u)
			{		
				task_5sec();
					
			}
			else
			{
				five_sec++;
			}

			if(sec_3 == 3u)
	
			{
				task_10sec();
				sec_3=0u;
		
			}

			else{
				
				sec_3++;
				
				}

			
		}
		
		
			
		}
			


		
    		
	
}

