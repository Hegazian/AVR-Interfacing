/*
 * WDT.c
 *
 * Created: 2/20/2022 11:28:55 AM
 *  Author: aaa
 */ 

#include "BIT_MATH.h"
#include "STD_Types.h"
#include "WDT.h"
#include "WDT_REG.h"
#include "WDT_CFG.h"

void WDT_INIT(void)
{
	//set prescalat to 2.1sec
	SET_BIT(WDTCR_REG,WDP0);
	SET_BIT(WDTCR_REG,WDP1);
	SET_BIT(WDTCR_REG,WDP2);
	//enable whatch dog timer
	SET_BIT(WDTCR_REG,WDE);
}

void WDT_REFRESH(void)
{
	asm("WDR");
}