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

	Json Jdata;
	cli();
    dht_getdata_dht_11(&temperature,&humidity,1);
	Jdata.field1=temperature;
	Jdata.field2=humidity;
	
    waterLevel=readDistance();
	Jdata.field3=waterLevel;
	sei();
	
	ESP_write_Fields(&Jdata,SENORS_WRITE_APIKEY,1,3);

    
}
void task_4Sec(void)
{
   
    uint8_t i = 0;
	Json Jdata;

			ESP_Read(&Jdata,SELONOID_CHANNEL_ID,SELONOID_READ_APIKEY,8);
			//change to "&Jdata" instead of "Jdata"
            relayModuleControl_Sol(&Jdata);
            ModuleControl_Med(&Jdata);
			
		//	ESP_Read(&Jdata,FAN_VENTILATION_CHANNEL_ID,FAN_VENTILATION_READ_APIKEY,8);
            sei();

        

}
void task_10sec (void)
{

    cli();

    if (  /*dht_getdata_dht_22(&ftemperature,&fhumidity,0)!=-1  &&*/ dht_getdata_dht_11(&temperature,&humidity,1) == 0 )
        {
            int8_t temp_avr;
            int8_t humd_avr;
            temp_avr = ( (ftemperature+temperature)/2 );
            humd_avr = ((fhumidity+humidity)/2);

            if(temp_avr > 30 || humd_avr > 67)
                {
                    VENTILATION_ON;
                    FAN_ON;
                }

            else if (manualflag == 0)
                {
                    VENTILATION_OFF;
                    FAN_OFF;
                }

        }
    else
        {
            //UART_string_tx("FATAL ERROR!");
            FAN_ON;
            VENTILATION_ON;
        }
    sei();


}