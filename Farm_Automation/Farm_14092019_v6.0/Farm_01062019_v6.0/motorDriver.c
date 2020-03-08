/*
 * motorDriver.c
 *
 * Created: 3/7/2020 1:40:28 PM
 *  Author: hmd-e
 */ 
#include "motorDriver.h"

extern volatile uint16_t number_of_rotation;
volatile uint8_t Medicine;
void motorDriver_Med(struct Json * Jdata)
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


void motorDriver_Config(void)
{
	DDR_MED_1_DIR_CONFIG;
	DDR_MED_1_STEP_CONFIG;
	DDR_MED_2_DIR_CONFIG;
	DDR_MED_2_STEP_CONFIG;
	DDR_MED_3_DIR_CONFIG;
	DDR_MED_3_STEP_CONFIG;
	DDR_MED_4_DIR_CONFIG;
	DDR_MED_4_STEP_CONFIG;
	
	PORT_MED_1_DIR_CONFIG;
	PORT_MED_1_STEP_CONFIG;
	PORT_MED_2_DIR_CONFIG;
	PORT_MED_2_STEP_CONFIG;
	PORT_MED_3_DIR_CONFIG;
	PORT_MED_3_STEP_CONFIG;
	PORT_MED_4_DIR_CONFIG;
	PORT_MED_4_STEP_CONFIG;
	
	DDR_A4899_CINFIG;
	PORT_A4899_CINFIG;
	A4899_DIS;
}