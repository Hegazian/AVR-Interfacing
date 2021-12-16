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
		Count_Down(0,9,100);
		Count_Up(0,9,100);
	}
}
