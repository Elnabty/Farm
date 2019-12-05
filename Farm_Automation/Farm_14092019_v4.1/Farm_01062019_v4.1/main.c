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
#include "config.h"


float ftemperature = 0;
float fhumidity = 0;
int8_t temperature = 0;
int8_t humidity = 0;

unsigned char tempString[] = {'T','e','m','p',':','\0'};
unsigned char humString[] =  {'H','u','m','d',':','\0'};
unsigned char sensor0[] = {'S','e','n','s','o','r','1','\0'};
unsigned char sensor1[] = {'S','e','n','s','o','r','2','\0'};
unsigned char buffer[4]; //used in itoa
uint32_t waterLevel = 0;

volatile uint8_t  newData = FALSE;
volatile unsigned char receivedChars[31];


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
    while(1)
    {


      //  task_PERIODIC();

        if(oneSec != oldTime)
        {
            oldTime = oneSec;

            if(five_sec == 5u)
            {
                task_5sec();
                five_sec = 0;
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

            else
            {

                sec_3++;

            }


        }



    }






}

