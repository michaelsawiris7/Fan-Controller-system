/*
 * DC_MOTOR.c
 *
 *  Created on: Feb 20, 2024
 *      Author: Admin
 */

#include "DC_MOTOR.h"


void DC_MOTOR_INIT()
{
	DDR(DC_M_PORT,DC_M_PIN1,OUTPUT);
	PORT(DC_M_PORT,DC_M_PIN1,OFF);

	DDR(DC_M_PORT,DC_M_PIN2,OUTPUT);
	PORT(DC_M_PORT,DC_M_PIN2,OFF);
}

void DC_MOTOR(MOTOR_STATE state,uint8 speed)
{
	switch(state)
	{
	case m_off:
		PORT(DC_M_PORT,DC_M_PIN1,OFF);
		PORT(DC_M_PORT,DC_M_PIN2,OFF);
		break;
	case m_on_cw:
		PORT(DC_M_PORT,DC_M_PIN1,ON);
		PORT(DC_M_PORT,DC_M_PIN2,OFF);
		PWM_Timer0_Start(speed);
		break;

	case m_on_acw:
		PORT(DC_M_PORT,DC_M_PIN1,OFF);
		PORT(DC_M_PORT,DC_M_PIN2,ON);
		PWM_Timer0_Start(speed);
		break;
	default:
		PORT(DC_M_PORT,DC_M_PIN1,OFF);
		PORT(DC_M_PORT,DC_M_PIN2,OFF);
		break;
	}
}
