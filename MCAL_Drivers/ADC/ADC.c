/*
 * ADC.c
 *
 *  Created on: Jan 8, 2022
 *      Author: aaa
 */

#include"LIB/Types.h"
#include"LIB/set_math.h"
#include"ADC_Registers.h"
#include"ADC.h"
#include"ADC_config.h"

void ADC_INIT(void)
{
	/*Enable ADC*/
	ADC_Enabled();
	/*Select ADC Reference Voltage*/
	if(ADC_VREF == ADC_VCC)
	{
		SET_BIT(ADMUX_REG,REFS0);
		CLR_BIT(ADMUX_REG,REFS1);
	}
	else if(ADC_VREF == ADC_INTERNAL_REF)
	{
		SET_BIT(ADMUX_REG,REFS0);
		SET_BIT(ADMUX_REG,REFS1);
	}
	else if(ADC_VREF == ADC_EXTRNAL_VREF)
	{
		CLR_BIT(ADMUX_REG,REFS0);
		CLR_BIT(ADMUX_REG,REFS1);
	}
	/*Select ADC ADJUST Result*/
	if(ADC_ADJUST == ADC_LEFT)
	{
		SET_BIT(ADMUX_REG,ADLAR);
	}
	else if(ADC_ADJUST == ADC_RIGHT)
	{
		CLR_BIT(ADMUX_REG,ADLAR);
	}
	/*Select ADC Prescaler*/
	if(ADC_PRESCALER == DivisionFactorBy128)
	{
		SET_BIT(ADCSRA_REG,ADPS2);
		SET_BIT(ADCSRA_REG,ADPS1);
		SET_BIT(ADCSRA_REG,ADPS0);
	}
	else if(ADC_PRESCALER == DivisionFactorBy64)
	{
		SET_BIT(ADCSRA_REG,ADPS2);
		SET_BIT(ADCSRA_REG,ADPS1);
		CLR_BIT(ADCSRA_REG,ADPS0);
	}
	else if(ADC_PRESCALER == DivisionFactorBy32)
	{
		SET_BIT(ADCSRA_REG,ADPS2);
		CLR_BIT(ADCSRA_REG,ADPS1);
		SET_BIT(ADCSRA_REG,ADPS0);
	}
	else if(ADC_PRESCALER == DivisionFactorBy16)
	{
		SET_BIT(ADCSRA_REG,ADPS2);
		CLR_BIT(ADCSRA_REG,ADPS1);
		CLR_BIT(ADCSRA_REG,ADPS0);
	}
	else if(ADC_PRESCALER == DivisionFactorBy8)
	{
		CLR_BIT(ADCSRA_REG,ADPS2);
		SET_BIT(ADCSRA_REG,ADPS1);
		SET_BIT(ADCSRA_REG,ADPS0);
	}
	else if(ADC_PRESCALER == DivisionFactorBy4)
	{
		CLR_BIT(ADCSRA_REG,ADPS2);
		SET_BIT(ADCSRA_REG,ADPS1);
		CLR_BIT(ADCSRA_REG,ADPS0);
	}
	else if(ADC_PRESCALER == DivisionFactorBy2)
	{
		CLR_BIT(ADCSRA_REG,ADPS2);
		CLR_BIT(ADCSRA_REG,ADPS1);
		CLR_BIT(ADCSRA_REG,ADPS0);
	}

}

u16 ADC_Read(u8 PinId)
{

	PinId = PinId & 0b00000111;
	/*Select ADC Channel*/
	switch(PinId)
	{
		case A0:CLR_BIT(ADMUX_REG,MUX0);CLR_BIT(ADMUX_REG,MUX1);CLR_BIT(ADMUX_REG,MUX2);break;//000
		case A1:SET_BIT(ADMUX_REG,MUX0);CLR_BIT(ADMUX_REG,MUX1);CLR_BIT(ADMUX_REG,MUX2);break;//001
		case A2:CLR_BIT(ADMUX_REG,MUX0);SET_BIT(ADMUX_REG,MUX1);CLR_BIT(ADMUX_REG,MUX2);break;//010
		case A3:SET_BIT(ADMUX_REG,MUX0);SET_BIT(ADMUX_REG,MUX1);CLR_BIT(ADMUX_REG,MUX2);break;//011
		case A4:CLR_BIT(ADMUX_REG,MUX0);CLR_BIT(ADMUX_REG,MUX1);SET_BIT(ADMUX_REG,MUX2);break;//100
		case A5:SET_BIT(ADMUX_REG,MUX0);CLR_BIT(ADMUX_REG,MUX1);SET_BIT(ADMUX_REG,MUX2);break;//101
		case A6:CLR_BIT(ADMUX_REG,MUX0);SET_BIT(ADMUX_REG,MUX1);SET_BIT(ADMUX_REG,MUX2);break;//110
		case A7:SET_BIT(ADMUX_REG,MUX0);SET_BIT(ADMUX_REG,MUX1);SET_BIT(ADMUX_REG,MUX2);break;//111
	}
	/*Start Conversion*/
	SET_BIT(ADCSRA_REG,ADSC);
	/*Wait until the flag bit is switched to 1 (Conversion Complete)*/
	while(GET_BIT(ADCSRA_REG,ADIF) == 0);
	/*Return 16 bits in ADCDATA Register */
	return ADCDATA_REG;
}

void ADC_Enabled(void)
{
	SET_BIT(ADCSRA_REG,ADEN);
}

void ADC_Disabled(void)
{
	CLR_BIT(ADCSRA_REG,ADEN);
}
