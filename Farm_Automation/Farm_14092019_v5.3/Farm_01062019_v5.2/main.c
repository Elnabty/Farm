/*
 * Farm_01062019_v0.1.c
 *
 * Created: 6/1/2019 1:56:18 AM
 * Author : hmd-e
 */

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


unsigned char buffer[4]; //used in itoa
uint32_t waterLevel = 0;

volatile uint8_t  newData = FALSE;
volatile unsigned char receivedChars[31];


extern volatile unsigned char oneSec;

int main(void)
{

	GPIO_init();
    timer1_init();
    timer0_init();
    unsigned char oldTime = 0;
    unsigned char sec_5 = 0;
    unsigned char sec_3 = 0u;
    uint8_t sec_4 = 0u;
    uint8_t sec_10 = 0u;
    Json Jdata;

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
	 wdt_enable(WDTO_8S);
	 wdt_reset();
    Jdata.field1=1;
    Jdata.field2=1;
    Jdata.field3=1;
    Jdata.field4=1;
    Jdata.field5=0;
    Jdata.field6=0;
    Jdata.field7=0;
    Jdata.field8=0;
    ESP_write_Fields(&Jdata,SELONOID_WRITE_APIKEY,1,8);
    while(1)
        {


               

            


			 wdt_reset();
            

            if(oneSec != oldTime)
                {
                    oldTime = oneSec;




                    if(sec_5 == 5u)
                        {
                            task_5sec();
                            sec_5 = 0;
                        }
                    else
                        {
                            sec_5++;
                        }

                    if(sec_10 == 10u)

                        {
                            task_10sec();
                            sec_10=0u;

                        }

                    else
                        {

                            sec_10++;

                        }



                    if(sec_4 == 4u)
                        {
                            task_4Sec();
                            sec_4 = 0;
                        }
                    else
                        {
                            sec_4++;
                        }


                }



        }






}

