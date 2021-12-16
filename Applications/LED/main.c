/*
 * main.c
 *
 *  Created on: Dec 7, 2021
 *      Author: aaa
 */

//#include"LIB/Types.h"
//#include"DIO.h"
#include"Led.h"
#include"avr/delay.h"


void main(void)
{
	LED_INIT();
	while(1)
	{
		LED_ON();
		_delay_ms(200);
		LED_OFF();
		_delay_ms(200);
		LED_Flashing();
		_delay_ms(200);
		LED_ZigZag();
		_delay_ms(200);
		LED_Diverging();
		_delay_ms(200);
		LED_Converging();
		_delay_ms(200);
		LED_Shift_Left();
		_delay_ms(200);
		LED_shift_Right();
		_delay_ms(200);
		LED_Ping_Bong();
		_delay_ms(200);

	}

}
