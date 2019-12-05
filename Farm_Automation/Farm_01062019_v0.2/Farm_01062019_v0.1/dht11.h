
#ifndef __dht11_h__
#define __dht11_h__
#define F_CPU 11059200UL
//setup parameters
#define DHT11_DDR DDRA
#define DHT11_PORT PORTA
#define DHT11_PIN PINA
#define channel_0 PA0 //dht11
#define channel_1 PA1 //dht22

#define DHT11_DATA_TEMPERATURE 0
#define DHT11_DATA_HUMIDITY 1
#define DHT11_ERROR 150

uint8_t dht11_get_data(uint8_t *,unsigned char channel);

#endif