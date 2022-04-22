/*
 * WDT_REG.h
 *
 * Created: 2/20/2022 1:10:10 PM
 *  Author: aaa
 */ 


#ifndef WDT_REG_H_
#define WDT_REG_H_


#define WDTCR_REG	*((volatile u8*)0x41)
#define WDTOE	4
#define WDE		3
#define WDP2	2
#define WDP1	1
#define WDP0	0

#define MCUCSR_REG	*((volatile u8*)0x54)

#endif /* WDT_REG_H_ */