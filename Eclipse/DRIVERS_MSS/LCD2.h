/*
 * LCD2.h
 *
 *  Created on: Feb 15, 2024
 *      Author: Admin
 */

#ifndef LCD2_H_
#define LCD2_H_

#include "STANDS.h"
#include <util/delay.h>
#include "GPIO2.h"
#include "MACROS.h"
#include <stdlib.h>

#define FOUR_BITS_MODE 4
#define EIGHT_BITS_MODE 8

#define LCD_TYPE EIGHT_BITS_MODE

#define LCD_CLEAR_COMMAND                    0x01
#define LCD_GO_TO_HOME                       0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE        0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE         0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32
#define LCD_CURSOR_OFF                       0x0C
#define LCD_CURSOR_ON                        0x0E
#define LCD_SET_CURSOR_LOCATION              0x80


#define RS   PD,P0
#define RW   PD,P1
#define EN   PD,P2

#define	D4   PC,P4
#define	D5   PC,P5
#define	D6   PC,P6
#define	D7   PC,P7

/*typedef enum
{
	FOUR_BITS_MODE=4,EIGHT_BITS_MODE=8
}typ;*/

void SEND2(uint8 send);

void SEND1(uint8 send);

void LCD_INIT(void);

void LCD_COMMAND(uint8 command);


void LCD_CHAR(uint8 charachter);

void LCD_STR(char *ptr);

void LCD_CLEAR();
void LCD_INT(int data);
void LCD_moveCursor(uint8 row,uint8 col);
void LCD_STR_R_C(uint8 row,uint8 col,char txt[]);
#endif /* LCD_H_ */


