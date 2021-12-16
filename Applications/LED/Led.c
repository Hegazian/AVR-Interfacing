/*
 * Led.c
 *
 *  Created on: Dec 7, 2021
 *      Author: aaa
 */

#include"LIB/Types.h"
#include"DIO.h"
#include"Led.h"
#include"avr/delay.h"


void LED_INIT(void)
{
	if(LedsNumber<= (PIN7+1) && LedPort <= PORTD )
	{
		for(int i =0;i<LedsNumber;i++)
			SetPinMode(i,LedPort,OUTPUT);
	}
	else
	{
		//report error
	}

}

void LED_ON(void)
{
	if(LedsNumber<= (PIN7+1) && LedPort <= PORTD )
	{
		for(int i =0;i<LedsNumber;i++)
			SetPinValue(i,LedPort,HIGH);
	}
	else
	{
		//report error
	}

}

void LED_OFF(void)
{
	if(LedsNumber<= (PIN7+1) && LedPort <= PORTD )
	{
		for(int i =0;i<LedsNumber;i++)
			SetPinValue(i,LedPort,LOW);
	}
	else
	{
		//report error
	}
}

void LED_ZigZag(void)
{
	if(LedsNumber<= (PIN7+1) && LedPort <= PORTD )
	{
		for(int i =0;i<LedsNumber;i++)
		{
			SetPinValue(i,LedPort,HIGH);
			_delay_ms(30);
		}
		for(int i=LedsNumber-1;i>=0;i--)
		{
			SetPinValue(i,LedPort,LOW);
			_delay_ms(30);
		}
	}
	else
	{
		//report error
	}
}

void LED_Diverging(void)
{
	int i,j;
	if(LedsNumber<= (PIN7+1) && LedPort <= PORTD )
	{
		for(i=0,j=LedsNumber-1;i<LedsNumber/2 && j>=4;i++,j--)
		{
			SetPinValue(i,LedPort,HIGH);
			SetPinValue(j,LedPort,HIGH);
			_delay_ms(40);
		}
		LED_OFF();
		_delay_ms(20);
	}
	else
	{
		//report error
	}
}

void LED_Converging(void)
{
	int i,j;
	if(LedsNumber<= (PIN7+1) && LedPort <= PORTD )
	{
		for(i=(LedsNumber/2)-1,j=LedsNumber/2;i>=0 && j<=LedsNumber-1;i--,j++)
		{
			SetPinValue(i,LedPort,HIGH);
			SetPinValue(j,LedPort,HIGH);
			_delay_ms(40);
		}
		LED_OFF();
		_delay_ms(20);
	}
	else
	{
		//report error
	}
}

void LED_Flashing(void)
{
	if(LedsNumber<= (PIN7+1) && LedPort <= PORTD )
	{
		LED_ON();
		_delay_ms(40);
		LED_OFF();
		_delay_ms(40);
	}
	else
	{
		//report error
	}
}

void LED_Shift_Left(void)
{
	int i;
	if(LedsNumber<= (PIN7+1) && LedPort <= PORTD )
	{
		for(i=0;i<LedsNumber;i++)
		{
			SetPinValue(i,LedPort,HIGH);
			_delay_ms(50);
		}
		LED_OFF();
		_delay_ms(50);
	}
	else
	{
		//report error
	}
}

void LED_shift_Right(void)
{
	int i;
	if(LedsNumber<= (PIN7+1) && LedPort <= PORTD )
	{
		for(i=LedsNumber-1;i>=0;i--)
		{
			SetPinValue(i,LedPort,HIGH);
			_delay_ms(50);
		}
		LED_OFF();
		_delay_ms(50);
	}
	else
	{
		//report error
	}
}

void LED_Ping_Bong(void)
{
	int i;
	if(LedsNumber<= (PIN7+1) && LedPort <= PORTD )
	{
		SetPinValue(PIN0,LedPort,HIGH);
		SetPinValue(PIN7,LedPort,HIGH);
		for(i=PIN1;i<=PIN6;i++)
		{
			SetPinValue(i,LedPort,HIGH);
			_delay_ms(20);
			SetPinValue(i,LedPort,LOW);
		}
		for(i=PIN6;i>=PIN1;i--)
		{
			SetPinValue(i,LedPort,HIGH);
			_delay_ms(20);
			SetPinValue(i,LedPort,LOW);
		}

	}
	else
	{
		//report error
	}
}
