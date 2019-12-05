//******************* lcd.c ****************************
#include "compiler.h"
#include "LCD.h"

void port_init(void)
{
	DDRA = 0xFF;
	PORTA = 0x00;
	DDRB = 0x00;
	PORTB = 0x00;
	DDRC = 0x00;
	PORTC = 0x00;
	DDRD = 0xF0;
	//DDRD = 0xFF;
	PORTD = 0x00;
}


//call this routine to initialize all peripherals
void init_devices(void)
{
	cli(); //disable all interrupts
	port_init();
	LCD_init();
	MCUCR = 0x00;
	GICR = 0x00;
	TIMSK = 0x00; //timer interrupt sources
}


//*********************************************************
//*********************** LCD Functions ***************
//*********************************************************



// *********************************
// *** Initialize the LCD driver ***
// *********************************
void LCD_init(void)
{
  delay_ms(100); // wait for 100ms
  LCD_WriteCommand (0x38); // 8 data lines
  LCD_WriteCommand (0x06); // cursor setting
  LCD_WriteCommand (0x0f); // display ON
  LCD_WriteCommand (0x01); // clear LCD memory
  delay_ms (10); // 10ms delay after clearing LCD
}

// **********************************************
// *** Write a command instruction to the LCD ***
// **********************************************
void LCD_WriteCommand (unsigned char Command)
{
  SET_LCD_CMD; // Set LCD in command mode
  PORTA = Command; // Load data to port
  ENABLE_LCD; // Write data to LCD
  asm("nop");
  asm("nop");
  DISABLE_LCD; // Disable LCD
  delay_ms(1); // wait for 1ms
}



// *****************************************
// *** Write one byte of data to the LCD ***
// *****************************************
void LCD_WriteData (unsigned char Data)
{
  SET_LCD_DATA; // Set LCD in data mode
  PORTA = Data; // Load data to port
  ENABLE_LCD; // Write data to LCD
  asm("nop");
  asm("nop");
  DISABLE_LCD; // Disable LCD
  delay_ms(1); // wait for 1ms
}

// ************************************************************
// Display a string at the specified row and column, from FLASH
//*************************************************************
void LCD_DisplayString_F (char row, char column ,const unsigned char *string)
{
  while (*string)
    LCD_WriteData(*string++);
}
void LCD_DisplayString (char row, char column ,const unsigned char *string)
{
  unsigned char i=0;
  LCD_Cursor (row, column);
  for(i=0;i<20;i++)
  	 LCD_WriteData(string[i]);
  //set the cursor at the end..
  LCD_Cursor(4,20);
}


// ***************************************************
// *** Position the LCD cursor at "row", "column". ***
// ***************************************************
void LCD_Cursor (char row, char column)
{
  switch (row)
  {
	//1 - 0x00
	//2 - 0xC0
	//3 - 0x94
	//4 - 0xD4
    case 1: LCD_WriteCommand (0x00 + column - 1); break;
    case 2: LCD_WriteCommand (0xC0 + column - 1); break;
	case 3: LCD_WriteCommand (0x94 + column - 1); break;
	case 4: LCD_WriteCommand (0xD4 + column - 1); break;
    default: break;
  }
}

// ********************** END **************************


