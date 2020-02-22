/*********************************************************************************/
/*  Ultrasonic range finder HC-SR04 lib for AVR									 */
/*  Autor: Kornuta Taras														 */
/*  Date: 21.04.2016															 */
/*	URL: http://digiua.com														 */
/*********************************************************************************/


#ifndef USOUND_H
#define USOUND_H
#include "config.h"

/*Test*/
// Ports initialization
#define US_DDR		DDRC
#define US_PORT		PORTC
#define US_PIN		PINC
#define US_TRIGER	PINA5
#define US_ECHO		PINA7


 void usound_init(void);				//Paste in Main function

 uint32_t readDistance(void);			//Return the distance in centimeters
										//Recommended use this function with 20Hz frequency 



#endif //USOUND_H
