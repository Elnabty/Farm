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

extern volatile uint16_t number_of_rotation;
volatile uint8_t Medicine;
void ModuleControl_Med(struct Json * Jdata)
{
    static uint8_t Med_1_State=0;
    static uint8_t Med_2_State=0;
    int8_t data;

    if(Jdata->field7 != Med_1_State)
        {
            Med_1_State = Jdata->field7;
            data = (int8_t)(Jdata->field5);
            if(data < 0)
                {
                    MED_1_ACW;
                    number_of_rotation = (uint16_t)((DEGREE_360)*(uint8_t)abs(data));
                    Medicine=1;
                    A4899_EN;
                    TIMER0_INTER_ENABLE;
                }

            else
                {
                    MED_1_CW;
                    number_of_rotation = (uint16_t)((DEGREE_360)*(uint8_t)abs(data));
                    Medicine=1;
                    A4899_EN;
                    TIMER0_INTER_ENABLE;

                }


        }
    else
        {

        }


    if(Jdata->field8 != Med_2_State)
        {
            Med_2_State = Jdata->field8;
            data = (int8_t)(Jdata->field6);
            if(data < 0)
                {
                    MED_2_ACW;
                    number_of_rotation = (uint16_t)((DEGREE_360)*(uint8_t)abs(data));
                    Medicine=2;
                    A4899_EN;
                    TIMER0_INTER_ENABLE;
                }

            else
                {
                    MED_2_CW;
                    number_of_rotation = (uint16_t)((DEGREE_360)*(uint8_t)abs(data));
                    Medicine=2;
                    A4899_EN;
                    TIMER0_INTER_ENABLE;

                }


        }
    else
        {

        }


}

void GPIO_init(void)
{
	 DDRC_CONFIG;
	 PORTC_COMFIG;
	 
	 DDRL_CINFIG;
	 PORTL_CINFIG;
	 A4899_DIS;
	 
	 DDRB_CONFIG;
	 PORTB_COMFIG;
	 
	 

}