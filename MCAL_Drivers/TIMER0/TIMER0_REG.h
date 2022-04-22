/*
 * TIMER0_REG.h
 *
 * Created: 2/16/2022 1:23:39 PM
 *  Author: aaa
 */ 


#ifndef TIMER0_REG_H_
#define TIMER0_REG_H_

//address of TCCR0 Register
#define TCCR0_REG	*((volatile u8*)0x53)
//TCCR0 PINS
#define  CS00	0
#define  CS01	1
#define  CS02	2
#define  WGM01	3
#define  COM00  4
#define  COM01	5
#define  WGM00	6
#define  FOC0	7

//address of SERG register
#define SREG_REG	*((volatile u8*)0x5F)	//The AVR Status Register – SREG(it has Bit No.7 as Global Interrupt Enable)
//SERG PINS
//this bit is The Global Interrupt Enable bit in SERG register
#define GIE		7

//address TIMSK register
#define TIMSK_REG	*((volatile u8*)0x59)
//TIMSK PINS


//address of TCNT0
#define TCNT0_REG	*((volatile u8*)0x52)

//address of OCR0
#define OCR0_REG	*((volatile u8*)0x5c)

#endif /* TIMER0_REG_H_ */