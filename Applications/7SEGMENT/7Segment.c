/*
 * 7Segment.c
 *
 *  Created on: Dec 8, 2021
 *      Author: aaa
 */

#include"LIB/Types.h"
#include"DIO.h"
#include"7Segment.h"
#include"avr/delay.h"


void Seven_Segment_Init(void)
{
	if(PortOf7Seg_1 <= PORTD)
	{
		SetPortMode(PortOf7Seg_1,OUTPUT);
		SetPortValue(PortOf7Seg_1,LOW);
	}
	else
	{
		//report error
	}
}

void Display_Number(u8 N)
{

			switch(N)
			{
			case 0:
				SetPortValue(PortOf7Seg_1,HIGH);
				SetPinValue(PIN0,PortOf7Seg_1,LOW);
				SetPinValue(PIN1,PortOf7Seg_1,LOW);
				SetPinValue(PIN2,PortOf7Seg_1,LOW);
				SetPinValue(PIN3,PortOf7Seg_1,LOW);
				SetPinValue(PIN4,PortOf7Seg_1,LOW);
				SetPinValue(PIN5,PortOf7Seg_1,LOW);
				break;
			case 1:
				SetPortValue(PortOf7Seg_1,HIGH);
				SetPinValue(PIN1,PortOf7Seg_1,LOW);
				SetPinValue(PIN2,PortOf7Seg_1,LOW);
				break;
			case 2:
				SetPortValue(PortOf7Seg_1,HIGH);
				SetPinValue(PIN0,PortOf7Seg_1,LOW);
				SetPinValue(PIN1,PortOf7Seg_1,LOW);
				SetPinValue(PIN3,PortOf7Seg_1,LOW);
				SetPinValue(PIN4,PortOf7Seg_1,LOW);
				SetPinValue(PIN6,PortOf7Seg_1,LOW);
				break;
			case 3:
				SetPortValue(PortOf7Seg_1,HIGH);
				SetPinValue(PIN0,PortOf7Seg_1,LOW);
				SetPinValue(PIN1,PortOf7Seg_1,LOW);
				SetPinValue(PIN2,PortOf7Seg_1,LOW);
				SetPinValue(PIN3,PortOf7Seg_1,LOW);
				SetPinValue(PIN6,PortOf7Seg_1,LOW);
				break;
			case 4:
				SetPortValue(PortOf7Seg_1,HIGH);
				SetPinValue(PIN1,PortOf7Seg_1,LOW);
				SetPinValue(PIN2,PortOf7Seg_1,LOW);
				SetPinValue(PIN5,PortOf7Seg_1,LOW);
				SetPinValue(PIN6,PortOf7Seg_1,LOW);
				break;
			case 5:
				SetPortValue(PortOf7Seg_1,HIGH);
				SetPinValue(PIN0,PortOf7Seg_1,LOW);
				SetPinValue(PIN2,PortOf7Seg_1,LOW);
				SetPinValue(PIN3,PortOf7Seg_1,LOW);
				SetPinValue(PIN5,PortOf7Seg_1,LOW);
				SetPinValue(PIN6,PortOf7Seg_1,LOW);
				break;
			case 6:
				SetPortValue(PortOf7Seg_1,HIGH);
				SetPinValue(PIN0,PortOf7Seg_1,LOW);
				SetPinValue(PIN2,PortOf7Seg_1,LOW);
				SetPinValue(PIN3,PortOf7Seg_1,LOW);
				SetPinValue(PIN4,PortOf7Seg_1,LOW);
				SetPinValue(PIN5,PortOf7Seg_1,LOW);
				SetPinValue(PIN6,PortOf7Seg_1,LOW);
				break;
			case 7:
				SetPortValue(PortOf7Seg_1,HIGH);
				SetPinValue(PIN0,PortOf7Seg_1,LOW);
				SetPinValue(PIN1,PortOf7Seg_1,LOW);
				SetPinValue(PIN2,PortOf7Seg_1,LOW);
				break;
			case 8:
				SetPortValue(PortOf7Seg_1,HIGH);
				SetPortValue(PortOf7Seg_1,LOW);
				break;
			case 9:
				SetPortValue(PortOf7Seg_1,HIGH);
				SetPinValue(PIN0,PortOf7Seg_1,LOW);
				SetPinValue(PIN1,PortOf7Seg_1,LOW);
				SetPinValue(PIN2,PortOf7Seg_1,LOW);
				SetPinValue(PIN3,PortOf7Seg_1,LOW);
				SetPinValue(PIN5,PortOf7Seg_1,LOW);
				SetPinValue(PIN6,PortOf7Seg_1,LOW);
				break;
			default:SetPortValue(PortOf7Seg_1,HIGH);break;
			}
}


void Count_Down(u8 start,u8 end,u8 time)
{
	if(start >= 0 && end <= 9 && start < end)
	{
		for(int i=end;i>=start;i--)
		{
			Display_Number(i);
			_delay_ms(time);
		}
	}
	else
	{
		SetPortValue(PortOf7Seg_1,HIGH);
	}
}

void Count_Up(u8 start,u8 end,u8 time)
{
	if(start >= 0 && end <= 9 && start < end)
	{
		for(int i=start;i<=end;i++)
		{
			Display_Number(i);
			_delay_ms(time);
		}
	}
	else
	{
		SetPortValue(PortOf7Seg_1,HIGH);
	}
}
