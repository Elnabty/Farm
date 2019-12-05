/*----------------------------------------------------------------------------
 Copyright:      Radig Ulrich  mailto: mail@ulrichradig.de
 Author:         Radig Ulrich
 Remarks:        
 known Problems: none
 Version:        24.10.2007
 Description:    Webserver uvm.

 Dieses Programm ist freie Software. Sie können es unter den Bedingungen der 
 GNU General Public License, wie von der Free Software Foundation veröffentlicht, 
 weitergeben und/oder modifizieren, entweder gemäß Version 2 der Lizenz oder 
 (nach Ihrer Option) jeder späteren Version. 

 Die Veröffentlichung dieses Programms erfolgt in der Hoffnung, 
 daß es Ihnen von Nutzen sein wird, aber OHNE IRGENDEINE GARANTIE, 
 sogar ohne die implizite Garantie der MARKTREIFE oder der VERWENDBARKEIT 
 FÜR EINEN BESTIMMTEN ZWECK. Details finden Sie in der GNU General Public License. 

 Sie sollten eine Kopie der GNU General Public License zusammen mit diesem 
 Programm erhalten haben. 
 Falls nicht, schreiben Sie an die Free Software Foundation, 
 Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA. 
----------------------------------------------------------------------------*/

#include <avr/io.h>
#include <avr/eeprom.h>
#include "config.h"
#include "usart.h"
#include "networkcard/enc28j60.h"
//#include "networkcard/rtl8019.h"
#include "stack.h"
#include "timer.h"
#include "wol.h"
#include "httpd.h"
#include "cmd.h"
#include "telnetd.h"
//#include "ntp.h"
#include "base64.h"
#include "http_get.h"
//#include "lcd.h"
#include "udp_lcd.h"
#include "analog.h"
//#include "camera/cam.h"
//#include "camera/servo.h"
//#include "sendmail.h"
//#include "artnet.h"
#include "dhcpc.h"
#include "dnsc.h"
#include "dht.h"

extern unsigned int var_array[MAX_VAR_ARRAY];
extern unsigned char gFanflag;
//----------------------------------------------------------------------------
//Hier startet das Hauptprogramm
int main(void)
{  
	unsigned long time_old;
	unsigned char second_5 = 0; 
	
	//Konfiguration der Ausgänge bzw. Eingänge
	//definition erfolgt in der config.h
//	DDRA = OUTA;
	DDRC = OUTC;
	DDRD = OUTD;
	PORTC = 0u;
    unsigned long a;
		float ftemperature = 0;
		float fhumidity = 0;
		int8_t temperature = 0;
		int8_t humidity = 0;
		
	
    usart_init(BAUDRATE); // setup the UART
	
	
	usart_write("\n\rSystem Ready\n\r");
    usart_write("Compiliert am "__DATE__" um "__TIME__"\r\n");
    usart_write("Compiliert mit GCC Version "__VERSION__"\r\n");

	for(a=0;a<1000000;a++){asm("nop");};

	//Applikationen starten
	stack_init();
	httpd_init();
	telnetd_init();
	

	

	//Ethernetcard Interrupt enable
	ETH_INT_ENABLE;
	
	//Globale Interrupts einschalten
	sei(); 
		
    usart_write("\r\nIP   %1i.%1i.%1i.%1i\r\n", myip[0]     , myip[1]     , myip[2]     , myip[3]);
    usart_write("MASK %1i.%1i.%1i.%1i\r\n", netmask[0]  , netmask[1]  , netmask[2]  , netmask[3]);
    usart_write("GW   %1i.%1i.%1i.%1i\r\n", router_ip[0], router_ip[1], router_ip[2], router_ip[3]);


		
	while(1)
	{
		#if USE_ADC
		ANALOG_ON;
		#endif
	    eth_get_data();
		
		#if USE_ARTNET
		artnet_main();
		#endif
		
        //Terminalcommandos auswerten
		if (usart_status.usart_ready){
            usart_write("\r\n");
			if(extract_cmd(&usart_rx_buffer[0]))
			{
				usart_write("Ready\r\n\r\n");
			}
			else
			{
				usart_write("ERROR\r\n\r\n");
			}
			usart_status.usart_ready =0;
		}
		

  
		//USART Daten für Telnetanwendung?
		telnetd_send_data();

		
		
			if(time != time_old)
			{
				time_old = time;
				enc28j60_status_test();
				second_5++;
				        
			}
		if(second_5 == 5)
		{
			second_5 = 0;
			
			cli();
			if(ping.result)
			{
				usart_write("Get PONG: %i.%i.%i.%i\r\n",ping.ip1[0],ping.ip1[1],ping.ip1[2],ping.ip1[3]);
				ping.result = 0;
			}
		
			if (dht_getdata_dht_22(&ftemperature,&fhumidity,0) == -1  && dht_getdata_dht_11(&temperature,&humidity,1) == -1)//error = -1
			{
				var_array[0u] = 0; //temperature
				var_array[1u] = 0; //humidity
				
				var_array[2u] = 0;//temperature
				var_array[3u] = 0;//humidity
				
				FAN_ON
			}
			else
			{
				var_array[0u] =(unsigned int)ftemperature;
				var_array[1u] = (unsigned int)fhumidity;
				var_array[2u] = (unsigned int)temperature;
				var_array[3u] = (unsigned int)humidity;
				
				if( ((unsigned int)(((unsigned int)ftemperature + temperature)/2)) > 30 || ((unsigned int)(((unsigned int)fhumidity + humidity)/2)) > 70 || gFanflag == 1 )
				{
					FAN_ON;
				}			
				
				else
				{
					FAN_OFF;
				}	
				
			}
		
			sei();
		}
    }//while (1)
		
return(0);
}

