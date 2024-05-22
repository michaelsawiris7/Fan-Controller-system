/*
 * TEMP_SENSOR_LM35.h
 *
 *  Created on: Feb 20, 2024
 *      Author: Admin
 */

#ifndef TEMP_SENSOR_LM35_H_
#define TEMP_SENSOR_LM35_H_

#include "GPIO2.h"
#include "STANDs.h"
#include "ADC.h"
#include "MACROS.h"

#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

#define SENSOR_CHANNEL_ID         ADC2
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150
uint8 LM35_getTemperature(void);

#endif
