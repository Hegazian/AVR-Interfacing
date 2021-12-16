/*
 * LCD.c
 *
 *  Created on: Dec 9, 2021
 *      Author: aaa
 */

#include"LIB/Types.h"
#define F_CPU	8000000UL
#include"avr/delay.h"
#include"DIO.h"
#include"LCD.h"




void LCD_Init(void)
{
	/*delay 30 ms to ensure That LCD Initialized and power on*/
	_delay_ms(30);
	/*Return Home*/
	LCD_Write_Cmd(Return_Home);
	_delay_ms(2);
	/*Function SET (8bit/2-line/5x7 dot character)*/
	LCD_Write_Cmd(Data_8bit);
	_delay_ms(1);
	/*Display ON/OFF Control*/
	LCD_Write_Cmd(Display_On);
	_delay_ms(1);
	/*Clear Screen*/
	LCD_Write_Cmd(Clear);
	_delay_ms(2);
	/*Entry Mode SET*/
	LCD_Write_Cmd(Entry_Mode);
	_delay_ms(2);

}


void LCD_Write_Cmd(u8 cmd)
{
	/*Set RS Pin to LOW*/
	SetPinValue(RS,Control_Port,LOW);
	/*Set RW Pin to LOW*/
	SetPinValue(RW,Control_Port,LOW);
	/*Set E Pin to HIGH*/
	SetPinValue(E,Control_Port,HIGH);
	/* Load Command to Data Pins(D0....D7)*/
	SetPortValue(Data_Port,cmd);
	/*Set E Pin to LOW */
	SetPinValue(E,Control_Port,LOW);
	_delay_ms(2);
	SetPinValue(E,Control_Port,HIGH);
	_delay_ms(1);
}

void LCD_Write_Char(u8 chr)
{
	/*Set RS Pin to LOW*/
	SetPinValue(RS,Control_Port,HIGH);
	/*Set RW Pin to LOW*/
	SetPinValue(RW,Control_Port,LOW);
	/*Set E Pin to HIGH*/
	SetPinValue(E,Control_Port,HIGH);
	/* Load Character to Data Pins(D0....D7)*/
	SetPortValue(Data_Port,chr);
	/*Set E Pin to LOW */
	SetPinValue(E,Control_Port,LOW);
	_delay_ms(2);
	SetPinValue(E,Control_Port,HIGH);
	_delay_ms(1);
}

void LCD_Write_String(u8* str)
{
	u8 i =0;
	while(str[i]!=0)
		LCD_Write_Char(str[i++]);
}

void LCD_GoTo_XY(u8 x,u8 y)
{
	switch(x)
	{
	case 1:
		LCD_Write_Cmd(y+127);
		break;
	case 2:
		LCD_Write_Cmd(y+191);
		break;
	}
}

void LCD_ClearLine(u8 line)
{
	LCD_GoTo_XY(line,1);
	LCD_Write_String("                ");
}


void LCD_WriteExtraChar (u8* ExtraChar,u8 Y,u8 X)
{
    u8 iteration1,iteration2;

    /*DDRAM-->CGRAM*/
    LCD_Write_Cmd(64);
	for(iteration1=0 ; iteration1<64 ; iteration1++)
	{
		LCD_Write_Char(ExtraChar[iteration1]);
	}
	/*CGRAM-->DDRAM*/
	LCD_Write_Cmd(128);
	LCD_GoTo_XY(Y,X);
	/*First eight character which saved at CGRAM*/
	for (iteration2=0; iteration2<=7 ; iteration2++)
	{
		/* Write bytes of DDRAM */
		LCD_Write_Char(iteration2);

		_delay_ms(5);
	}
}
