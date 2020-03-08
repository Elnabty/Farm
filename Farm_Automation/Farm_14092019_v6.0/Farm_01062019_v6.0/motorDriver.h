/*
 * motorDriver.h
 *
 * Created: 3/7/2020 1:40:53 PM
 *  Author: hmd-e
 */ 


#ifndef MOTORDRIVER_H_
#define MOTORDRIVER_H_


#include "config.h"
#include "packetsConfig.h"






/*Motor driver Enabler config*/
#define	 A4899 0u /*Test*/
#define	DDR_A4899_CINFIG DDRA|=(1<<A4899);
#define PORT_A4899_CINFIG PORTA|=(1<<A4899);
/*En(Low) Dis(High) Med_Module*/
#define  A4899_EN PORTA&=~(1<<A4899);
#define  A4899_DIS PORTA|=(1<<A4899);





/*Motor Medicine 1*/
#define MED_1_STEP 3u
#define DDR_MED_1_STEP_CONFIG DDRD|=(1<<MED_1_STEP);
#define PORT_MED_1_STEP_CONFIG DDRD&=~(1<<MED_1_STEP);
#define MED_1_TOGGLE PORTD^=(1<<MED_1_STEP);/*Toggle to give steps to the driver*/

#define MED_1_DIR 2u   //MED 1 Motor DIRECRTION
#define DDR_MED_1_DIR_CONFIG DDRD|=(1<<MED_1_DIR);
#define PORT_MED_1_DIR_CONFIG DDRD&=~(1<<MED_1_DIR);
#define MED_1_CW  PORTD&=~(1<<MED_1_DIR);
#define MED_1_ACW PORTD|=(1<<MED_1_DIR);



/*Motor Medicine 2*/
#define MED_2_STEP 5u
#define DDR_MED_2_STEP_CONFIG DDRE|=(1<<MED_2_STEP);
#define PORT_MED_2_STEP_CONFIG DDRE&=~(1<<MED_2_STEP);
#define MED_2_TOGGLE PORTE^=(1<<MED_2_STEP);/*Toggle to give steps to the driver*/

#define MED_2_DIR 4u   //MED 2 Motor DIRECRTION
#define DDR_MED_2_DIR_CONFIG DDRE|=(1<<MED_2_DIR);
#define PORT_MED_2_DIR_CONFIG DDRE&=~(1<<MED_2_DIR);
#define MED_2_CW  PORTE&=~(1<<MED_2_DIR);
#define MED_2_ACW PORTE|=(1<<MED_2_DIR);


/*Motor Medicine 3*/
#define MED_3_STEP 3u
#define DDR_MED_3_STEP_CONFIG DDRE|=(1<<MED_3_STEP);
#define PORT_MED_3_STEP_CONFIG DDRE&=~(1<<MED_3_STEP);
#define MED_3_TOGGLE PORTE^=(1<<MED_3_STEP);/*Toggle to give steps to the driver*/

#define MED_3_DIR 5u   //MED 3 Motor DIRECRTION
#define DDR_MED_3_DIR_CONFIG DDRG|=(1<<MED_3_DIR);
#define PORT_MED_3_DIR_CONFIG DDRG&=~(1<<MED_3_DIR);
#define MED_3_CW  PORTE&=~(1<<MED_3_DIR);
#define MED_3_ACW PORTE|=(1<<MED_3_DIR);


/*Motor Medicine 4*/
#define MED_4_STEP 4u
#define DDR_MED_4_STEP_CONFIG DDRH|=(1<<MED_4_STEP);
#define PORT_MED_4_STEP_CONFIG DDRH&=~(1<<MED_4_STEP);
#define MED_4_TOGGLE PORTE^=(1<<MED_4_STEP);/*Toggle to give steps to the driver*/

#define MED_4_DIR 3u   //MED 3 Motor DIRECRTION
#define DDR_MED_4_DIR_CONFIG DDRH|=(1<<MED_4_DIR);
#define PORT_MED_4_DIR_CONFIG DDRH&=~(1<<MED_4_DIR);
#define MED_4_CW  PORTE&=~(1<<MED_4_DIR);
#define MED_4_ACW PORTE|=(1<<MED_4_DIR);

void motorDriver_Med(struct Json * Jdata);
void motorDriver_Config(void);


#endif /* MOTORDRIVER_H_ */