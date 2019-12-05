/*
 * UART.h
 *
 * Created: 8/23/2018 7:42:43 PM
 *  Author: hmd-e
 */ 
#ifndef UART_H_
#define UART_H_


#include "config.h"

#define FALSE 0U
#define TRUE 1U


#define MAXDATALENGTH 2U
#define BAUDRATE (250000UL)

// we will be using Async double speed mode because the error on that baud rate will be 0.2%
//#define UBRRset (((F_CPU)/(16*BAUDRATE))-1)
#define UBRRset (3u)// for 250K baudrate
void UART_int();
void UART_tx(unsigned char x);
void UART_string_tx(unsigned char *x);
void recvWithStartEndMarkers(uint8_t Data);

#endif