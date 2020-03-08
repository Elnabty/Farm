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


/*Relay Module 2*/
/*Solenoids*/
#define SOL_1 2u   //First solenoid
#define DDR_SOL_1_CONFIG DDRG|=(1<<SOL_1);
#define SOL_1_ON  PORTG&=~(1<<SOL_1);
#define SOL_1_OFF PORTG|=(1<<SOL_1);

#define SOL_2 0u   //Second solenoid 
#define DDR_SOL_2_CONFIG DDRG|=(1<<SOL_2);
#define SOL_2_ON  PORTG&=~(1<<SOL_2);
#define SOL_2_OFF PORTG|=(1<<SOL_2);

#define SOL_3 6u   //Third solenoid
#define DDR_SOL_3_CONFIG DDRL|=(1<<SOL_3);
#define SOL_3_ON  PORTL&=~(1<<SOL_3);
#define SOL_3_OFF PORTL|=(1<<SOL_3);

#define SOL_4 4u   //Fourth solenoid
#define DDR_SOL_4_CONFIG DDRL|=(1<<SOL_4);
#define SOL_4_ON  PORTL&=~(1<<SOL_4);
#define SOL_4_OFF PORTL|=(1<<SOL_4);


/////////////////////////////////////////////////////////////////////////////////////////////


/*(FAN, LIGHT, LIGHT,VENTILATION ,FLYMED ) */

#define FLYMED 2U
#define DDR_FLYMED_CONFIG DDRL|=(1<<FLYMED);
#define FLYMED_ON  PORTL&=~(1<<FLYMED);
#define FLYMED_OFF PORTL|=(1<<FLYMED);


#define VENTILATION 0U
#define DDR_VENTILATION_CONFIG DDRL|=(1<<VENTILATION);
#define VENTILATION_ON  PORTL&=~(1<<VENTILATION);
#define VENTILATION_OFF PORTL|=(1<<VENTILATION);


#define LIGHT_1 2U
#define DDR_LIGHT_1_CONFIG DDRB|=(1<<LIGHT_1);
#define LIGHT_1_ON  PORTB&=~(1<<LIGHT_1);
#define LIGHT_1_OFF PORTB|=(1<<LIGHT_1);


#define LIGHT_2 0U
#define DDR_LIGHT_2_CONFIG DDRB|=(1<<LIGHT_2);
#define LIGHT_2_ON  PORTB&=~(1<<LIGHT_2);
#define LIGHT_2_OFF PORTB|=(1<<LIGHT_2);

/*Not yet implemented*/
#define FAN 3U
#define FAN_ON PORTB&=~(1<<FAN);
#define FAN_OFF PORTB|=(1<<FAN);







void relayModuleControl_Sol(struct Json * Jdata);

/*Fan Ventilation Light Med*/
void GPOIcontrol_FVLM(struct Json * Jdata);

void GPIO_init(void);
#ifdef RELAYMODULECONTROL
void relayModuleControl(unsigned char *data);
#endif




#endif /* GPIOCONTROL_H_ */