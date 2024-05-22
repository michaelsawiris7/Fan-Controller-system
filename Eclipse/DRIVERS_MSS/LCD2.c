/*
 * LCD2.c
 *
 *  Created on: Feb 15, 2024
 *      Author: Admin
 */

#include "LCD2.h"
//===================================================================
// SEND FIRST 4 BITS
void SEND2(uint8 send)
{
	PORT(D4,GET_BIT(send,4) );
	PORT(D5,GET_BIT(send,5) );
	PORT(D6,GET_BIT(send,6) );
	PORT(D7,GET_BIT(send,7) );
}
//===================================================================
// SEND SECOND 4 BITS
void SEND1(uint8 send)

{
	PORT(D4,GET_BIT(send,0) );
	PORT(D5,GET_BIT(send,1) );
	PORT(D6,GET_BIT(send,2) );
	PORT(D7,GET_BIT(send,3) );
}
// LCD INITIALIZATION
void LCD_INIT(void)
{
	#if (LCD_TYPE==FOUR_BITS_MODE)
			DDR(RS,OUTPUT);            //RS PIN     ---> OUTPUT
			DDR(RW,OUTPUT);
			DDR(EN,OUTPUT);            //ENABLE PIN ---> OUTPUT
			_delay_ms(20);

			DDR(D4,OUTPUT);
			DDR(D5,OUTPUT);
			DDR(D6,OUTPUT);
			DDR(D7,OUTPUT);
			_delay_ms(20);

			LCD_COMMAND(0x33);
			LCD_COMMAND(0x32);
			LCD_COMMAND(LCD_TWO_LINES_FOUR_BITS_MODE);
			LCD_COMMAND(LCD_CURSOR_OFF);
			LCD_COMMAND(LCD_CLEAR_COMMAND);
	#elif (LCD_TYPE ==EIGHT_BITS_MODE)
			DDR(RS,OUTPUT);            //RS PIN     ---> OUTPUT
			DDR(RW,OUTPUT);
			DDR(EN,OUTPUT);            //ENABLE PIN ---> OUTPUT
			_delay_ms(20);
			DDR(PC,total,OUTPUT);
			_delay_ms(20);
			LCD_COMMAND(LCD_TWO_LINES_EIGHT_BITS_MODE);
			LCD_COMMAND(LCD_CURSOR_OFF);
			LCD_COMMAND(LCD_CLEAR_COMMAND);
	#endif
}
// SEND COMMAND
void LCD_COMMAND(uint8 command)
{
	#if (LCD_TYPE==FOUR_BITS_MODE)
			PORT(RS,OFF);
			PORT(RW,OFF);
			_delay_ms(1);
			PORT(EN,ON);
			_delay_ms(1);
			SEND2(command);
			_delay_ms(1);
			PORT(EN,OFF);
			_delay_ms(1);
			PORT(EN,ON);
			_delay_ms(1);
			SEND1(command);
			_delay_ms(1);
			PORT(EN,OFF);
			_delay_ms(1);
	#elif (LCD_TYPE==EIGHT_BITS_MODE)
			PORT(RS,OFF);
			PORT(RW,OFF);
			_delay_ms(1);
			PORT(EN,ON);
			_delay_ms(1);
			PORT(PC,total,command);
			_delay_ms(1);
			PORT(EN,OFF);
			_delay_ms(1);
	#endif
}
//===================================================================
// SEND CHARACHTER
void LCD_CHAR(uint8 charachter)
{
	#if (LCD_TYPE==FOUR_BITS_MODE)

		PORT(RS,ON);
		PORT(RW,OFF);
		_delay_ms(1);
		PORT(EN,ON);
		_delay_ms(1);
		SEND2(charachter);
		_delay_ms(1);
		PORT(EN,OFF);
		_delay_ms(1);
		PORT(EN,ON);
		_delay_ms(1);
		SEND1(charachter);
		_delay_ms(1);
		PORT(EN,OFF);
		_delay_ms(1);

	#elif (LCD_TYPE==EIGHT_BITS_MODE)

			PORT(RS,ON);
			PORT(RW,OFF);
			_delay_ms(1);
			PORT(EN,ON);
			_delay_ms(1);
			PORT(PC,total,charachter);
			_delay_ms(1);
			PORT(EN,OFF);
			_delay_ms(1);

	#endif
}
//===================================================================
// SEND STRING
void LCD_STR(char *ptr)
{
	while((*ptr) != '\0')
	{
		LCD_CHAR(*ptr);
		ptr++;
	}
}
//===================================================================
// CLEAR LCD
void LCD_CLEAR()
{
	LCD_COMMAND(0x01);
}

void LCD_INT(int data)
{
   char buff[16]; /* String to hold the ascii result */
   itoa(data,buff,10); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
   LCD_STR(buff); /* Display the string */
}

void LCD_moveCursor(uint8 row,uint8 col)
{
	uint8 lcd_memory_address;

	switch(row)
	{
		case 0:
			lcd_memory_address=col;
				break;
		case 1:
			lcd_memory_address=col+0x40;
				break;

	}
	/* Move the LCD cursor to this specific address */
	LCD_COMMAND(lcd_memory_address | LCD_SET_CURSOR_LOCATION);
}

void LCD_STR_R_C(uint8 row,uint8 col,char txt[])
{
	LCD_moveCursor(row,col); /* go to to the required LCD position */
	LCD_STR(txt); /* display the string */
}




