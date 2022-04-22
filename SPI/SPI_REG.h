/*
 * SPI_REG.h
 *
 * Created: 2/28/2022 12:43:58 PM
 *  Author: aaa
 */ 


#ifndef SPI_REG_H_
#define SPI_REG_H_


#define SPCR_REG	(*((volatile u8*)0x2D))
#define SPIE	7
#define SPE		6
#define DORD	5
#define MSTR	4
#define CPOL	3
#define CPHA	2
#define SPR1	1
#define SPR0	0 

#define SPSR_REG	 (*((volatile u8*)0x2E))
#define SPIF	7
#define WCOL	6
#define SPI2X	0


#define SPDR_REG	(*((volatile u8*)0x2F))


#endif /* SPI_REG_H_ */