/*********************************************************************************/
/*  Ultrasonic range finder HC-SR04 lib for AVR									 */
/*  Autor: Kornuta Taras														 */
/*  Date: 21.04.2016															 */
/*	URL: http://digiua.com														 */
/*********************************************************************************/


#ifndef USOUND_H
#define USOUND_H
#include "config.h"


// Ports initialization
#define US_DDR		DDRA
#define US_PORT		PORTA
#define US_PIN		PINA
#define US_TRIGER	PINA4
#define US_ECHO		PINA5


 void usound_init(void);				//Paste in Main function

 uint32_t readDistance(void);			//Return the distance in centimeters
										//Recommended use this function with 20Hz frequency 



#endif //USOUND_H
