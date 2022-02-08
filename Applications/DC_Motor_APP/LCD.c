/*
 * LCD.c
 *
 *  Created on: Dec 14, 2021
 *      Author: aaa
 */

#include"LIB/Types.h"
#include"LIB/set_math.h"
#define F_CPU	8000000UL
#include"avr/delay.h"
#include"DIO.h"
#include"LCD.h"

u8 x = 0;
void LCD_Init(void)
{
	/*delay 30 ms to ensure That LCD Initialized and power on*/
	_delay_ms(30);
	/*Return Home*/

	/*Function SET (8bit/2-line/5x7 dot character)*/
	LCD_Function_Set();
	_delay_ms(1);
	/*Display ON/OFF Control*/
	LCD_Display_Control(ON,ON,ON);
	_delay_ms(1);
	/*Clear Screen*/
	LCD_Clear_Screen();
	_delay_ms(2);
	/*Entry Mode SET*/
	LCD_EntryMode();
	_delay_ms(1);
	x = 1;

}
void LCD_Write_Cmd(u8 cmd)
{
	/*Set RS Pin to LOW*/
	SetPinValue(RS,Control_Port,LOW);
	/*Set RW Pin to LOW*/
	SetPinValue(RW,Control_Port,LOW);

	/* Load Command to Data Pins(D4....D7) using 4-bit Mode*/
	SetPinValue(PIN4,Data_Port,GET_BIT(cmd,4));
	SetPinValue(PIN5,Data_Port,GET_BIT(cmd,5));
	SetPinValue(PIN6,Data_Port,GET_BIT(cmd,6));
	SetPinValue(PIN7,Data_Port,GET_BIT(cmd,7));

	/*Set E Pin to HIGH for 1 us and then turn it to low to make a falling edge(latching)*/
	SetPinValue(E,Control_Port,HIGH);
	_delay_us(1);
	SetPinValue(E,Control_Port,LOW);
	_delay_us(1);
	if(x)
	{
		/* Load Command to Data Pins(D4....D7) using 4-bit Mode*/
		SetPinValue(PIN4,Data_Port,GET_BIT(cmd,0));
		SetPinValue(PIN5,Data_Port,GET_BIT(cmd,1));
		SetPinValue(PIN6,Data_Port,GET_BIT(cmd,2));
		SetPinValue(PIN7,Data_Port,GET_BIT(cmd,3));

		/*Set E Pin to HIGH for 1 us and then turn it to low to make a falling edge(latching)*/
		SetPinValue(E,Control_Port,HIGH);
		_delay_us(1);
		SetPinValue(E,Control_Port,LOW);
		_delay_us(1);
	}

	//wait 2 ms after every instruction
	_delay_ms(2);
}


void LCD_Write_Char(u8 chr)
{
	/*Set RS Pin to HIGH*/
	SetPinValue(RS,Control_Port,HIGH);
	/*Set RW Pin to LOW*/
	SetPinValue(RW,Control_Port,LOW);

	/* Load Command to Data Pins(D4....D7) using 4-bit Mode*/
	SetPinValue(PIN4,Data_Port,GET_BIT(chr,4));
	SetPinValue(PIN5,Data_Port,GET_BIT(chr,5));
	SetPinValue(PIN6,Data_Port,GET_BIT(chr,6));
	SetPinValue(PIN7,Data_Port,GET_BIT(chr,7));

	/*Set E Pin to HIGH for 1 us and then turn it to low to make a falling edge(latching)*/
	SetPinValue(E,Control_Port,HIGH);
	_delay_us(1);
	SetPinValue(E,Control_Port,LOW);
	_delay_us(1);

	/* Load Command to Data Pins(D4....D7) using 4-bit Mode*/
	SetPinValue(PIN4,Data_Port,GET_BIT(chr,0));
	SetPinValue(PIN5,Data_Port,GET_BIT(chr,1));
	SetPinValue(PIN6,Data_Port,GET_BIT(chr,2));
	SetPinValue(PIN7,Data_Port,GET_BIT(chr,3));

	/*Set E Pin to HIGH for 1 us and then turn it to low to make a falling edge(latching)*/
	SetPinValue(E,Control_Port,HIGH);
	_delay_us(1);
	SetPinValue(E,Control_Port,LOW);
	_delay_us(1);

	//wait 2 ms after every instruction
	_delay_us(100);
}

