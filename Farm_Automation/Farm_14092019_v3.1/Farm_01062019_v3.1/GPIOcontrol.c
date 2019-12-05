/*
 * GPIOcontrol.c
 *
 * Created: 8/29/2019 1:51:32 PM
 *  Author: aelnabty
 */ 
#include "GPIOcontrol.h"

void relayModuleControl(unsigned char * data)
{
	uartPacket packet;
	
	
	packetSplitter_2Bytes(data, &packet);
	
	
	switch(packet.id)
	{
		case MED_1_TABLE+'0':
							if (packet.data == ('0'+1u))
							{
									MED_1_ON;
							}
							else
							{
								MED_1_OFF;
							}
							UART_string_tx("[ERROR Receiving:MED1 Ok]");
							break;

		case MED_2_TABLE+'0':
							if (packet.data == ('0'+1u))
							{
								MED_2_ON;
							}
							else
							{
								MED_2_OFF;
							}
							UART_string_tx("[ERROR Receiving:MED2 Ok]");
							break;
							
		case MED_3_TABLE+'0':
							if (packet.data == ('0'+1u))
							{
								MED_3_ON;
							}
							else
							{
								MED_3_OFF;
							}
							UART_string_tx("[ERROR Receiving:MED3 Ok]");
							break;
							
							
		case MED_4_TABLE+'0':
							if (packet.data == ('0'+1u))
							{
								MED_4_ON;
							}
							else
							{
								MED_4_OFF;
							}
							UART_string_tx("[ERROR Receiving:MED4 Ok]");
							break;														
						
		default: UART_string_tx("[ERROR Receiving:YES]");																					
						
	}
	
}

