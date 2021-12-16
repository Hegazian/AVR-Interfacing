/*
 * Led.h
 *
 *  Created on: Dec 7, 2021
 *      Author: aaa
 */

#ifndef LED_H_
#define LED_H_


#define LedsNumber	8
#define LedPort		PORTA

void LED_INIT(void);

void LED_ON(void);

void LED_OFF(void);

void LED_ZigZag(void);

void LED_Diverging(void);

void LED_Converging(void);

void LED_Flashing(void);

void LED_Shift_Left(void);

void LED_shift_Right(void);

void LED_Ping_Bong(void);

#endif /* LED_H_ */
