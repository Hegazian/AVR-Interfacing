/*
 * motor.c
 *
 *  Created on: Dec 25, 2021
 *      Author: aaa
 */

#include"LIB/Types.h"
#include"DIO.h"
#include"motor.h"

void Motor_Init(Motor m)
{
	SetPinMode(m.LEFT_PIN,m.MOTOR_PORT,OUTPUT);
	SetPinMode(m.RIGHT_PIN,m.MOTOR_PORT,OUTPUT);
}

void Motor_Left(Motor m)
{

	SetPinValue(m.LEFT_PIN,m.MOTOR_PORT,HIGH);
	SetPinValue(m.RIGHT_PIN,m.MOTOR_PORT,LOW);
}

void Motor_Right(Motor m)
{

	SetPinValue(m.LEFT_PIN,m.MOTOR_PORT,LOW);
	SetPinValue(m.RIGHT_PIN,m.MOTOR_PORT,HIGH);
}
