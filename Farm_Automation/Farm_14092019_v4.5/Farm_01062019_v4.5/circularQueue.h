/*
 * circularQueue.h
 *
 * Created: 9/23/2019 1:29:58 PM
 *  Author: aelnabty
 */ 


#ifndef CIRCULARQUEUE_H_
#define CIRCULARQUEUE_H_
#include "config.h"
//#include <stdlib.h>
//#include <inttypes.h>

#define MAX_BUFFER_LENGTH 200U


uint8_t circularQueue_isEmpty();
void circularQueue_enqueue(uint8_t data);
uint8_t circularQueue_dequeue();
void circularQueue_clearBuffer();
uint8_t circularQueue_searchSubStringInQueue(uint8_t* data);
uint8_t *circularQueue_bufferPointer();

#endif /* CIRCULARQUEUE_H_ */