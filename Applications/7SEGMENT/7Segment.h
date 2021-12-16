/*
 * 7Segment.h
 *
 *  Created on: Dec 8, 2021
 *      Author: aaa
 */

#ifndef _7SEGMENT_H_
#define _7SEGMENT_H_

/*
 * 																						 0
 * 																						---
 * 																					 5 | 6 |1
 * 																						---
 * 																					  4|   |2
 * 																					    ---
 * 																					     3
 */

#define PortOf7Seg_1	PORTD


void Seven_Segment_Init(void);

void Count_Up(u8 start,u8 end,u8 time);

void Count_Down(u8 start,u8 end,u8 time);

void Display_Number(u8 N);

#endif /* 7SEGMENT_H_ */
