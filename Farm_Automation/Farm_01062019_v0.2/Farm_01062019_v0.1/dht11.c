
#define F_CPU 11059200UL
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include "dht11.h"

uint8_t dht11_get_data(uint8_t * buff,unsigned char channel) {
	uint8_t bits[5];
	uint8_t i, j = 0;

	//reset port
	DHT11_DDR |= (1 << channel); //output
	DHT11_PORT |= (1 << channel); //high
	_delay_ms(100);

	//send request
	DHT11_PORT &= ~(1 << channel); //low
	_delay_ms(18);
	DHT11_PORT |= (1 << channel); //high
	_delay_us(1);
	DHT11_DDR &= ~(1 << channel); //input
	_delay_us(39);

	//check start condition 1
	if ((DHT11_PIN & (1 << channel))) {
		return DHT11_ERROR;
	}
	_delay_us(80);
	//check start condition 2
	if (!(DHT11_PIN & (1 << channel))) {
		return DHT11_ERROR;
	}
	_delay_us(80);

	//read the data
	for (j = 0; j < 5; j++) { //read 5 byte
		uint8_t result = 0;
		for (i = 0; i < 8; i++) { //read every bit
			while (!(DHT11_PIN & (1 << channel)))
				; //wait for an high input
			_delay_us(30);
			if (DHT11_PIN & (1 << channel)) //if input is high after 30 us, get result
				result |= (1 << (7 - i));
			while (DHT11_PIN & (1 << channel))
				; //wait until input get low
		}
		bits[j] = result;
	}

	//reset port
	DHT11_DDR |= (1 << channel); //output
	DHT11_PORT |= (1 << channel); //low
	_delay_ms(100);

	//check checksum
	if (bits[0] + bits[1] + bits[2] + bits[3] == bits[4]) 
	{
		buff[0] = bits[2];
		buff[1] = bits[0];
		// if (select == DHT11_DATA_TEMPERATURE) { //return temperature
		// 	return (bits[2]);
		// } else if (select == DHT11_DATA_HUMIDITY)
		// { //return humidity
		// 	return (bits[0]);
		// }
		return 1;
	}

	return DHT11_ERROR;
}
