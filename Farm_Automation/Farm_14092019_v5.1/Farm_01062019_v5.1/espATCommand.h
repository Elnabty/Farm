/*
 * espATCommand.h
 *
 * Created: 9/27/2019 1:01:24 AM
 *  Author: aelnabty
 */ 


#ifndef ESPATCOMMAND_H_
#define ESPATCOMMAND_H_

#include "config.h"


typedef struct THWdata
{
	uint8_t* Temp;
	uint8_t* Hum;
	uint8_t* WL;
} THWdata;


typedef struct Json
{
	uint8_t IPD;
	uint8_t field1;
	uint8_t field2;
	uint8_t field3;
	uint8_t field4;
	uint8_t field5;//Med_1
	uint8_t field6;//Med_2
	uint8_t field7;//Med_1_Start
	uint8_t field8;//Med_2_Start
}Json;

#define TCP_THINGSPEAK "AT+CIPSTART=\"TCP\",\"184.106.153.149\",80\r\n"
#define MESSAGE_LENGTH "AT+CIPSEND="
#define	CLOSE_TCP "AT+CIPCLOSE\r\n"
//#define GET "GET " 
#define SENORS_WRITE_APIKEY "5PXU25L32MJLPSJ8"
#define SELONOID_WRITE_APIKEY "XMXY8PE7KOT0HNMM"
#define SELONOID_READ_APIKEY "HFCKEVJ6RK7YOMS3"
#define FAN_VENTILATION_READ_APIKEY "RON68QE7PZ7O1U9S"
#define FAN_VENTILATION_CHANNEL_ID "881306"
#define SELONOID_CHANNEL_ID "872668"
#define NUMBER_OF_SOLENOIDS 4U




void ESP_write(uint8_t* data, uint8_t* feild,uint8_t* api_key); /*wont be void*/
void ESP_write_FieldsTHWL(THWdata data,uint8_t* api_key);
void ESP_write_Fields(struct Json *data,uint8_t* api_key,uint8_t fieldStart,uint8_t fieldEnd);
void ESP_close_TCP();
void ESP_Read(Json* Jdata, uint8_t* channelID,uint8_t* api_key,uint8_t numberOfFields);
uint8_t readFieldValue(uint8_t* data);
uint8_t jasonParser(uint8_t* data, uint8_t numberOfFields,Json * Jdata);




#endif /* ESPATCOMMAND_H_ */