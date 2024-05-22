/*
 * TEST.c
 *
 *  Created on: Feb 11, 2024
 *      Author: Admin
 */

#include "GPIO2.h"
#include "LCD2.h"
#include "DC_MOTOR.h"
#include "TEMP_SENSOR_LM35.h"
#include "ADC.h"

int main()
{
	ADC_TYPE adc_type ={INTERNAL,PS_8,POOL};
	uint8 Tem=0;
	LCD_INIT();
	DC_MOTOR_INIT();
	ADC_INIT(&adc_type);
	LCD_STR_R_C(0,0,"FAN IS OFF");
	LCD_STR_R_C(1,0,"TEMP = ");
	LCD_STR_R_C(1,13,"C");

	while(1)
	{
				Tem=LM35_getTemperature();
				LCD_moveCursor(1,9);
				LCD_INT(Tem);
				if(Tem<0)
				{
					DC_MOTOR(m_off,0);
					LCD_STR_R_C(0,0,"FAN IS OFF");
					LCD_STR_R_C(1,0,"TEMP. UNDER ZERO C");

				}
				else
				{
					if(Tem<30)
					{
						DC_MOTOR(m_off,0);
						LCD_STR_R_C(0,0,"FAN IS OFF      ");
					}
					else if (Tem>=30 && Tem<60)
					{
						DC_MOTOR(m_on_cw,25);
						LCD_STR_R_C(0,0,"FAN IS ON, S1  ");

					}
					else if (Tem>=60 && Tem<90)
					{
						DC_MOTOR(m_on_cw,50);
						LCD_STR_R_C(0,0,"FAN IS ON, S2  ");

					}
					else if (Tem>=90 && Tem<120)
					{
						DC_MOTOR(m_on_cw,75);
						LCD_STR_R_C(0,0,"FAN IS ON, S3  ");

					}
					else
					{
						DC_MOTOR(m_on_cw,100);
						LCD_STR_R_C(0,0,"FAN IS ON, S4  ");

					}
					LCD_moveCursor(1,9);
					LCD_INT(Tem);
					LCD_CHAR(' ');
				}

	}
}
