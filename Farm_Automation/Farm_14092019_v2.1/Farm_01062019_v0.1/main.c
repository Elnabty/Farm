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




volatile unsigned char gUartRFlag=0;
volatile unsigned char gUartData=0;
extern volatile unsigned char oneSec;
uint8_t manualflag = 0;
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
	

		float ftemperature = 0;
		float fhumidity = 0;
		int8_t temperature = 0;
		int8_t humidity = 0;
		
	unsigned char tempString[] = {'T','e','m','p',':','\0'};
	unsigned char humString[] =  {'H','u','m','d',':','\0'};
	unsigned char sensor0[] = {'S','e','n','s','o','r','1','\0'};
	unsigned char sensor1[] = {'S','e','n','s','o','r','2','\0'};			
	unsigned char buffer[3]; //used in itoa 

	//sei();
	cli();
	PORTB = 0u;
	_delay_ms(1000);
	_delay_ms(1000);
	_delay_ms(1000);
	_delay_ms(1000);
	_delay_ms(1000);
	oldTime = oneSec;
	sei();
	while(1){
			
		
		if(oneSec != oldTime)
		{
			oldTime = oneSec;
			
			if(five_sec == 5u)
			{		
					cli();
					/*dht_getdata_dht_22(&ftemperature,&fhumidity,0);
					dtostrf(ftemperature, 3, 3, buffer);
					UART_string_tx(sensor0);
					UART_string_tx(tempString);
					UART_string_tx(buffer);
					dtostrf(fhumidity, 3, 3, buffer);
					UART_string_tx(humString);
					UART_string_tx(buffer);
					UART_tx('\n');*/
					
					dht_getdata_dht_11(&temperature,&humidity,1);
					itoa(temperature,buffer,10);
					UART_tx('[');
					UART_string_tx(sensor1);
					UART_string_tx(tempString);
					UART_string_tx(buffer);
					UART_tx(']');
					UART_tx('\n');
					_delay_ms(10);
					itoa(humidity, buffer, 10);
					UART_tx('[');
					UART_string_tx(sensor1);
					UART_string_tx(humString);
					UART_string_tx(buffer);
					UART_tx(']');
					UART_tx('\n');
					
					five_sec = 0u;	
					sei();
					
			}
			else
			{
				five_sec++;
			}

			if(sec_3 == 3u)
			{
	cli();

	if (  /*dht_getdata_dht_22(&ftemperature,&fhumidity,0)!=-1  &&*/ dht_getdata_dht_11(&temperature,&humidity,1) == 0 )
	{
		int8_t temp_avr;
		int8_t humd_avr;
		temp_avr = ( (ftemperature+temperature)/2 );
		humd_avr = ((fhumidity+humidity)/2);
		
		if(temp_avr > 30 || humd_avr > 67)
		{
			VENTILATION_ON;
			FAN_ON;
		}
		
		else if (manualflag == 0)
		{
			VENTILATION_OFF;
			FAN_OFF;
		}
		
	}
	else
	{
		//UART_string_tx("FATAL ERROR!");
		FAN_ON;
		VENTILATION_ON;
	}
	sec_3=0u;
	sei();

	

}

else{sec_3++;}

			
		}
		
		
		if( gUartRFlag == 1 )
		{
				cli();//cretical section 
				UART_tx(gUartData);
				//relayModuleControl( gUartData);
				
			switch (gUartData)
			{
				
			
			case '1':
				/*	dht_getdata_dht_22(&ftemperature,&fhumidity,0);
					dtostrf(ftemperature, 3, 3, buffer);
					UART_string_tx(sensor0);
					UART_string_tx(tempString);
					UART_string_tx(buffer);
					dtostrf(fhumidity, 3, 3, buffer);
					UART_string_tx(humString);
					UART_string_tx(buffer);
					UART_tx('\n');*/
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
			
			default:UART_tx(gUartData);//UART_string_tx("wrong request");
			}
			
	
			
			gUartRFlag=0;
			_delay_ms(1000);
			sei();
			
		}
			


		
    		
	}
}

