/*
 * RELAY.c
 *
 * Created: 2/8/2022 2:10:43 PM
 *  Author: aaa
 */ 

#include "RELAY_CFG.h"
#include "STD_Types.h"
#include "DIO.h"
#include "RELAY.h"


void RELAY_INIT(u8 REL)
{
	switch(REL)
	{
		case RELAY_1_PIN:
		PIN_MODE(REL,OUTPUT);
		break;
		
		case RELAY_2_PIN:
		PIN_MODE(REL,OUTPUT);
		break;
		
		default:
		break;
		
	}
}

void RELAY_ON(u8 REL)
{
	switch(REL)
	{
		case RELAY_1_PIN:
		PIN_WRITE(REL,HIGH);
		break;
		
		case RELAY_2_PIN:
		PIN_WRITE(REL,HIGH);
		break;
		
		default:
		break;
		
	}
}

void RELAY_OFF(u8 REL)
{
	switch(REL)
	{
		case RELAY_1_PIN:
		PIN_WRITE(REL,LOW);
		break;
		
		case RELAY_2_PIN:
		PIN_WRITE(REL,LOW);
		break;
		
		default:
		break;
		
	}
}