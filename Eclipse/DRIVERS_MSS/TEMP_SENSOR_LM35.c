/*
 * TEMP_SENSOR_LM35.c
 *
 *  Created on: Feb 20, 2024
 *      Author: Admin
 */



#include "TEMP_SENSOR_LM35.h"

uint8 LM35_getTemperature(void)
{
	uint8 temp_value = 0;
	//ADC_INIT (&adc_type);
	ADC_READ(ADC2);
	/* Calculate the temperature from the ADC value*/
    temp_value = (uint8)(((uint32)ADC_RES*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));
	return temp_value;
}
