/*
 * UART.h
 *
 * Created: 8/23/2018 7:42:43 PM
 *  Author: hmd-e
 */ 
#ifndef UART_H_
#define UART_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define BAUDRATE (9600UL)
// we will be using Async double speed mode because the error on that baud rate will be 0.2%
#define UBRRset (((F_CPU)/(16*BAUDRATE))-1)
void UART_int();
void UART_tx(unsigned char x);
void UART_string_tx(unsigned char *x);
#endif