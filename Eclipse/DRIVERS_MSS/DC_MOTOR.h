/*
 * DC_MOTOR.h
 *
 *  Created on: Feb 20, 2024
 *      Author: Admin
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "STANDS.h"
#include "GPIO2.h"
#include "MACROS.h"
#include "PWM_TIM0.h"
#include <util/delay.h>

#define DC_M_PORT PB
#define DC_M_PIN1 PIN0
#define DC_M_PIN2 PIN1

//DC MOTOR STATE [ OFF=0 , ON_CLOCKWISE =1 , ON_ANTI-CLOCKWISE =2 ]
typedef enum
{
	m_off,m_on_cw,m_on_acw
}MOTOR_STATE;
void DC_MOTOR_INIT();
void DC_MOTOR(MOTOR_STATE state,uint8 speed);

#endif /* DC_MOTOR_H_ */
