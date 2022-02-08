/*
 * led.c
 *
 * Created: 2/8/2022 11:13:09 AM
 *  Author: aaa
 */ 

#include "STD_Types.h"
#include "DIO.h"
#include "LED.h"
void LED_INIT(u8 led)
{
	u8 pin = led%10;
	switch(led)
	{
		case 0:
		PIN_MODE(PC0,OUTPUT);
		break;
		
		case 1:
		PIN_MODE(PC1,OUTPUT);
		break;
		
		case 2:
		PIN_MODE(PC2,OUTPUT);
		break;
		
		default:
		break;
	}
}

void LED_ON(u8 led)
{
	switch(led)
	{
		case 0:
		PIN_WRITE(PC0,HIGH);
		break;
		
		case 1:
		PIN_WRITE(PC1,HIGH);
		break;
		
		case 2:
		PIN_WRITE(PC2,HIGH);
		break;
		
		default:
		break;
	}
}

void LED_OFF(u8 led)
{
	switch(led)
	{
		case 0:
		PIN_WRITE(PC0,LOW);
		break;
		
		case 1:
		PIN_WRITE(PC1,LOW);
		break;
		
		case 2:
		PIN_WRITE(PC2,LOW);
		break;
		
		default:
		break;
	}
}

void LED_TOG(u8 led)
{
	switch(led)
	{
		case 1:
		PIN_TOG(PC0);
		break;
		
		case 2:
		PIN_TOG(PC1);
		break;
		
		case 3:
		PIN_TOG(PC2);
		break;
		
		default:
		break;
	}
}