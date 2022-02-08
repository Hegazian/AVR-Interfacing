/*
 * main.c
 *
 *  Created on: Dec 25, 2021
 *      Author: aaa
 */

#define	F_CPU	8000000UL
#include<util/delay.h>
#include"LIB/Types.h"
#include"DIO.h"
#include"LCD.h"
#include"KPD.h"
#include"KPD_config.h"
#include"motor.h"

void main(void)
{
	u8 left_flag = 0;
	u8 right_flag = 0;
	//KPD Initialization
	u8 key = 0;
	SetPortMode(KPD_PORT,0x0F);
	SetPortValue(KPD_PORT,0xF0);

	/*Initialization of LCD*/
	SetPortMode(Control_Port,OUTPUT);
	SetPortMode(Data_Port,OUTPUT);
	LCD_Init();

	/*MOTOR Initialization*/
	Motor M1;
	M1.MOTOR_PORT = PORTB;
	M1.LEFT_PIN = PIN1;
	M1.RIGHT_PIN = PIN2;
	Motor_Init(M1);
	LCD_Write_String("MOTOR DIR: ");

	while(1)
	{

		key = GetPressedKey();
		if(key != 0)
		{
			//LCD_Write_Char(key);
			if(key == '6')
			{
				LCD_GoTo_XY(1,12);
				LCD_Write_String("LEFT");
				Motor_Left(M1);
			}
			else if(key == '4')
			{
				LCD_GoTo_XY(1,12);
				LCD_Write_String("RIGHT");
				Motor_Right(M1);
			}
		}
	}


}
