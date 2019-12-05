/*****************************************************************************
*  "A Very Simple Application" from the uIP 0.9 documentation
*****************************************************************************/

#include "app.h"

#define maxrotations 5
#define serverport 12345

unsigned char payload[20];
unsigned char len=0;
unsigned char i,j=0;
unsigned char c=1;
unsigned char sel=1;

void server_init(void)
{
	uip_listen(HTONS(serverport));
}


void main_loop(void)
{
	if(uip_connected() || uip_rexmit()){
		//we the user connects we sent a number letting it know 
		//what we'd like to fetch and display
		//this will itterate off of the key press later
		if(sel > maxrotations)
			sel = 1;

		sprintf(payload,"%d",sel);
		uip_send(payload, 1);
		sel++;
	}
	if(uip_newdata())
	{
		if(c >= 4)
			c=1;
		j=0;
		//read
		LCD_init();
		delay_ms(10);
		//clear out our buffer
		for(i=0;i<20;i++)
			payload[i]=0;

		len = uip_datalen();

		for(i=0;i<len;i++)
		{
			payload[j]=uip_appdata[i];
			if(j == 19)
			{
				LCD_DisplayString(c,1,payload);
				delay_ms(10);
				j=0;
				c++;
			}
			else
				j++;
		}

	}
}
