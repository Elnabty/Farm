/*
 * espATCommand.h
 *
 * Created: 9/27/2019 1:01:24 AM
 *  Author: aelnabty
 */ 


#ifndef ESPATCOMMAND_H_
#define ESPATCOMMAND_H_

#include "config.h"

#define TCP_THINGSPEAK "AT+CIPSTART=\"TCP\",\"184.106.153.149\",80\r\n"
#define MESSAGE_LENGTH "AT+CIPSEND="
#define	CLOSE_TCP "AT+CIPCLOSE\r\n"
//#define GET "GET " 
#define SENORS_WRITE_APIKEY "5PXU25L32MJLPSJ8"
#define FIELD_TEMP "field1"
#define FIELD_HUMD "field2"
#define FIELD_WL "field3"
void ESP_write(uint8_t* data, uint8_t* feild,uint8_t* api_key); /*wont be void*/
void ESP_close_TCP();




#endif /* ESPATCOMMAND_H_ */