/*
 * SERVO.c
 *
 * Created: 2/23/2022 10:53:04 AM
 *  Author: aaa
 */ 

#include "STD_Types.h"
#include "SERVO_CFG.h"
#include "SERVO.h"
#include "TIMER1.h"

void SERVO_INIT(void)
{
	PWM1_INIT();
	PWM1_SET_FREQUANCY(SERVO_FREQUANCY);
}


void SET_SERVO_ANGLE(u16 angle)
{
	PWM1_SET_DUTY_CYCLE(((5*angle)/180)+5);
}
void SERVO_START()
{
	PWM1_START();
}

void SERVO_STOP()
{
	PWM1_STOP();
}