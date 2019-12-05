/*
 * GPIOcontrol.h
 *
 * Created: 8/29/2019 1:51:16 PM
 *  Author: aelnabty
 */ 


#ifndef GPIOCONTROL_H_
#define GPIOCONTROL_H_

#include "config.h"
#include "packetsConfig.h"






/*PORT C (SELONOID_PACKET 4PINS MSb) (MEDICINE_PACKET 4PINS LSb) */
	
#define DDRC_CONFIG	DDRC=0xFF;
#define PORTC_COMFIG PORTC=0u;

/*(MEDICINE_PACKET 4PINS LSb)*/
#define MED_1 0u   //First medicine
#define MED_1_ON  PORTC&=~(1<<MED_1);
#define MED_1_OFF PORTC|=(1<<MED_1);


#define MED_2 1u   //Second medicine
#define MED_2_ON  PORTC&=~(1<<MED_2);
#define MED_2_OFF PORTC|=(1<<MED_2);


#define MED_3 2u   //Third medicine
#define MED_3_ON  PORTC&=~(1<<MED_3);
#define MED_3_OFF PORTC|=(1<<MED_3);


#define MED_4 3u   //Fourth medicine
#define MED_4_ON  PORTC&=~(1<<MED_4);
#define MED_4_OFF PORTC|=(1<<MED_4);

#define MED_MASK ((~ ( (1<<MED_1) | (1<<MED_2) | (1<<MED_3) | (1<<MED_4) ) ) & PORTC)  
#define MED_POS(data) PORTC=(data | MED_MASK )

/*(SELONOID_PACKET 4PINS MSb)*/
#define SOL_1 4u   //First solenoid
#define SOL_1_ON  PORTC&=~(1<<SOL_1);
#define SOL_1_OFF PORTC|=(1<<SOL_1);


#define SOL_2 5u   //Second solenoid
#define SOL_2_ON  PORTC&=~(1<<SOL_2);
#define SOL_2_OFF PORTC|=(1<<SOL_2);

#define SOL_3 6u   //Third solenoid
#define SOL_3_ON  PORTC&=~(1<<SOL_3);
#define SOL_3_OFF PORTC|=(1<<SOL_3);

#define SOL_4 7u   //Fourth solenoid
#define SOL_4_ON  PORTC&=~(1<<SOL_4);
#define SOL_4_OFF PORTC|=(1<<SOL_4);

#define SOL_MASK ( (~( (1<<SOL_1) | (1<<SOL_2) | (1<<SOL_3) | (1<<SOL_4) ) ) & PORTC )
#define SOL_POS(data) PORTC=( (data << 4u) | SOL_MASK)
/////////////////////////////////////////////////////////////////////////////////////////////


/*PORT B (FAN, LIGHT, LIGHT,VENTILATION ,FLYMED ) */

#define DDRB_CONFIG	DDRB=0x1Fu;
#define PORTB_COMFIG PORTB=0u;

#define FLYMED 0U
#define FLYMED_ON  PORTB&=~(1<<FLYMED);
#define FLYMED_OFF PORTB|=(1<<FLYMED);

#define FLYMED_MASK ( (~( (1<<FLYMED) ) ) & PORTB )
#define FLYMED_POS(data) PORTB=( (data << FLYMED) | FLYMED_MASK)

#define VENTILATION 1U
#define VENTILATION_ON  PORTB&=~(1<<VENTILATION);
#define VENTILATION_OFF PORTB|=(1<<VENTILATION);

#define VENTILATION_MASK ( (~( (1<<VENTILATION) ) ) & PORTB )
#define VENTILATION_POS(data) PORTB=( (data << VENTILATION) | VENTILATION_MASK)

#define LIGHT_1 2U
#define LIGHT_1_ON  PORTB&=~(1<<LIGHT_1);
#define LIGHT_1_OFF PORTB|=(1<<LIGHT_1);

#define LIGHT_1_MASK ( (~( (1<<LIGHT_1) ) ) & PORTB )
#define LIGHT_1_POS(data) PORTB=( (data << LIGHT_1) | LIGHT_1_MASK)

#define LIGHT_2 3U
#define LIGHT_2_ON  PORTB&=~(1<<LIGHT_2);
#define LIGHT_2_OFF PORTB|=(1<<LIGHT_2);

#define LIGHT_2_MASK ( (~( (1<<LIGHT_2) ) ) & PORTB )
#define LIGHT_2_POS(data) PORTB=( (data << LIGHT_2) | LIGHT_2_MASK)

#define FAN 4U
#define FAN_ON PORTB&=~(1<<FAN);
#define FAN_OFF PORTB|=(1<<FAN);

#define FAN_MASK ( (~( (1<<FAN) ) ) & PORTB )
#define FAN_POS(data) PORTB=( (data << FAN) | FAN_MASK)

/*Table for each pin or data DID*/
#define MED_1_TABLE 1U
#define MED_2_TABLE 2U
#define MED_3_TABLE 3U
#define MED_4_TABLE 4U

#define SOL_1_TABLE 11U
#define SOL_2_TABLE	12U
#define SOL_3_TABLE	13U
#define SOL_4_TABLE 14U

#define FLYMED_TABLE 21U

#define VENTILATION_TABLE 31U

#define FAN_TABLE 41U

#define LIGHT_1_TABLE 51U
#define LIGHT_2_TABLE 52U

#define FAN_AUTO_MODE 100U	
/////////////////////////////////////////////////////////////////////////////////////



void relayModuleControl_Sol(struct Json * Jdata);


void relayModuleControl(unsigned char *data);



#endif /* GPIOCONTROL_H_ */