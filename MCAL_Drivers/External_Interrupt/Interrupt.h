/*
 * Interrupt.h
 *
 *  Created on: Dec 27, 2021
 *      Author: aaa
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#define EXT_INT0	0
#define EXT_INT1	1
#define EXT_INT2	2

#define	RISING		0
#define FALLING		1
#define LOW_LEVEL	2
#define	TOGGLING	3

void Interrupt_Init(u8 intrrupt_id,u8 interrupt_mode);

void Interrupt_Enabled(u8 intrrupt_id);

void Interrupt_Disabled(u8 intrrupt_id);

void Enable_General_Interrupt(void);

void Disable_General_Interrupt(void);


#endif /* INTERRUPT_H_ */
