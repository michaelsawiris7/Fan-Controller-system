/*
 * SEVEN_SEG.c
 *
 *  Created on: Feb 15, 2024
 *      Author: Admin
 */
#include "SEVEN_SEG.h"


void SEVEN_SEG(uint8 num)
{

DDR(PA,total,OUTPUT);
DDR(SEG1,OUTPUT);
PORT(SEG1,ON);

	switch(num)
	{
	case 0:
		PORT(PA,P1,ON);
		PORT(PA,P2,ON);
		PORT(PA,P3,ON);
		PORT(PA,P4,ON);
		PORT(PA,P5,ON);
		PORT(PA,P6,ON);
		PORT(PA,P7,OFF);
		break;
	case 1:
		PORT(PA,P1,OFF);
		PORT(PA,P2,ON);
		PORT(PA,P3,ON);
		PORT(PA,P4,OFF);
		PORT(PA,P5,OFF);
		PORT(PA,P6,OFF);
		PORT(PA,P7,OFF);
		break;
	case 2:
		PORT(PA,P1,ON);
		PORT(PA,P2,ON);
		PORT(PA,P3,OFF);
		PORT(PA,P4,ON);
		PORT(PA,P5,ON);
		PORT(PA,P6,OFF);
		PORT(PA,P7,ON);
		break;
	case 3:
		PORTA |= (1<<1);
		PORTA |= (1<<2);
		PORTA |= (1<<3);
		PORTA |= (1<<4);
		PORTA &= ~(1<<5);
		PORTA &= ~(1<<6);
		PORTA |= (1<<7);
		break;
	case 4:
		PORTA &= ~(1<<1);
		PORTA |= (1<<2);
		PORTA |= (1<<3);
		PORTA &= ~(1<<4);
		PORTA &= ~(1<<5);
		PORTA |= (1<<6);
		PORTA |= (1<<7);
		break;
	case 5:
		PORTA |= (1<<1);
		PORTA &= ~(1<<2);
		PORTA |= (1<<3);
		PORTA |= (1<<4);
		PORTA &= ~(1<<5);
		PORTA |= (1<<6);
		PORTA |= (1<<7);
		break;
	case 6:
		PORTA |= (1<<1);
		PORTA &= ~(1<<2);
		PORTA |= (1<<3);
		PORTA |= (1<<4);
		PORTA |= (1<<5);
		PORTA |= (1<<6);
		PORTA |= (1<<7);
		break;
	case 7:
		PORTA |= (1<<1);
		PORTA |= (1<<2);
		PORTA |= (1<<3);
		PORTA &= ~(1<<4);
		PORTA &= ~(1<<5);
		PORTA &= ~(1<<6);
		PORTA &= ~(1<<7);
		break;
	case 8:
		PORTA |= (1<<1);
		PORTA |= (1<<2);
		PORTA |= (1<<3);
		PORTA |= (1<<4);
		PORTA |= (1<<5);
		PORTA |= (1<<6);
		PORTA |= (1<<7);
		break;
	case 9:
		PORTA |= (1<<1);
		PORTA |= (1<<2);
		PORTA |= (1<<3);
		PORTA &= ~(1<<4);
		PORTA &= ~(1<<5);
		PORTA |= (1<<6);
		PORTA |= (1<<7);
		break;
	}
}

