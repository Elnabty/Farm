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
 unsigned char gUartRFlag=0;
 unsigned char gUartData=0;
#include "UART.h"
#include "dht11.h"
#include <stdlib.h>



int main(void)
{
    UART_int();
	_delay_ms(5);
	uint8_t tempHumData_channel0[3]; //dht11 data from first sensor
	uint8_t tempHumData_channel1[3]; //dht22 data from second sensor
	unsigned char tempString[] = {'T','e','m','p',' ','=',' ','\0'};
	unsigned char humString[] = {'H','u','m','d',' ','=',' ','\0'};
	unsigned char sensor0[] = {'S','e','n','s','o','r','1',' ','\0'};
	unsigned char sensor1[] = {'S','e','n','s','o','r','2',' ','\0'};			
	unsigned char buffer[3]; //used in itoa 

	sei();
	
	_delay_ms(1000);
	while(1){
		
		if(gUartRFlag == 1  )
		{
				cli();//cretical section 
			
			dht11_get_data(tempHumData_channel0,channel_0);
			itoa(tempHumData_channel0[0],buffer,10);
			UART_string_tx(sensor0);
			UART_string_tx(tempString);
			UART_string_tx(buffer);
			itoa(tempHumData_channel0[1],buffer,10);
			UART_string_tx(humString);
			UART_string_tx(buffer);
			
			
			dht11_get_data(tempHumData_channel1,channel_1);
			itoa(tempHumData_channel1[0],buffer,10);
			UART_string_tx(sensor1);
			UART_string_tx(tempString);
			UART_string_tx(buffer);
			itoa(tempHumData_channel1[1],buffer,10);
			UART_string_tx(humString);
			UART_string_tx(buffer);
			
			gUartRFlag=0;
			sei();
			
		}
    		_delay_ms(1000);
	}
}

