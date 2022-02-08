/*
 * main.c
 *
 *  Created on: Dec 25, 2021
 *      Author: aaa
 */

#define F_CPU	8000000UL
#include"LIB/Types.h"
#include"DIO.h"
#include"motor.h"
#include<util/delay.h>


void main(void)
{
	Motor m1;
	m1.MOTOR_PORT = PORTB;
	m1.LEFT_PIN = PIN1;
	m1.RIGHT_PIN = PIN2;

	Motor_Init(m1);

	while(1)
	{
		Motor_Left(m1);
		_delay_ms(1000);
		Motor_Right(m1);
		_delay_ms(1000);
	}
}
