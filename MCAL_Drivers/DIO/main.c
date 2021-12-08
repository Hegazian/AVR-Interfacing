/*
 * main.c
 *
 *  Created on: Dec 5, 2021
 *      Author: aaa
 */


#include"LIB/Types.h"
#include"DIO.h"
#include<avr/delay.h>
#define F_CPU 12000000 /* Define a CPU frequency of 12 Mega Hertz */

void main(void)
{

	SetPortMode(PORTA,OUTPUT);

	while(1)
	{
		SetPinValue(PIN0,PORTA,HIGH);
		SetPinValue(PIN1,PORTA,HIGH);
		SetPinValue(PIN2,PORTA,HIGH);
		SetPinValue(PIN3,PORTA,HIGH);
		SetPinValue(PIN4,PORTA,HIGH);
		SetPinValue(PIN5,PORTA,HIGH);
		SetPinValue(PIN6,PORTA,HIGH);
		SetPinValue(PIN7,PORTA,HIGH);
		_delay_ms(100);
		SetPinValue(PIN0,PORTA,LOW);
		SetPinValue(PIN1,PORTA,LOW);
		SetPinValue(PIN2,PORTA,LOW);
		SetPinValue(PIN3,PORTA,LOW);
		SetPinValue(PIN4,PORTA,LOW);
		SetPinValue(PIN5,PORTA,LOW);
		SetPinValue(PIN6,PORTA,LOW);
		SetPinValue(PIN7,PORTA,LOW);
		_delay_ms(100);


	}
}
