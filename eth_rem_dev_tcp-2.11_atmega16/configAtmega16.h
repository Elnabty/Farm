#ifndef _CONFIG_H
#define _CONFIG_H

//atmega16
//#include <stdint.h>
#define F_CPU 8000000UL  // 8 MHz
#define SPI_PORT    PORTB
#define SPI_DDR     DDRB

#define LED_PORT    PORTB
#define LED_DDR     DDRB

#define SWITCH1_PORT PORTC
#define SWITCH1_DDR  DDRC

#define INT0_INPUT_DDR DDRC
#define INT0_INPUT_DDC2 DDC2

#define SPI_CS      PB4
#define SPI_MOSI    PB5
#define SPI_SCK     PB7
#define SPI_MISO    PINB6

#define STATUS_LED  PB1
#define STATUS_LED_DD DDB1
#define SWITCH1     PC7     
#define SWITCH1_DD DDC7


#endif
