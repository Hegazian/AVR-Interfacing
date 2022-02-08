/*
 * BUZZER.c
 *
 * Created: 2/8/2022 1:16:12 PM
 *  Author: aaa
 */ 

#define F_CPU	16000000UL
#include <util/delay.h>
#include "STD_Types.h"
#include "DIO.h"
#include "BUZZER.h"
#include "BUZZER_CFG.h"

void BUZZER_INIT(void)
{
	PIN_MODE(BUZ,OUTPUT);	
}

void BUZZER_ON(void)
{
	PIN_WRITE(BUZ,HIGH);
}

void BUZZER_OFF(void)
{
	PIN_WRITE(BUZ,LOW);
}

void BUZZER_TOG(void)
{
	PIN_TOG(BUZ);
}

void BUZZER_ONCE(void)
{
	BUZZER_ON();
	_delay_ms(100);
	BUZZER_OFF();
	_delay_ms(100);
	
}

void BUZZER_TWICE(void)
{
	BUZZER_ON();
	_delay_ms(100);
	BUZZER_OFF();
	_delay_ms(100);
	
	BUZZER_ON();
	_delay_ms(100);
	BUZZER_OFF();
	_delay_ms(100);
}

void BUZZER_TRIPLE(void)
{
	BUZZER_ON();
	_delay_ms(100);
	BUZZER_OFF();
	_delay_ms(100);
	
	BUZZER_ON();
	_delay_ms(100);
	BUZZER_OFF();
	_delay_ms(100);
	
	BUZZER_ON();
	_delay_ms(100);
	BUZZER_OFF();
	_delay_ms(100);
	
}

void BUZZER_LONG(void)
{
	BUZZER_ON();
	_delay_ms(2000);
	BUZZER_OFF();	
}