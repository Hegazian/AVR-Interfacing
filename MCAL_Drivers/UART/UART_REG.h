/*
 * UART_REG.h
 *
 * Created: 2/28/2022 9:21:06 AM
 *  Author: aaa
 */ 


#ifndef UART_REG_H_
#define UART_REG_H_

#define UCSRA_REG	(*((volatile u8*)0x2B))

#define UCSRB_REG	(*((volatile u8*)0x2A))

#define UCSRC_REG	(*((volatile u8*)0x40))

#define UDR_REG		(*((volatile u8*)0x2C))

#define UBRRL_REG	(*((volatile u8*)0x29))

#define UBRRH_REG	(*((volatile u8*)0x40))


//UBRRH,UCSRC
#endif /* UART_REG_H_ */