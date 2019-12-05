/*
 * Farm_01062019_v0.1.c
 *
 * Created: 6/1/2019 1:56:18 AM
 * Author : hmd-e
 */ 

#define F_CPU 11059200UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
volatile unsigned char gUartRFlag=0;
volatile unsigned char gUartData=0;
#include "UART.h"
#include "dht.h"
#include <stdlib.h>

#define FAN 0
#define FAN_ON PORTC&=~(1<<FAN);
#define FAN_OFF PORTC|=(1<<FAN);

#define LED 1
#define LED_ON PORTC&=~(1<<LED);
#define LED_OFF PORTC|=(1<<LED);

uint8_t manualflag = 0;
int main(void)
{
    UART_int();
	_delay_ms(5);
	DDRC = 0xFF;
	PORTC = 0;
		float ftemperature = 0;
		float fhumidity = 0;
		int8_t temperature = 0;
		int8_t humidity = 0;
		
	unsigned char tempString[] = {'T','e','m','p',' ','=',' ','\0'};
	unsigned char humString[] = {'H','u','m','d',' ','=',' ','\0'};
	unsigned char sensor0[] = {'S','e','n','s','o','r','1',' ','\0'};
	unsigned char sensor1[] = {'S','e','n','s','o','r','2',' ','\0'};			
	unsigned char buffer[3]; //used in itoa 

	sei();
	
	_delay_ms(1000);
	while(1){
		
		if( gUartRFlag == 1 )
		{
				cli();//cretical section 
				UART_tx(gUartData);
			switch (gUartData)
			{
				
			
			case '1':
					dht_getdata_dht_22(&ftemperature,&fhumidity,0);
					dtostrf(ftemperature, 3, 3, buffer);
					UART_string_tx(sensor0);
					UART_string_tx(tempString);
					UART_string_tx(buffer);
					dtostrf(fhumidity, 3, 3, buffer);
					UART_string_tx(humString);
					UART_string_tx(buffer);
					UART_tx('\n');
					dht_getdata_dht_11(&temperature,&humidity,1);
					itoa(temperature,buffer,10);
					UART_string_tx(sensor1);
					UART_string_tx(tempString);
					UART_string_tx(buffer);
					itoa(humidity, buffer, 10);
					UART_string_tx(humString);
					UART_string_tx(buffer);
					UART_tx('\n');		
			
			break;
			
			case '2': FAN_ON;manualflag=1; break;
			case '3': FAN_OFF;manualflag=0;break;
			
			default:UART_string_tx("wrong request");
			}
			
	
			
			gUartRFlag=0;
			_delay_ms(1000);
			sei();
			
		}
		
		if (  dht_getdata_dht_22(&ftemperature,&fhumidity,0)!=-1  && dht_getdata_dht_11(&temperature,&humidity,1)!=-1 )
		{
				int8_t temp_avr;
				int8_t humd_avr;
				temp_avr = ( (ftemperature+temperature)/2 );
				humd_avr = ((fhumidity+humidity)/2);
				
				if(temp_avr > 30 || humd_avr > 67)
				{
					FAN_ON
				}
				
				else if (manualflag == 0)
				{
					FAN_OFF
				}
			
		}
		else
		{
						UART_string_tx("FATAL ERROR!");
						FAN_ON
		}
		
    		_delay_ms(1000);
	}
}

