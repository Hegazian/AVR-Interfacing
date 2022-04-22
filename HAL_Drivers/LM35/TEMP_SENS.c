/*
 * TEMP_SENS.c
 *
 * Created: 2/16/2022 9:28:13 AM
 *  Author: aaa
 */ 

#include "STD_Types.h"
#include "ADC.h"
#include "DIO.h"
#include "TEMP_SENS_CFG.h"
#include "TEMP_SENS.h"

void LM35_INIT(void)
{
	//PIN_MODE(LM35_PIN,INPUT);
	ADC_INIT();
}

u16 LM35_READ(void)
{
	u32 reading = ADC_READ();
	u16 result = ((reading*255)/1023);
	return result;
	
}