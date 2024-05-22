/*
 * PWM_TIM0.c
 *
 *  Created on: Feb 24, 2024
 *      Author: Admin
 */



#include "PWM_TIM0.h"
void PWM_Timer0_Start(uint8 duty_cycle)
{
	DDR(PB,P3,OUTPUT);
	TCNT0=0;
	OCR0=(uint8)(2.55*duty_cycle);
	TCCR0=(1<<WGM01)|(1<<WGM00)|(1<<COM01)|(1<<CS01);

}
