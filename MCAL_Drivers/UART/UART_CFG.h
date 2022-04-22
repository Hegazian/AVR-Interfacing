/*
 * UART_CFG.h
 *
 * Created: 2/28/2022 9:21:21 AM
 *  Author: aaa
 */ 


#ifndef UART_CFG_H_
#define UART_CFG_H_

//CHARACTER_SIZE options ->[5, 6, 7, 8, 9]
#define CHARACTER_SIZE		8

//PARITY_CHECK options ->[ODD, EVEN, NON]
#define PARITY_CHECK		NON

//STOP_BIT options ->[1, 2]
#define STOP_BIT			1

//BAUD_RATE options ->[9600, 115200, 38400]
#define BAUD_RATE		9600


#endif /* UART_CFG_H_ */