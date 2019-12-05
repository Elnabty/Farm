/*
DHT Library 0x03

copyright (c) Davide Gironi, 2012

Released under GPLv3.
Please refer to LICENSE file for licensing information.

References:
  - DHT-11 Library, by Charalampos Andrianakis on 18/12/11
*/


#ifndef DHT_H_
#define DHT_H_

#include <stdio.h>
#include <avr/io.h>

//setup port
#define DHT_DDR DDRA
#define DHT_PORT PORTA
#define DHT_PIN PINA
#define DHT_INPUTPIN PA0



//timeout retries
#define DHT_TIMEOUT 200

//functions
int8_t dht_getdata_dht_11(int8_t *temperature, int8_t *humidity ,uint8_t channel);
int8_t dht_getdata_dht_22(float *temperature, float *humidity ,uint8_t channel);

#endif
