/*
 * UART.h
 *
 * Created: 2/28/2022 9:20:50 AM
 *  Author: aaa
 */ 


#ifndef UART_H_
#define UART_H_


#define ODD		0
#define EVEN	1
#define NON		2

void UART_INIT(void);

void UART_SEND(u8);

u8 UART_RECEIVE(void);


#endif /* UART_H_ */