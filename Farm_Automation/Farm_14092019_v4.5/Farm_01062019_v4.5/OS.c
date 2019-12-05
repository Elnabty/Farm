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
	THWdata data;
	uint8_t Tbuffer[4];
	uint8_t Hbuffer[4];
	uint8_t WLbuffer[4];
 
	cli();
    dht_getdata_dht_11(&temperature,&humidity,1);
    itoa(temperature,Tbuffer,10);
	data.Temp=Tbuffer;
    itoa(humidity, Hbuffer, 10);
	data.Hum=Hbuffer;

    waterLevel=readDistance();
    itoa(waterLevel, WLbuffer, 10);
	data.WL=WLbuffer;
	sei();
	
	ESP_write_FieldsTHWL(data,SENORS_WRITE_APIKEY);


    
}
void task_4Sec(void)
{
   
    uint8_t i = 0;
	Json Jdata;

			ESP_Read(&Jdata,SELONOID_CHANNEL_ID,SELONOID_READ_APIKEY,NUMBER_OF_SOLENOIDS);
			//change to "&Jdata" instead of "Jdata"
            relayModuleControl_Sol(&Jdata);
            
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