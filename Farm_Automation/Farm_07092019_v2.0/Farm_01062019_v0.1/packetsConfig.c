/*
 * packetsConfig.c
 *
 * Created: 8/29/2019 1:29:40 PM
 *  Author: aelnabty
 */ 
#include "packetsConfig.h"

void packetSplitter(unsigned char packet, uartPacket *packetDataId )
{
	
	packetDataId->id = ((packet & ID_MASK) >> 5u);
	packetDataId->data = (packet & DATA_MASK);	
	
}