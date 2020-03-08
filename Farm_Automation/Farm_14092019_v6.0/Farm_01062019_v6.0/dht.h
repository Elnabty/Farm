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

#include "config.h"


/*ADDRES*/
#define dht_1_DDRC 0x07
#define dht_2_DDRG 0x13
#define dht_3_DDRL 0x10A

#define dht_1_PORTC 0x08
#define dht_2_PORTG 0x14
#define dht_3_PORTL 0x10B

#define dht_1_PINC 0x06
#define dht_2_PING 0x12
#define dht_3_PINL 0x109

#define DDR(DDR_data) _SFR_IO8(DDR_data)
#define PORT(PORT_data) _SFR_IO8(PORT_data)
#define PIN(PIN_data) _SFR_IO8(PIN_data)





//timeout retries
#define DHT_TIMEOUT 200

//functions

int8_t dht_getdata_dht_11(int8_t *temperature, int8_t *humidity,uint16_t DDR_data,uint16_t PORT_data,uint16_t PIN_data ,uint8_t channel);
//int8_t dht_getdata_dht_22(float *temperature, float *humidity ,uint8_t channel);

#endif
