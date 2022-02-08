/*
 * LCD.h
 *
 *  Created on: Dec 14, 2021
 *      Author: aaa
 */

#ifndef LCD_H_
#define LCD_H_

/*
 * This is Driver describes LCD (16x2) in Hardware Abstraction layer (HAL).
 * LCD(Liquid Character Display)
 * we will work on this driver based on the data sheet of LCD which placed with this driver
 * Based on data sheet this LCD has 16 Pins:
 * 1-Control Pins:(RS-RW-E) it consists of 3 Pins:
 * 													1- RS pin (Register select pin) this pin used to determine what you will request from LCD (Data display/Command).
 *   												2- RW pin (Read/Write) pin : it is used to determine if You will Write on LCD or read a register from it.
 *   												3- E pin (Enable) pin : it is used to Enable signal to read data when E is HIGH or Write data When it is falling edge
 * 2-Data Pins: it consists of 8 Pins (D0......D7).
 *
 *
 *
 */

/****************************************************************************************************/
/***************************************Public Macros************************************************/
/***************************************************************************************************/

/*PINS Definitions*/
#define Control_Port	PORTD
#define Data_Port		PORTC
#define RS				PIN0
#define RW				PIN1
#define E				PIN2

/*Commands Instructions*/
#define RIGHT			1
#define LEFT			0
#define ON				1
#define OFF				0

/*************************************************************************************************/
/**************************************Public Functions******************************************/
/************************************************************************************************/

void LCD_Init(void);

void LCD_Write_Cmd(u8 cmd);

void LCD_Write_Char(u8 chr);

void LCD_Write_String(u8* str);

void LCD_GoTo_XY(u8 x,u8 y);

void LCD_ClearLine(u8 line);

void LCD_WriteExtraChar (u8* ExtraChar,u8 Y,u8 X);

void LCD_Function_Set(void);

void LCD_Display_Control(u8 display,u8 cursor,u8 blinking);

void LCD_Clear_Screen(void);

void LCD_EntryMode(void);

void LCD_Cursor_Shift(unsigned char direction);

void LCD_Display_Shift(unsigned char direction);

void LCD_Print_Int(f32 integer);


#endif /* LCD_H_ */
