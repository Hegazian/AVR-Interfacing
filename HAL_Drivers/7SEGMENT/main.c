/*
 * main.c
 *
 *  Created on: Dec 8, 2021
 *      Author: aaa
 */

#include"LIB/Types.h"
#include"7Segment.h"
#include"avr/delay.h"

void main(void)
{
	Seven_Segment_Init();
	while(1)
	{
		/*Display_Number(0);
		_delay_ms(500);
		Display_Number(1);
		_delay_ms(500);
		Display_Number(2);
		_delay_ms(500);
		Display_Number(3);
		_delay_ms(500);
		Display_Number(4);
		_delay_ms(500);
		Display_Number(5);
		_delay_ms(500);
		Display_Number(6);
		_delay_ms(500);
		Display_Number(7);
		_delay_ms(500);
		Display_Number(8);
		_delay_ms(500);
		Display_Number(9);
		_delay_ms(500);*/
		Count_Down(0,9,500);
		Count_Up(0,9,500);
	}
}
