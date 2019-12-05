//********************************************************
//*********** PROGRAM FOR LCD INTERFACING *************
//********************************************************
//Controller: ATmega32 (Crystal: 16 Mhz)
//Compiler: ImageCraft ICCAVR
//Author: CC Dharmani, Chennai
//********************************************************
// ************* LCD.h : Header file *************

void LCD_init(void);
void LCD_WriteCommand (unsigned char CMD);
void LCD_WriteData (unsigned char Data);
void LCD_DisplayString_F(char row, char column, const unsigned char *string);
void LCD_Cursor(char row, char column);

#define ENABLE_LCD PORTD |= 0x80
#define DISABLE_LCD PORTD &= ~0x80
#define SET_LCD_DATA PORTD |= 0x20
#define SET_LCD_CMD PORTD &= ~0x20
#define pushButton1_PRESSED !(PIND & 0x02)
#define pushButton1_OPEN (PIND & 0x02)