void LCD_Write_String(u8* str)
{
	while(*str)
	{
		LCD_Write_Char(*str);
		str++;
	}
}


void LCD_Function_Set()
{
	LCD_Write_Cmd(0x20);
	LCD_Write_Cmd(0x20);
	LCD_Write_Cmd(0x80);
}

void LCD_Display_Control(u8 display,u8 cursor,u8 blinking)
{
	if(display == ON && cursor == ON && blinking == ON)
	{
		LCD_Write_Cmd(0x00);
		LCD_Write_Cmd(0xF0);
	}

	else if(display == ON && cursor == OFF && blinking == OFF)
	{
		LCD_Write_Cmd(0x00);
		LCD_Write_Cmd(0xC0);
	}
	else if(display == ON && cursor == ON && blinking == OFF)
	{
		LCD_Write_Cmd(0x00);
		LCD_Write_Cmd(0xE0);
	}
	else if(display == ON && cursor == OFF && blinking == ON)
	{
		LCD_Write_Cmd(0x00);
		LCD_Write_Cmd(0xD0);
	}
	else if(display == OFF && cursor == OFF && blinking == OFF)
	{
		LCD_Write_Cmd(0x00);
		LCD_Write_Cmd(0x80);
	}

}

void LCD_Clear_Screen()
{
	LCD_Write_Cmd(0x00);
	LCD_Write_Cmd(0x01);
}

