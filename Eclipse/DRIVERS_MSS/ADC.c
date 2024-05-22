/*
 * ADC.c
 *
 *  Created on: Feb 16, 2024
 *      Author: Admin
 */

#include "avr/interrupt.h"
#include "ADC.h"
volatile uint16 ADC_RES ;
volatile uint8 ADC_ST   = 0;

ISR(ADC_vect)
{
	/* Read ADC Data after conversion complete */
	ADC_RES = ADC;
}

void ADC_INIT(const ADC_TYPE *ptr_type)
{
	ADC_ST=(uint8)(ptr_type->adc_st);
	ADMUX=0;
	ADMUX=( (ADMUX & 0x3f)|((ptr_type->adc_rv & 0x03)<<6) );
	ADC_EN;
	ADCSRA|= ((ADCSRA & 0xF8)| ((ptr_type->adc_ps)&0x07) );
	if(ptr_type->adc_st==POOL)
	{
		ADC_INT_DIS;                    //DISABLE INTERRUPT
	}
	else
	{
		ADC_INT_EN;                     //ENABLE INTERRUPT
	}

}
void ADC_READ(ADC_CHANNEL ch)
{
	ch&=0x07;
	ADMUX&=0xE0;
	ADMUX|=ch;
	ADC_START;
	if(ADC_ST ==POOL)
	{
	while ( BIT_IS_CLEAR(ADCSRA,ADIF) ){}
	SET_BIT(ADCSRA,ADIF);
	ADC_RES=ADC;
	}
	else
	{

	}

}
