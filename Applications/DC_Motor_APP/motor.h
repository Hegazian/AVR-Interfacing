/*
 * motor.h
 *
 *  Created on: Dec 25, 2021
 *      Author: aaa
 */

#ifndef MOTOR_H_
#define MOTOR_H_

/*#define MOTOR_PORT	PORTB
#define LEFT_PIN	PIN1
#define RIGHT_PIN	PIN2
*/

typedef struct motor
{
	u8 MOTOR_PORT;
	u8 LEFT_PIN	;
	u8 RIGHT_PIN;

}Motor;
void Motor_Init(Motor m);

void Motor_Left(Motor m);

void Motor_Right(Motor m);


#endif /* MOTOR_H_ */
