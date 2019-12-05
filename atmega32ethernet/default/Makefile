###############################################################################
# Makefile for the project atmega32ethernet
###############################################################################

## General Flags
PROJECT = atmega32ethernet
MCU = atmega32
TARGET = atmega32ethernet.elf
CC = avr-gcc

CPP = avr-g++

## Options common to compile, link and assembly rules
COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -Wall -gdwarf-2 -Os -std=gnu99 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -MD -MP -MT $(*F).o -MF dep/$(@F).d 

## Assembly specific flags
ASMFLAGS = $(COMMON)
ASMFLAGS += $(CFLAGS)
ASMFLAGS += -x assembler-with-cpp -Wa,-gdwarf2

## Linker flags
LDFLAGS = $(COMMON)
LDFLAGS +=  -Wl,-Map=atmega32ethernet.map


## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom -R .fuse -R .lock -R .signature

HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0 --no-change-warnings


## Objects that must be built in order to link
OBJECTS = atmega32ethernet.o app.o delay.o enc28j60.o nic.o uip.o uip_arch.o uip_arp.o lcd.o 

## Objects explicitly added by the user
LINKONLYOBJECTS = 

## Build
all: $(TARGET) atmega32ethernet.hex atmega32ethernet.eep atmega32ethernet.lss size

## Compile
atmega32ethernet.o: ../atmega32ethernet.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

app.o: ../app.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

delay.o: ../delay.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

enc28j60.o: ../enc28j60.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

nic.o: ../nic.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

uip.o: ../uip.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

uip_arch.o: ../uip_arch.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

uip_arp.o: ../uip_arp.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

lcd.o: ../lcd.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

##Link
$(TARGET): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) $(LINKONLYOBJECTS) $(LIBDIRS) $(LIBS) -o $(TARGET)

%.hex: $(TARGET)
	avr-objcopy -O ihex $(HEX_FLASH_FLAGS)  $< $@

%.eep: $(TARGET)
	-avr-objcopy $(HEX_EEPROM_FLAGS) -O ihex $< $@ || exit 0

%.lss: $(TARGET)
	avr-objdump -h -S $< > $@

size: ${TARGET}
	@echo
	@avr-size -C --mcu=${MCU} ${TARGET}

## Clean target
.PHONY: clean
clean:
	-rm -rf $(OBJECTS) atmega32ethernet.elf dep/* atmega32ethernet.hex atmega32ethernet.eep atmega32ethernet.lss atmega32ethernet.map


## Other dependencies
-include $(shell mkdir dep 2>/dev/null) $(wildcard dep/*)

