/*
 * OS.h
 *
 * Created: 9/19/2019 6:43:33 PM
 *  Author: aelnabty
 */ 


#ifndef OS_H_
#define OS_H_
#include "config.h"
void task_5sec  (void);
void task_PERIODIC  (void);
void task_10sec (void);

extern volatile unsigned char gUartRFlag;
extern volatile unsigned char gUartData;
uint8_t manualflag = 0;


#endif /* OS_H_ */