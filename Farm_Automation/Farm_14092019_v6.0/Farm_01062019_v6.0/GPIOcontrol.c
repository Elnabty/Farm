/*
* GPIOcontrol.c
*
* Created: 8/29/2019 1:51:32 PM
*  Author: aelnabty
*/
#include "GPIOcontrol.h"

#ifdef RELAYMODULECONTROL
void relayModuleControl(unsigned char * data)
{
    uartPacket packet;


    packetSplitter_2Bytes(data, &packet);


    switch(packet.id)
        {
            case MED_1_TABLE:
                if (packet.data == (1u))
                    {
                        MED_1_ON;
                        UART_string_tx((unsigned char *)"[ERROR Receiving:MED1_On_Ok]");
                    }
                else if(packet.data == 7u)
                    {
                        MED_1_OFF;
                        UART_string_tx((unsigned char *)"[ERROR Receiving:MED1_Off_Ok]");
                    }

                break;

            case MED_2_TABLE:
                if (packet.data == (1u))
                    {
                        MED_2_ON;
                        UART_string_tx((unsigned char *)"[ERROR Receiving:MED2_On_Ok]");
                    }
                else if(packet.data == 7u)
                    {
                        MED_2_OFF;
                        UART_string_tx((unsigned char *)"[ERROR Receiving:MED2_Off_Ok]");
                    }

                break;

            case MED_3_TABLE:
                if (packet.data == (1u))
                    {
                        MED_3_ON;
                        UART_string_tx((unsigned char *)"[ERROR Receiving:MED3_On_Ok]");
                    }
                else if(packet.data == 7u)
                    {
                        MED_3_OFF;
                        UART_string_tx((unsigned char *)"[ERROR Receiving:MED3_Off_Ok]");
                    }

                break;


            case MED_4_TABLE:
                if (packet.data == (1u))
                    {
                        MED_4_ON;
                        UART_string_tx((unsigned char *)"[ERROR Receiving:MED4_On_Ok]");
                    }
                else if(packet.data == 7u)
                    {
                        MED_4_OFF;
                        UART_string_tx((unsigned char *)"[ERROR Receiving:MED4_Off_Ok]");
                    }
                break;

            case SOL_1_TABLE:
                if (packet.data == (1u))
                    {
                        SOL_1_ON;
                        UART_string_tx((unsigned char *)"[ERROR Receiving:SOL1_On_Ok]");
                    }
                else if(packet.data == 7u)
                    {
                        SOL_1_OFF;
                        UART_string_tx((unsigned char *)"[ERROR Receiving:SOL1_Off_Ok]");
                    }
                break;


            case SOL_2_TABLE:
                if (packet.data == (1u))
                    {
                        SOL_2_ON;
                        UART_string_tx((unsigned char *)"[ERROR Receiving:SOL2_On_Ok]");
                    }
                else if(packet.data == 7u)
                    {
                        SOL_2_OFF;
                        UART_string_tx((unsigned char *)"[ERROR Receiving:SOL2_Off_Ok]");
                    }
                break;

            case SOL_3_TABLE:
                if (packet.data == (1u))
                    {
                        SOL_3_ON;
                        UART_string_tx((unsigned char *)"[ERROR Receiving:SOL3_On_Ok]");
                    }
                else if(packet.data == 7u)
                    {
                        SOL_3_OFF;
                        UART_string_tx((unsigned char *)"[ERROR Receiving:SOL3_Off_Ok]");
                    }
                break;

            case SOL_4_TABLE:
                if (packet.data == (1u))
                    {
                        SOL_4_ON;
                        UART_string_tx((unsigned char *)"[ERROR Receiving:SOL4_On_Ok]");
                    }
                else if(packet.data == 7u)
                    {
                        SOL_4_OFF;
                        UART_string_tx((unsigned char *)"[ERROR Receiving:SOL4_Off_Ok]");
                    }
                break;


            case FLYMED_TABLE:
                if (packet.data == (1u))
                    {
                        FLYMED_ON;
                        UART_string_tx((unsigned char *)"[ERROR Receiving:FLYMED_On_Ok]");
                    }
                else if(packet.data == 7u)
                    {
                        FLYMED_OFF;
                        UART_string_tx((unsigned char *)"[ERROR Receiving:FLYMED_Off_Ok]");
                    }
                break;


            case VENTILATION_TABLE:
                if (packet.data == (1u))
                    {
                        VENTILATION_ON;
                        UART_string_tx((unsigned char *)"[ERROR Receiving:VENTILATION_On_Ok]");
                    }
                else if(packet.data == 7u)
                    {
                        VENTILATION_OFF;
                        UART_string_tx((unsigned char *)"[ERROR Receiving:VENTILATION_Off_Ok]");
                    }
                break;


            case FAN_TABLE:
                if (packet.data == (1u))
                    {
                        FAN_ON;
                        UART_string_tx((unsigned char *)"[ERROR Receiving:FAN_On_Ok]");
                    }
                else if(packet.data == 7u)
                    {
                        FAN_OFF;
                        UART_string_tx((unsigned char *)"[ERROR Receiving:FAN_Off_Ok]");
                    }
                break;

            case LIGHT_1_TABLE:
                if (packet.data == (1u))
                    {
                        LIGHT_1_ON;
                        UART_string_tx((unsigned char *)"[ERROR Receiving:LIGHT_1_On_Ok]");
                    }
                else if(packet.data == 7u)
                    {
                        LIGHT_1_OFF;
                        UART_string_tx((unsigned char *)"[ERROR Receiving:LIGHT_1_Off_Ok]");
                    }
                break;

            case LIGHT_2_TABLE:
                if (packet.data == (1u))
                    {
                        LIGHT_2_ON;
                        UART_string_tx((unsigned char *)"[ERROR Receiving:FAN_On_Ok]");
                    }
                else if(packet.data == 7u)
                    {
                        LIGHT_2_OFF;
                        UART_string_tx((unsigned char *)"[ERROR Receiving:FAN_Off_Ok]");
                    }
                break;

            case FAN_AUTO_MODE:
                if (packet.data == (1u))
                    {
                        //  LIGHT_2_ON;
                        UART_string_tx((unsigned char *)"[ERROR Receiving:FAN_AUTO_MODE_On_Ok]");
                    }
                else if(packet.data == 7u)
                    {
                        //  LIGHT_2_OFF;
                        UART_string_tx((unsigned char *)"[ERROR Receiving:FAN_AUTO_MODE_Off_Ok]");
                    }
                break;



            default:
                UART_string_tx((unsigned char *)"[ERROR Receiving:YES]");

        }

}
#endif
void relayModuleControl_Sol(Json * Jdata)
{
    if(Jdata->field1 == 0)
        {
            SOL_1_OFF;
        }
    else
        {
            SOL_1_ON
        }


    if(Jdata->field2 == 0)
        {
            SOL_2_OFF;
        }
    else
        {
            SOL_2_ON
        }
    if(Jdata->field3 == 0)
        {
            SOL_3_OFF;
        }
    else
        {
            SOL_3_ON
        }
    if(Jdata->field4 == 0)
        {
            SOL_4_OFF;
        }
    else
        {
            SOL_4_ON
        }


}

