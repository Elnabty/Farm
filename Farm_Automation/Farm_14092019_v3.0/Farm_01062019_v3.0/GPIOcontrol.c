/*
 * GPIOcontrol.c
 *
 * Created: 8/29/2019 1:51:32 PM
 *  Author: aelnabty
 */ 
#include "GPIOcontrol.h"

void relayModuleControl(unsigned char data)
{
	uartPacket packet;
	
	
	packetSplitter(data, &packet);
	
	switch(packet.id)
	{
		case FAN_PACKET:
						FAN_POS(packet.data);
						break;
		case SELONOID_PACKET: 
						SOL_POS(packet.data);
						break;

		case MEDICINE_PACKET: 
						MED_POS(packet.data);
						break;

		case LIGHT_PACKET: 
						LIGHT_1_POS(packet.data);
						LIGHT_2_POS(packet.data);
						break;
						
		case VENTILATION_PACKET: 
						VENTILATION_POS(packet.data);
						break;
						
		case FLYMED_PACKET:
						FLYMED_POS(packet.data);
						break;
						
		default: UART_string_tx("wrong ID")	;																					
						
	}
	
}