void LCD_EntryMode()
{
	LCD_Write_Cmd(0x00);
	LCD_Write_Cmd(0x60);
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


void LCD_Cursor_Shift(unsigned char direction)
{
	if (direction == RIGHT)
	{
		LCD_Write_Cmd(0x14);				// shift cursor 1 step to right
	}
	else if (direction == LEFT)
	{
		LCD_Write_Cmd(0x10);				// shift cursor 1 step to left
	}
}


void LCD_Display_Shift(unsigned char direction)
{
	if (direction == RIGHT)
	{
		LCD_Write_Cmd(0x1c);				// shift data on LCD 1 step to right
	}
	else if (direction == LEFT)
	{
		LCD_Write_Cmd(0x18);				// shift data on LCD 1 step to left
	}
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

void LCD_Print_Int(f32 integer)
{
	s32 fraction = 0;
	s32 thousands = 0;
	s32 dozens = 0;
	s32 ones = 0;
	if(integer<=1000 && integer>=0)
	{
		fraction = integer*10;
		fraction = fraction%10;
		thousands = (s32)integer%10;
		dozens = (((s32)integer-thousands)/10)%10;
		ones = (((s32)integer-dozens)/100)%10;

		switch(ones)
		{
		//case 0:LCD_Write_Char('0');break;
		case 1:LCD_Write_Char('1');break;
		case 2:LCD_Write_Char('2');break;
		case 3:LCD_Write_Char('3');break;
		case 4:LCD_Write_Char('4');break;
		case 5:LCD_Write_Char('5');break;
		case 6:LCD_Write_Char('6');break;
		case 7:LCD_Write_Char('7');break;
		case 8:LCD_Write_Char('8');break;
		case 9:LCD_Write_Char('9');break;
		}

		switch(dozens)
		{

		case 0:
			if(ones == 0)
			{
				break;
			}
			else
			{
				LCD_Write_Char('0');break;
			}
		case 1:LCD_Write_Char('1');break;
		case 2:LCD_Write_Char('2');break;
		case 3:LCD_Write_Char('3');break;
		case 4:LCD_Write_Char('4');break;
		case 5:LCD_Write_Char('5');break;
		case 6:LCD_Write_Char('6');break;
		case 7:LCD_Write_Char('7');break;
		case 8:LCD_Write_Char('8');break;
		case 9:LCD_Write_Char('9');break;
		}
		switch(thousands)
		{
		case 0:LCD_Write_Char('0');break;
		case 1:LCD_Write_Char('1');break;
		case 2:LCD_Write_Char('2');break;
		case 3:LCD_Write_Char('3');break;
		case 4:LCD_Write_Char('4');break;
		case 5:LCD_Write_Char('5');break;
		case 6:LCD_Write_Char('6');break;
		case 7:LCD_Write_Char('7');break;
		case 8:LCD_Write_Char('8');break;
		case 9:LCD_Write_Char('9');break;
		}
		switch(fraction)
		{
		case 0:LCD_Write_String(".0");break;
		case 1:LCD_Write_String(".1");break;
		case 2:LCD_Write_String(".2");break;
		case 3:LCD_Write_String(".3");break;
		case 4:LCD_Write_String(".4");break;
		case 5:LCD_Write_String(".5");break;
		case 6:LCD_Write_String(".6");break;
		case 7:LCD_Write_String(".7");break;
		case 8:LCD_Write_String(".8");break;
		case 9:LCD_Write_String(".9");break;
		}

	}
	else if(integer<0)
	{
		integer = (integer)*(-1);
		fraction = integer*10;
		fraction = fraction%10;
		thousands = (s32)integer%10;
		dozens = (((s32)integer-thousands)/10)%10;
		ones = (((s32)integer-dozens)/100)%10;
		LCD_Write_Char('-');
		switch(ones)
		{
		//case 0:LCD_Write_Char('0');break;
		case 1:LCD_Write_Char('1');break;
		case 2:LCD_Write_Char('2');break;
		case 3:LCD_Write_Char('3');break;
		case 4:LCD_Write_Char('4');break;
		case 5:LCD_Write_Char('5');break;
		case 6:LCD_Write_Char('6');break;
		case 7:LCD_Write_Char('7');break;
		case 8:LCD_Write_Char('8');break;
		case 9:LCD_Write_Char('9');break;
		}

		switch(dozens)
		{

		case 0:
			if(ones == 0)
			{
				break;
			}
			else
			{
				LCD_Write_Char('0');break;
			}
		case 1:LCD_Write_Char('1');break;
		case 2:LCD_Write_Char('2');break;
		case 3:LCD_Write_Char('3');break;
		case 4:LCD_Write_Char('4');break;
		case 5:LCD_Write_Char('5');break;
		case 6:LCD_Write_Char('6');break;
		case 7:LCD_Write_Char('7');break;
		case 8:LCD_Write_Char('8');break;
		case 9:LCD_Write_Char('9');break;
		}
		switch(thousands)
		{
		case 0:LCD_Write_Char('0');break;
		case 1:LCD_Write_Char('1');break;
		case 2:LCD_Write_Char('2');break;
		case 3:LCD_Write_Char('3');break;
		case 4:LCD_Write_Char('4');break;
		case 5:LCD_Write_Char('5');break;
		case 6:LCD_Write_Char('6');break;
		case 7:LCD_Write_Char('7');break;
		case 8:LCD_Write_Char('8');break;
		case 9:LCD_Write_Char('9');break;
		}
		switch(fraction)
		{
		case 0:LCD_Write_String(".0");break;
		case 1:LCD_Write_String(".1");break;
		case 2:LCD_Write_String(".2");break;
		case 3:LCD_Write_String(".3");break;
		case 4:LCD_Write_String(".4");break;
		case 5:LCD_Write_String(".5");break;
		case 6:LCD_Write_String(".6");break;
		case 7:LCD_Write_String(".7");break;
		case 8:LCD_Write_String(".8");break;
		case 9:LCD_Write_String(".9");break;
		}

	}
	else
	{

	}

}

