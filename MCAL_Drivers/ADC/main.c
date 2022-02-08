/*
 * main.c
 *
 *  Created on: Jan 8, 2022
 *      Author: aaa
 */

#define	F_CPU	8000000
#include"avr/delay.h"
#include"LIB/Types.h"
#include"DIO.h"
#include"LCD.h"
#include"ADC.h"


void main(void)
{

	u16 ADC;
	f32 volt;
	SetPinMode(PIN0,PORTA,INPUT);
	ADC_INIT();
	SetPortMode(Data_Port,OUTPUT);
	SetPortMode(Control_Port,OUTPUT);
	LCD_Init();
	LCD_GoTo_XY(1,1);
	ADC = ADC_Read(A0);
	volt = (f32)(ADC*20)/1024;
	LCD_Print_Int(volt);
	LCD_Write_String(" Volt");


	while(1)
	{

	}
}
