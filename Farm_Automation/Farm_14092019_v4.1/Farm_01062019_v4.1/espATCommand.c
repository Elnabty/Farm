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

    ESP_close_TCP();// CLOSE ANY TCP CONNECTION

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

	circularQueue_clearBuffer();
    UART_string_tx(TCP_THINGSPEAK);
    while(circularQueue_isEmpty() == TRUE);
    while(circularQueue_searchSubStringInQueue("ERROR") == FALSE  && circularQueue_searchSubStringInQueue("OK") == FALSE);
    if(circularQueue_searchSubStringInQueue("ERROR") == TRUE)
        {
            circularQueue_clearBuffer();
			_delay_ms(1000);
            return;

        }

	_delay_ms(20);
    circularQueue_clearBuffer();
    UART_string_tx(command_length);
    while(circularQueue_isEmpty() == TRUE);
	while(circularQueue_searchSubStringInQueue("ERROR") == FALSE && circularQueue_searchSubStringInQueue("OK") == FALSE && circularQueue_searchSubStringInQueue("FAIL") == FALSE);
  
    if(circularQueue_searchSubStringInQueue("ERROR") == TRUE)
        {
            circularQueue_clearBuffer();
			_delay_ms(1000);
            return;

        }

	 _delay_ms(20);
	if (circularQueue_searchSubStringInQueue("OK") == TRUE)
	{
		while(circularQueue_searchSubStringInQueue(">") == FALSE);
			circularQueue_clearBuffer();
			_delay_ms(50);
			UART_string_tx(command);
	}

	circularQueue_clearBuffer();
   _delay_ms(1000);
}


void ESP_close_TCP()
{
    circularQueue_clearBuffer();
    UART_string_tx(CLOSE_TCP);
    while(circularQueue_isEmpty() == TRUE);
    _delay_ms(50);
    circularQueue_clearBuffer();

}