/*
* OS.c
*
* Created: 9/19/2019 6:43:48 PM
*  Author: aelnabty
*/
#include "OS.h"
uint8_t manualflag = 0;

void task_5sec  (void)
{

	Json Jdata = {0};
	int8_t flag=0;
	wdt_reset();
	cli();
	flag=dht_getdata_dht_11(&temperature,&humidity,dht_2_DDRG,dht_2_PORTG,dht_2_PING,1);
	if(flag==0)
	{
		Jdata.field2=temperature;
		Jdata.field3=humidity;
	}
	
	
	waterLevel=readDistance();
	Jdata.field1=waterLevel;
	sei();
	wdt_reset();
	ESP_write_Fields(&Jdata,SENORS_WRITE_APIKEY,1,3);
	wdt_reset();
	
}
void task_4Sec(void)
{
	

	static Json Jdata_Med={1,0,1,0,1,0,1,0};
	static Json Jdata_Sol={1,1,1,1,1,1,1,1};
	static Json Jdata_FVLM={1,1,1,1,1,1,1,1};	/*Fan_Ventilation_Light_Med*/
	
	
	wdt_reset();
	
	
	/*Read data Solenoid valves data from thingspeak*/
	ESP_Read(&Jdata_Sol,SELONOID_CHANNEL_ID,SELONOID_READ_APIKEY,4);
	relayModuleControl_Sol(&Jdata_Sol);
	wdt_reset();
	/*Read data Injection data from thingspeak*/
	ESP_Read(&Jdata_Med,INJECTION_CHANNEL_ID,INJECTION_READ_APIKEY,8);
	motorDriver_Med(&Jdata_Med);
	wdt_reset();
	/*Read data FVLM data from thingspeak*/
	ESP_Read(&Jdata_FVLM,FAN_VENTILATION_CHANNEL_ID,FAN_VENTILATION_READ_APIKEY,4);
	GPOIcontrol_FVLM(&Jdata_FVLM);
	
	wdt_reset();
	sei();

	

}
void task_10sec (void)
{

	//cli();
	

	
	
	//sei();


}