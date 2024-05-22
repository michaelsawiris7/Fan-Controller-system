/*
 * GPIO2.h
 *
 *  Created on: Feb 14, 2024
 *      Author: Admin
 */

#ifndef GPIO2_H_
#define GPIO2_H_

#include <avr/io.h>
#include "STANDS.h"
#include "MACROS.h"
#define ON (1u)
#define OFF (0u)

typedef enum
{
	PA,PB,PC,PD
}ports;
typedef enum
{
	P0,P1,P2,P3,P4,P5,P6,P7,total
}pins;
typedef enum
{
	INPUT=0,OUTPUT=1
}state;

void  DDR  (ports po,pins pi,state st);
void  PORT (ports po,pins pi,uint8 data);
uint8 PIN  (ports po,pins pi);

#endif /* GPIO2_H_ */
