/*
 * Interrupt_reg.h
 *
 *  Created on: Dec 26, 2021
 *      Author: aaa
 */

#ifndef INTERRUPT_REG_H_
#define INTERRUPT_REG_H_


#define MCUCR_REG	*((volatile u8*)0x55)	//The MCU Control Register contains control bits for interrupt sense control and general MCU functions.
#define SREG_REG	*((volatile u8*)0x5F)	//The AVR Status Register – SREG(it has Bit No.7 as Global Interrupt Enable)
#define GICR_REG	*((volatile u8*)0x5B)	//General Interrupt Control Register – GICR
#define GIFR_REG	*((volatile u8*)0x5A)	//General Interrupt Flag Register – GIFR
#define MCUCSR_REG	*((volatile u8*)0x54)

//this bit is The Global Interrupt Enable bit in MCUCSR register
#define GIE		7
//this two bits are The Interrupt Sense Control for INT0 in MCURC register
#define ISC00	0
#define ISC01	1
//this two bits are The Interrupt Sense Control for INT1 in MCURC register
#define ISC10	2
#define ISC11	3
//this bit is The Interrupt Sense Control for INT2 in MCUCSR register
#define ISC2	6
//this three bits are responsible about enable INT0,INT1,INT2 in General Interrupt Control Register GICR
#define INT0_EN	6
#define INT1_EN	7
#define INT2_EN	5


#endif /* INTERRUPT_REG_H_ */
