/*
DHT Library 0x03

copyright (c) Davide Gironi, 2012

Released under GPLv3.
Please refer to LICENSE file for licensing information.
*/


#include <stdio.h>
#include <string.h>
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

#include "dht.h"

/*
 * get data from sensor
 */

int8_t dht_getdata_dht_11(int8_t *temperature, int8_t *humidity,uint8_t channel) {

	uint8_t bits[5];
	uint8_t i,j = 0;

	memset(bits, 0, sizeof(bits));

	//reset port
	DHT_DDR |= (1<<channel); //output
	DHT_PORT |= (1<<channel); //high
	_delay_ms(100);

	//send request
	DHT_PORT &= ~(1<<channel); //low
	
		_delay_ms(18);
	
	
	
	DHT_PORT |= (1<<channel); //high
	DHT_DDR &= ~(1<<channel); //input
	_delay_us(40);

	//check start condition 1
	if((DHT_PIN & (1<<channel))) {
		return -1;
	}
	_delay_us(80);
	//check start condition 2
	if(!(DHT_PIN & (1<<channel))) {
		return -1;
	}
	_delay_us(80);

	//read the data
	uint16_t timeoutcounter = 0;
	for (j=0; j<5; j++) { //read 5 byte
		uint8_t result=0;
		for(i=0; i<8; i++) {//read every bit
			timeoutcounter = 0;
			while(!(DHT_PIN & (1<<channel))) { //wait for an high input (non blocking)
				timeoutcounter++;
				if(timeoutcounter > DHT_TIMEOUT) {
					return -1; //timeout
				}
			}
			_delay_us(30);
			if(DHT_PIN & (1<<channel)) //if input is high after 30 us, get result
				result |= (1<<(7-i));
			timeoutcounter = 0;
			while(DHT_PIN & (1<<channel)) { //wait until input get low (non blocking)
				timeoutcounter++;
				if(timeoutcounter > DHT_TIMEOUT) {
					return -1; //timeout
				}
			}
		}
		bits[j] = result;
	}

	//reset port
	DHT_DDR |= (1<<channel); //output
	DHT_PORT |= (1<<channel); //low
	_delay_ms(100);

	//check checksum
	if ((uint8_t)(bits[0] + bits[1] + bits[2] + bits[3]) == bits[4]) {
		//return temperature and humidity
		
			*temperature = bits[2];
			*humidity = bits[0];
		



		
		return 0;
	}

	return -1;
}


int8_t dht_getdata_dht_22(float *temperature, float *humidity,uint8_t channel) {

	uint8_t bits[5];
	uint8_t i,j = 0;

	memset(bits, 0, sizeof(bits));

	//reset port
	DHT_DDR |= (1<<channel); //output
	DHT_PORT |= (1<<channel); //high
	_delay_ms(100);

	//send request
	DHT_PORT &= ~(1<<channel); //low
	
	

		_delay_us(500);
	
	
	
	DHT_PORT |= (1<<channel); //high
	DHT_DDR &= ~(1<<channel); //input
	_delay_us(40);

	//check start condition 1
	if((DHT_PIN & (1<<channel))) {
		return -1;
	}
	_delay_us(80);
	//check start condition 2
	if(!(DHT_PIN & (1<<channel))) {
		return -1;
	}
	_delay_us(80);

	//read the data
	uint16_t timeoutcounter = 0;
	for (j=0; j<5; j++) { //read 5 byte
		uint8_t result=0;
		for(i=0; i<8; i++) {//read every bit
			timeoutcounter = 0;
			while(!(DHT_PIN & (1<<channel))) { //wait for an high input (non blocking)
				timeoutcounter++;
				if(timeoutcounter > DHT_TIMEOUT) {
					return -1; //timeout
				}
			}
			_delay_us(30);
			if(DHT_PIN & (1<<channel)) //if input is high after 30 us, get result
			result |= (1<<(7-i));
			timeoutcounter = 0;
			while(DHT_PIN & (1<<channel)) { //wait until input get low (non blocking)
				timeoutcounter++;
				if(timeoutcounter > DHT_TIMEOUT) {
					return -1; //timeout
				}
			}
		}
		bits[j] = result;
	}

	//reset port
	DHT_DDR |= (1<<channel); //output
	DHT_PORT |= (1<<channel); //low
	_delay_ms(100);

	//check checksum
	if ((uint8_t)(bits[0] + bits[1] + bits[2] + bits[3]) == bits[4]) {



			uint16_t rawhumidity = bits[0]<<8 | bits[1];
			uint16_t rawtemperature = bits[2]<<8 | bits[3];
			if(rawtemperature & 0x8000) {
				*temperature = (float)((rawtemperature & 0x7FFF) / 10.0) * -1.0;
				} else {
				*temperature = (float)(rawtemperature)/10.0;
			}
			*humidity = (float)(rawhumidity)/10.0;
		

		
		return 0;
	}

	return -1;
}




