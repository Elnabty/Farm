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

#include "UART.h"
#include "dht.h"
#include <stdlib.h>
 unsigned char gUartRFlag=0;
 unsigned char gUartData=0;

int main(void)
{
    UART_int();
	_delay_ms(5);
	float temperature = 0;
	float humidity = 0;
		
	
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
			
			dht_gettemperaturehumidity(&temperature, &humidity);
			dtostrf(temperature, 3, 3, buffer);
			UART_string_tx(sensor0);
			UART_string_tx(tempString);
			UART_string_tx(buffer);
			dtostrf(humidity, 3, 3, buffer);
			UART_string_tx(humString);
			UART_string_tx(buffer);
			UART_tx('\n');
			
			
			gUartRFlag=0;
			sei();
			
		}
    		_delay_ms(1000);
	}
}

