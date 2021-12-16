/*
 * main.c
 *
 *  Created on: Dec 15, 2021
 *      Author: aaa
 */


#define F_CPU	8000000UL
#include"avr/delay.h"
#include"LIB/Types.h"
#include"DIO.h"
#include"KPD.h"
#include"LCD.h"
#include"KPD_config.h"

void main(void)
{
	//KPD Initialization
	SetPortMode(KPD_PORT,0x0F);
	SetPortValue(KPD_PORT,0xF0);
	//LCD Initialization
	SetPortMode(Data_Port,OUTPUT);
	SetPortMode(Control_Port,OUTPUT);
	LCD_Init();
	LCD_Write_Cmd(Set_Cursor);

	while(1)
	{
		u8 key = 0;
		key = GetPressedKey();
		if(key != 0)
		{
			LCD_Write_Char(key);
		}


	}

}
