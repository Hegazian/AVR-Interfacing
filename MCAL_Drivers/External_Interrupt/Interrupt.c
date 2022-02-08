/*
 * Interrupt.c
 *
 *  Created on: Dec 27, 2021
 *      Author: aaa
 */

#include"LIB/Types.h"
#include"LIB/set_math.h"
#include"Interrupt.h"
#include"Interrupt_reg.h"

void Interrupt_Init(u8 intrrupt_id,u8 interrupt_mode)
{
	if(intrrupt_id<=EXT_INT2 && interrupt_mode<= TOGGLING)
	{
		Enable_General_Interrupt();
		Interrupt_Enabled(intrrupt_id);
		if(intrrupt_id == EXT_INT0)
		{
			switch(interrupt_mode)
			{
			case RISING: SET_BIT(MCUCR_REG,ISC00);SET_BIT(MCUCR_REG,ISC01);break; //set ISC00 by 1,set ISC01 by 1
			case FALLING: CLR_BIT(MCUCR_REG,ISC00);SET_BIT(MCUCR_REG,ISC01);break;//set ISC00 by 0,set ISC01 by 1
			case LOW_LEVEL:CLR_BIT(MCUCR_REG,ISC00);CLR_BIT(MCUCR_REG,ISC01);break;//set ISC00 by 0,set ISC01 by 0
			case TOGGLING:	SET_BIT(MCUCR_REG,ISC00);CLR_BIT(MCUCR_REG,ISC01);break;//set ISC00 by 1,set ISC01 by 0
			}
		}
		else if(intrrupt_id == EXT_INT1)
		{
			switch(interrupt_mode)
			{
			case RISING: SET_BIT(MCUCR_REG,ISC10);SET_BIT(MCUCR_REG,ISC11);break; //set ISC10 by 1,set ISC11 by 1
			case FALLING: CLR_BIT(MCUCR_REG,ISC10);SET_BIT(MCUCR_REG,ISC11);break;//set ISC10 by 0,set ISC11 by 1
			case LOW_LEVEL:CLR_BIT(MCUCR_REG,ISC10);CLR_BIT(MCUCR_REG,ISC11);break;//set ISC10 by 0,set ISC11 by 0
			case TOGGLING:	SET_BIT(MCUCR_REG,ISC10);CLR_BIT(MCUCR_REG,ISC11);break;//set ISC10 by 1,set ISC11 by 0
			}
		}
		else if(intrrupt_id == EXT_INT2)
		{
			switch(interrupt_mode)
			{
			case FALLING:CLR_BIT(MCUCSR_REG,ISC2);break;
			case RISING: SET_BIT(MCUCSR_REG,ISC2);break;
			}
		}
		else
		{
			//error msg
		}
	}
}

void Interrupt_Enabled(u8 intrrupt_id)
{
	if(intrrupt_id <= EXT_INT2)
	{
		switch(intrrupt_id)
		{
		case EXT_INT0: SET_BIT(GICR_REG,INT0_EN);break;
		case EXT_INT1: SET_BIT(GICR_REG,INT1_EN);break;
		case EXT_INT2: SET_BIT(GICR_REG,INT2_EN);break;
		}
	}
	else
	{
		//error massage
	}
}

void Interrupt_Disabled(u8 intrrupt_id)
{
	if(intrrupt_id <= EXT_INT2)
	{
		switch(intrrupt_id)
		{
		case EXT_INT0: CLR_BIT(GICR_REG,INT0_EN);break;
		case EXT_INT1: CLR_BIT(GICR_REG,INT1_EN);break;
		case EXT_INT2: CLR_BIT(GICR_REG,INT2_EN);break;
		}
	}
	else
	{
		//error massage
	}
}


void Enable_General_Interrupt(void)
{
	SET_BIT(SREG_REG,GIE);
}

void Disable_General_Interrupt(void)
{
	CLR_BIT(SREG_REG,GIE);
}
