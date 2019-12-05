/*
 * OS.c
 *
 * Created: 9/19/2019 6:43:48 PM
 *  Author: aelnabty
 */ 
#include "OS.h"

void task_5sec  (void)
{
					cli();
					/*dht_getdata_dht_22(&ftemperature,&fhumidity,0);
					dtostrf(ftemperature, 3, 3, buffer);
					UART_string_tx(sensor0);
					UART_string_tx(tempString);
					UART_string_tx(buffer);
					dtostrf(fhumidity, 3, 3, buffer);
					UART_string_tx(humString);
					UART_string_tx(buffer);
					UART_tx('\n');*/
					
					dht_getdata_dht_11(&temperature,&humidity,1);
					itoa(temperature,buffer,10);
					UART_tx('[');
					UART_string_tx(sensor1);
					UART_string_tx(tempString);
					UART_string_tx(buffer);
					UART_tx(']');
					UART_tx('\n');
					_delay_ms(10);
					itoa(humidity, buffer, 10);
					UART_tx('[');
					UART_string_tx(sensor1);
					UART_string_tx(humString);
					UART_string_tx(buffer);
					UART_tx(']');
					UART_tx('\n');
					
					waterLevel=readDistance();
					itoa(waterLevel, buffer, 10);
					UART_tx('[');
					UART_string_tx("water level: ");
					UART_string_tx(buffer);
					UART_tx(']');
					UART_tx('\n');
					
						
					sei();	
}
void task_PERIODIC  (void)
{
			if( gUartRFlag == 1 )
		{
				cli();//cretical section 
				//UART_tx(gUartData);
				//relayModuleControl( gUartData);
				
			switch (gUartData)
			{
				
			
			case '1':
				/*	dht_getdata_dht_22(&ftemperature,&fhumidity,0);
					dtostrf(ftemperature, 3, 3, buffer);
					UART_string_tx(sensor0);
					UART_string_tx(tempString);
					UART_string_tx(buffer);
					dtostrf(fhumidity, 3, 3, buffer);
					UART_string_tx(humString);
					UART_string_tx(buffer);
					UART_tx('\n');*/
					dht_getdata_dht_11(&temperature,&humidity,1);
					itoa(temperature,buffer,10);
					UART_string_tx(sensor1);
					UART_string_tx(tempString);
					UART_string_tx(buffer);
					itoa(humidity, buffer, 10);
					UART_string_tx(humString);
					UART_string_tx(buffer);
					UART_tx('\n');		
			
			break;
			
			case '2': FAN_ON;manualflag=1; break;
			case '3': FAN_OFF;manualflag=0;break;
			
			default:UART_tx(gUartData);//UART_string_tx("wrong request");
			}
			
	
			
			gUartRFlag=0;
			
			sei();
			
		}

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