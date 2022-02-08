/*
 * KPD.c
 *
 *  Created on: Dec 15, 2021
 *      Author: aaa
 */

#define F_CPU	8000000UL
#include"avr/delay.h"
#include"LIB/Types.h"
#include"DIO.h"
#include"KPD.h"
#include"KPD_config.h"
#include"KPD_prev.h"



u8 SwitchValue [4][4]={{'1','2','3','/'},
					   {'4','5','6','*'},
					   {'7','8','9','+'},
					   {'c','0','=','-'}};



u8 GetPressedKey(void)
{
	u8 col;
	u8 row;
	u8 PressedKey = 0;
	for(col = Col1 ; col <= Col4 ; col++)
	{
		SetPinValue(col,KPD_PORT,LOW);
		for(row = Row1; row <= Row4; row++)
		{
			if(GetPinValue(row,KPD_PORT) == LOW)
			{
				PressedKey = SwitchValue[row-4][col];
				while(GetPinValue(row,KPD_PORT) == LOW);
				//_delay_ms(50);
			}
		}
		SetPinValue(col,KPD_PORT,HIGH);
	}

	return PressedKey;
}
