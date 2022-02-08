/*
 * DIO.c
 *
 *  Created on: Dec 5, 2021
 *      Author: aaa
 */


#include"LIB/Types.h"
#include"LIB/set_math.h"
#include"DIO.h"
#include"DIO_Registers.h"

void SetPinValue(u8 PinId,u8 PortId,u8 PinValue)
{
	if(PinId <= PIN7 && PortId <= DIO_PORTD)
	{
		if(PinValue == HIGH)
		{
			switch(PortId)
			{
			case DIO_PORTA:	SET_BIT(PORTA_REG,PinId);break;
			case DIO_PORTB:	SET_BIT(PORTB_REG,PinId);break;
			case DIO_PORTC:	SET_BIT(PORTC_REG,PinId);break;
			case DIO_PORTD:	SET_BIT(PORTD_REG,PinId);break;
			}
		}
		else if(PinValue == LOW)
		{
			switch(PortId)
			{
			case DIO_PORTA:	CLR_BIT(PORTA_REG,PinId);break;
			case DIO_PORTB:	CLR_BIT(PORTB_REG,PinId);break;
			case DIO_PORTC:	CLR_BIT(PORTC_REG,PinId);break;
			case DIO_PORTD:	CLR_BIT(PORTD_REG,PinId);break;
			}
		}
		else
		{
			//report error massage
		}
	}

	else
	{
		//report error massage
	}
}

void SetPinMode(u8 PinId,u8 PortId,u8 PinMode)
{
	if(PinId <= PIN7 && PortId <= DIO_PORTD)
	{
		if(PinMode == OUTPUT)
		{
			switch(PortId)
			{
			case DIO_PORTA:	SET_BIT(DDRA_REG,PinId);break;
			case DIO_PORTB:	SET_BIT(DDRB_REG,PinId);break;
			case DIO_PORTC:	SET_BIT(DDRC_REG,PinId);break;
			case DIO_PORTD:	SET_BIT(DDRD_REG,PinId);break;
			}
		}
		else if(PinMode == INPUT)
		{
			switch(PortId)
			{
			case DIO_PORTA:	CLR_BIT(DDRA_REG,PinId);break;
			case DIO_PORTB:	CLR_BIT(DDRB_REG,PinId);break;
			case DIO_PORTC:	CLR_BIT(DDRC_REG,PinId);break;
			case DIO_PORTD:	CLR_BIT(DDRD_REG,PinId);break;
			}
		}
	}
		else
		{
			//report error massage
		}
}


void SetPortValue(u8 PortId,u8 PortValue)
{
	if(PortId <= DIO_PORTD)
	{
		if(PortValue == HIGH)
		{
			switch(PortId)
			{
			case DIO_PORTA:	SET_REG(PORTA_REG);break;
			case DIO_PORTB:	SET_REG(PORTB_REG);break;
			case DIO_PORTC:	SET_REG(PORTC_REG);break;
			case DIO_PORTD: SET_REG(PORTD_REG);break;
			}
		}
		else if(PortValue == LOW)
		{
			switch(PortId)
			{
			case DIO_PORTA:	CLR_REG(PORTA_REG);break;
			case DIO_PORTB:	CLR_REG(PORTB_REG);break;
			case DIO_PORTC:	CLR_REG(PORTC_REG);break;
			case DIO_PORTD: CLR_REG(PORTD_REG);break;
			}
		}
		else
		{
			switch(PortId)
			{
				case DIO_PORTA:	ASSIGN_REG(PORTA_REG,PortValue);break;
				case DIO_PORTB:	ASSIGN_REG(PORTB_REG,PortValue);break;
				case DIO_PORTC:	ASSIGN_REG(PORTC_REG,PortValue);break;
				case DIO_PORTD: ASSIGN_REG(PORTD_REG,PortValue);break;
			}
		}
	}
	else
	{
		//report error massage
	}
}

void SetPortMode(u8 PortId,u8 PortMode)
{
	if(PortId <= DIO_PORTD)
	{
		if(PortMode == OUTPUT)
		{
			switch(PortId)
			{
			case DIO_PORTA:	SET_REG(DDRA_REG);break;
			case DIO_PORTB:	SET_REG(DDRB_REG);break;
			case DIO_PORTC:	SET_REG(DDRC_REG);break;
			case DIO_PORTD: SET_REG(DDRD_REG);break;
			}
		}
		else if(PortMode == INPUT)
		{
			switch(PortId)
			{
			case DIO_PORTA:	CLR_REG(DDRA_REG);break;
			case DIO_PORTB:	CLR_REG(DDRB_REG);break;
			case DIO_PORTC:	CLR_REG(DDRC_REG);break;
			case DIO_PORTD: CLR_REG(DDRD_REG);break;
			}
		}
		else
		{
			switch(PortId)
			{
				case DIO_PORTA:	ASSIGN_REG(DDRA_REG,PortMode);break;
				case DIO_PORTB:	ASSIGN_REG(DDRA_REG,PortMode);break;
				case DIO_PORTC:	ASSIGN_REG(DDRA_REG,PortMode);break;
				case DIO_PORTD: ASSIGN_REG(DDRA_REG,PortMode);break;
			}
		}
	}
	else
	{
		//report error massage
	}
}

u8 GetPinValue(u8 PinId,u8 PortId)
{
	u8 value;
	if(PinId <= PIN7 && PortId <= DIO_PORTD)
	{
		switch(PortId)
		{
		case DIO_PORTA:	value = GET_BIT(PINA_REG,PinId);break;
		case DIO_PORTB:	value = GET_BIT(PINB_REG,PinId);break;
		case DIO_PORTC: value = GET_BIT(PINC_REG,PinId);break;
		case DIO_PORTD: value = GET_BIT(PIND_REG,PinId);break;
		}
	}
	else
	{
		//report error massage
	}
	return value;
}

void TogglePin(u8 PinId,u8 PortId)
{
	if(PinId <= PIN7 && PortId <= DIO_PORTD)
	{
		switch(PortId)
		{
		case DIO_PORTA: TOG_BIT(PORTA_REG,PinId);break;
		case DIO_PORTB:	TOG_BIT(PORTB_REG,PinId);break;
		case DIO_PORTC: TOG_BIT(PORTC_REG,PinId);break;
		case DIO_PORTD: TOG_BIT(PORTD_REG,PinId);break;
		}
	}
	else
	{

	}
}
