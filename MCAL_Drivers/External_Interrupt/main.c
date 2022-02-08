/*
 * main.c
 *
 *  Created on: Dec 27, 2021
 *      Author: aaa
 */

#include"LIB/Types.h"
#include"LIB/set_math.h"
#include"DIO.h"
#include"Interrupt.h"
#include<avr/interrupt.h>
//#include<avr/io.h>

//u8 flag = 0;
void main(void)
{

	//Initialization
	SetPinMode(PIN7,DIO_PORTB,OUTPUT);	//make pin 7 in PORTB output for led
	SetPinMode(PIN3,DIO_PORTD,INPUT);	//make pin3 in PORTD(INT1) INPUT for push bottom
	SetPinValue(PIN3,DIO_PORTD,HIGH);	//make pin3 in PORTD(INT1) High Pull up to detect low level

	//CLR_BIT(MCUCR,2);
	//CLR_BIT(MCUCR,3);
	//Interrupt Initialization
	Interrupt_Init(EXT_INT1,LOW_LEVEL);
	//SET_BIT(GICR,7);
	//SET_BIT(SREG,7);

	while(1)
	{

	}

}

ISR(INT1_vect)
{
	/*if(flag == 0)
	{
		SetPinValue(PIN7,DIO_PORTB,HIGH);
		flag = 1;
	}
	else
	{
		SetPinValue(PIN7,DIO_PORTB,LOW);
		flag = 0;
	}*/
	TogglePin(PIN7,DIO_PORTB);
}
