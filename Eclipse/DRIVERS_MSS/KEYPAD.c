/*
 * KEYPAD.c
 *
 *  Created on: Feb 13, 2024
 *      Author: Admin
 */
#include "KEYPAD.h"

uint8 KEYPAD()
{
	uint8 R,C;
	for (R=ROW_INIT_PIN;R<=7;R++)  	{DDR(PB,R,INPUT);}
	for (C=COL_INIT_PIN;C<=5;C++)  	{DDR(PD,C,INPUT);}

	while(1)
	{
		for(R=0;R<ROW_NUM;R++)
		{
			DDR (PB,R+ROW_INIT_PIN,OUTPUT);
			PORT(PB,R+ROW_INIT_PIN,OFF);

			for(C=0;C<COL_NUM;C++)
			{
			  if (PIN(PD,C+COL_INIT_PIN)==0)
			  {
				  return K_P_4X4((R*COL_NUM)+C+1);
				  while (!PIN(PD,C+COL_INIT_PIN)){}
			  }
			}
			DDR(PB,R+ROW_INIT_PIN,INPUT);
			_delay_ms(5);

		}
	}
}
uint8 K_P_4X4(uint8 num)
{
	uint8 keypad_button;
	switch(num)
	{
	case 1: keypad_button = 7;
			break;
	case 2: keypad_button = 8;
			break;
	case 3: keypad_button = 9;
			break;
	case 4: keypad_button = '%'; // ASCII Code of %
			break;
	case 5: keypad_button = 4;
			break;
	case 6: keypad_button = 5;
			break;
	case 7: keypad_button = 6;
			break;
	case 8: keypad_button = '*'; /* ASCII Code of '*' */
			break;
	case 9: keypad_button = 1;
			break;
	case 10: keypad_button = 2;
			break;
	case 11: keypad_button = 3;
			break;
	case 12: keypad_button = '-'; /* ASCII Code of '-' */
			break;
	case 13: keypad_button = 13;  /* ASCII of Enter */
			break;
	case 14: keypad_button = 0;
			break;
	case 15: keypad_button = '='; /* ASCII Code of '=' */
			break;
	case 16: keypad_button = '+'; /* ASCII Code of '+' */
			break;
	default: keypad_button = num;
			break;
    }
return keypad_button;
}


