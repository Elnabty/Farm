/*
 * espATCommand.c
 *
 * Created: 9/27/2019 1:02:07 AM
 *  Author: aelnabty
 */ 
#include "espATCommand.h"
//GET https://api.thingspeak.com/update?api_key=<5PXU25L32MJLPSJ8>&<field1=>0
void ESP_write(uint8_t* data, uint8_t* feild,uint8_t* api_key)
{
	
	uint8_t command[200];
	uint8_t command_length[30];
	uint8_t buffer[5];
	strcpy(command,"GET https://api.thingspeak.com/update?api_key=");
	strcat(command,api_key);
	strcat(command,"&");
	strcat(command,feild);
	strcat(command,"=");
	strcat(command,data);
	strcat(command,"\r\n");
	itoa(strlen(command),buffer,10);
	strcpy(command_length,MESSAGE_LENGTH);
	strcat(command_length,buffer);
	strcat(command_length,"\r\n");
	
	
	UART_string_tx(TCP_THINGSPEAK);
	_delay_ms(1000);
	UART_string_tx(command_length);
	_delay_ms(1000);
	UART_string_tx(command);
	_delay_ms(1000);
	
	
	
}