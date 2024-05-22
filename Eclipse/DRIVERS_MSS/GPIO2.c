/*
 * GPIO2.c
 *
 *  Created on: Feb 14, 2024
 *      Author: Admin
 */
#include "GPIO2.h"

void DDR(ports po,pins pi,state st)
{
	switch(po)
	{
	case PA:
		if (pi==total)
		{
			switch (st)
			{
				case INPUT:  DDRA=0x00;  break;
				case OUTPUT: DDRA=0xFF;  break;
			}
		}
		else
		{
			switch (st)
			{
				case INPUT:   DDRA&=~(1<<pi); break;
				case OUTPUT:  DDRA|=(1<<pi);  break;
			}
		}
	break;

	case PB:
		if (pi==total)
		{
			switch (st)
			{
				case INPUT:  DDRB=0x00; break;
				case OUTPUT: DDRB=0xFF;  break;
			}
		}
		else
		{
			switch (st)
			{
				case INPUT: DDRB&=~(1<<pi); break;
				case OUTPUT:  DDRB|=(1<<pi);  break;
			}
		}
	break;

	case PC:
		if (pi==total)
		{
			switch (st)
			{
				case INPUT:  DDRC=0x00; break;
				case OUTPUT: DDRC=0xFF;  break;
			}
		}
		else
		{
			switch (st)
			{
				case INPUT: DDRC&=~(1<<pi); break;
				case OUTPUT:  DDRC|=(1<<pi);  break;
			}
		}
	break;

	case PD:
		if (pi==total)
		{
			switch (st)
			{
				case INPUT: DDRD=0x00; break;
				case OUTPUT: DDRD=0xFF;  break;
			}
		}
		else
		{
			switch (st)
			{
				case INPUT: DDRD&=~(1<<pi); break;
				case OUTPUT:  DDRD|=(1<<pi);  break;
			}
		}
	break;
	}

}
void PORT(ports po,pins pi,uint8 data)
{
	switch(po)
	{
	case PA:
		if (pi==total)
		{

			PORTA=data;
			break;
		}
		else
		{
			switch (data)
			{
				case OFF:
				PORTA&=~(1<<pi);
				break;
				case ON:
				PORTA|=(1<<pi);
				break;
			}
		}
	break;

	case PB:
		if (pi==total)
		{

		 PORTB=data;
		 break;

		}
		else
		{
			switch (data)
			{
				case OFF: PORTB&=~(1<<pi); break;
				case ON:  PORTB|=(1<<pi);  break;
			}
		}
	break;

	case PC:
		if (pi==total)
		{

		 PORTC=data;
		 break;

		}
		else
		{
			switch (data)
			{
				case OFF: PORTC&=~(1<<pi); break;
				case ON:  PORTC|=(1<<pi);  break;
			}
		}
	break;

	case PD:
		if (pi==total)
		{

		 PORTD=data;
		 break;

		}
		else
		{
			switch (data)
			{
				case OFF: PORTD&=~(1<<pi); break;
				case ON:  PORTD|=(1<<pi);  break;
			}
		}
	break;
	}
}
uint8 PIN(ports po,pins pi)
{
	uint8 RET;
	switch(po)
	{
	case PA:
		if(pi==total)
		{
		RET=PINA;
		}
		else
		{
		RET=GET_BIT(PINA,pi);
		}
		break;
	case PB:
		if(pi==total)
		{
		RET=PINB;
		}
		else
		{
		RET=GET_BIT(PINB,pi);  //PINB&(1<<pi);
		}
		break;
	case PC:
		if(pi==total)
		{
		RET=PINC;
		}
		else
		{
		RET=GET_BIT(PINC,pi);
		}
		break;
	case PD:
		if(pi==total)
		{
		RET=PIND;
		}
		else
		{
		RET=GET_BIT(PIND,pi);
		}
		break;
	}
	return RET;
}
