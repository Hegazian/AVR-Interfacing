/*
 * LCD.h
 *
 *  Created on: Dec 9, 2021
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
#define Clear			0x01
#define Return_Home		0x02
#define Entry_Mode		0x06
#define	Display_On		0x0E
#define	Display_Off		0x08
#define	Reset			0x30
#define	Data_8bit		0x38
#define	Data_4bit		0x40
#define	Set_Cursor		0x80
#define	Cursor_On		0x0E
#define	Cursor_Off		0x0C
#define	Cursor_Bilink	0x0F


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

#endif /* LCD_H_ */