/*Fan Ventilation Light Med*/
void GPOIcontrol_FVLM(struct Json * Jdata)
{
	if(Jdata->field1 == 0)
	{
		FLYMED_OFF;
	}
	else
	{
		FLYMED_ON;
	}


	if(Jdata->field2 == 0)
	{
		VENTILATION_OFF;
	}
	else
	{
		VENTILATION_ON;
	}
	if(Jdata->field3 == 0)
	{
		LIGHT_1_OFF;
	}
	else
	{
		LIGHT_1_ON;
	}
	if(Jdata->field4 == 0)
	{
		LIGHT_2_OFF;
	}
	else
	{
		LIGHT_2_ON;
	}


}

void GPIO_init(void)
{
	 DDR_FLYMED_CONFIG;
	 DDR_LIGHT_1_CONFIG;
	 DDR_VENTILATION_CONFIG;
	 
	 DDR_SOL_1_CONFIG;
	 DDR_SOL_2_CONFIG;
	 DDR_SOL_3_CONFIG;
	 DDR_SOL_4_CONFIG;
	 
	 SOL_1_OFF;
	 SOL_2_OFF;
	 SOL_3_OFF;
	 SOL_4_OFF;
	 
	 FLYMED_OFF;
	 LIGHT_1_ON;
	 VENTILATION_OFF;
	 LIGHT_2_OFF;
	 
	 

}