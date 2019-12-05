/*
 * packetsConfig.h
 *
 * Created: 8/29/2019 12:16:02 PM
 *  Author: aelnabty
 */ 


#ifndef PACKETSCONFIG_H_
#define PACKETSCONFIG_H_

#define FAN_PACKET 0x01U
#define SELONOID_PACKET 0x02U
#define MEDICINE_PACKET 0x03U
#define LIGHT_PACKET 0x04U
#define VENTILATION_PACKET 0x05U
#define FLYMED_PACKET 0x06U
#define DATA_MASK 0x1Fu
#define ID_MASK 0xE0u

typedef struct uartPacket
{
	unsigned char id;
	unsigned char data;
	}uartPacket;

void packetSplitter(unsigned char packet, uartPacket *packetDataId );

#endif /* PACKETSCONFIG_H_ */