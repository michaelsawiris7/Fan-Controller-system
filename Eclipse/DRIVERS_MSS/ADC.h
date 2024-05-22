/*
 * ADC.h
 *
 *  Created on: Feb 16, 2024
 *      Author: Admin
 */

#ifndef ADC_H_
#define ADC_H_

#include "GPIO2.h"
#include "STANDS.h"
#include "MACROS.h"

extern volatile uint16 ADC_RES;
extern volatile uint8  ADC_ST;

#define ADC_EN   ADCSRA=(1<<ADEN)             //ENABLE  ADC FEATURE
#define ADC_DIS  CLEAR_BIT(ADCSRA,ADEN)             //DISABLE ADC FEATURE

#define ADC_INT_EN   SET_BIT  (ADCSRA,ADIE)         //ENABLE  ADC INTERRUPT
#define ADC_INT_DIS  CLEAR_BIT(ADCSRA,ADIE)         //DISABLE ADC INTERUUPT

#define ADC_START  SET_BIT(ADCSRA,ADSC)             //ADC START CONVERSION
/*ADMUX REGISTER(8 BITS)  */

typedef enum
{
	AREF,AVCC,RESERVED,INTERNAL
}ADC_REF_VOLT;

typedef enum
{
	PS_2=1,PS_4,PS_8,PS_16,PS_32,PS_64,PS_128
}ADC_PRE_SCALER;

typedef enum
{
	POOL,INT
}ADC_STATE;
typedef enum
{
	ADC0,ADC1,ADC2,ADC3,ADC4,ADC5,ADC6,ADC7
}ADC_CHANNEL;
typedef struct
{
	ADC_REF_VOLT   adc_rv;
	ADC_PRE_SCALER adc_ps;
	ADC_STATE      adc_st;
}ADC_TYPE;

void ADC_INIT (const ADC_TYPE *ptr_type);
void ADC_READ (ADC_CHANNEL ch);



#endif /* ADC_H_ */
