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


void ESP_write_FieldsTHWL(THWdata data,uint8_t* api_key)
{


    uint8_t command[200];
    uint8_t command_length[30];
    uint8_t buffer[5];

    ESP_close_TCP();// CLOSE ANY TCP CONNECTION

    strcpy(command,"GET https://api.thingspeak.com/update?api_key=");
    strcat(command,api_key);
    strcat(command,"&");
    strcat(command,"field1");
    strcat(command,"=");
    strcat(command,data.Temp);

    strcat(command,"&");
    strcat(command,"field2");
    strcat(command,"=");
    strcat(command,data.Hum);

    strcat(command,"&");
    strcat(command,"field3");
    strcat(command,"=");
    strcat(command,data.WL);

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


//https://api.thingspeak.com/channels/872668/feeds/last.json?api_key=HFCKEVJ6RK7YOMS3
void ESP_Read(Json* Jdata, uint8_t* channelID,uint8_t* api_key,uint8_t numberOfFields)
{


	uint8_t command[200];
	uint8_t command_length[30];
	uint8_t buffer[5];
	uint8_t *data;

	ESP_close_TCP();// CLOSE ANY TCP CONNECTION

	strcpy(command,"GET https://api.thingspeak.com/channels/");
	strcat(command,channelID);
	strcat(command,"/feeds/last.json?api_key=");
	strcat(command,api_key);
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

	if(circularQueue_searchSubStringInQueue("ERROR") == TRUE || circularQueue_searchSubStringInQueue("FAIL") == TRUE)
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
		while(circularQueue_searchSubStringInQueue("CLOSED") == FALSE);
		_delay_ms(5);
		data=circularQueue_bufferPointer();
		jasonParser(data,numberOfFields,Jdata);
		circularQueue_clearBuffer();
	}

	circularQueue_clearBuffer();
	_delay_ms(1000);
}

uint8_t jasonParser(uint8_t* data, uint8_t numberOfFields, Json * Jdata)
{
	uint8_t ret=0;
	uint8_t i=0;
	uint8_t Field[10];
	uint8_t *splitedata;
	uint8_t splitRet;
	strcpy(Field,"field0");
	Field[5]='0'+i;

	if(strstr(data,"IPD") == 0)
	{

		ret = 0;

	}

	else
	{
		for(i=1;i<= numberOfFields; i++)
		{
			strcpy(Field,"field");
			Field[5]='0'+i;
			splitedata = strstr(data,Field);

			if(splitedata!=0 )
			{
				splitRet = readFieldValue(splitedata);
				
				switch(i)
				{
					case 1:Jdata->field1=splitRet;ret++;break;
					case 2:Jdata->field2=splitRet;ret++;break;
					case 3:Jdata->field3=splitRet;ret++;break;
					case 4:Jdata->field4=splitRet;ret++;break;
					case 5:Jdata->field5=splitRet;ret++;break;
					case 6:Jdata->field6=splitRet;ret++;break;
					case 7:Jdata->field7=splitRet;ret++;break;
					case 8:Jdata->field8=splitRet;ret++;break;

				}
			}
		}


	}



	return ret;


}

uint8_t readFieldValue(uint8_t* data)
{
	int i = 0;
	uint8_t count=0;
	uint8_t buffer[5]={'1','5','\0'};
	uint8_t ret;
	for(i=7;i<strlen(data);i++)
	{
		if(data[i]>='0' && data[i]<='9')
		{
			
			buffer[count] = data[i];
			count++;
			buffer[count]='\0';
		}

		else if (data[i]==',')
		{
			break;
		}
	}

	ret = atoi(buffer);

	return ret;

}