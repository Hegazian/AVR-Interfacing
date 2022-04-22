/*
 * SPI.c
 *
 * Created: 2/28/2022 12:44:16 PM
 *  Author: aaa
 */ 

#define F_CPU	16000000UL
#include <util/delay.h>
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "SPI.h"
#include "SPI_CFG.h"
#include "SPI_REG.h"
#include "DIO.h"

void SPI_INIT(void)
{
	//to set data transver LSH
	SET_BIT(SPCR_REG,DORD);
	#if SPI_MODE == MASTER
	SET_BIT(SPCR_REG,MSTR);
	PIN_MODE(MISO,INPUT);
	PIN_MODE(MOSI,OUTPUT);
	PIN_MODE(SS,OUTPUT);
	PIN_WRITE(SS,HIGH);
	PIN_MODE(SCK,OUTPUT);
	//choose CPOL Functionality and CPHA Functionality
	SET_BIT(SPCR_REG,CPOL);
	SET_BIT(SPCR_REG,CPHA);
	//set prescalar for clk
	SET_BIT(SPCR_REG,SPR0);
	SET_BIT(SPCR_REG,SPR1);
	CLR_BIT(SPSR_REG,SPI2X);
	_delay_ms(1000);
	#elif SPI_MODE == SLAVE
	CLR_BIT(SPCR_REG,MSTR);
	PIN_MODE(MISO,OUTPUT);
	PIN_MODE(MOSI,INPUT);
	PIN_MODE(SS,INPUT);
	PIN_MODE(SCK,INPUT);
	//choose CPOL Functionality and CPHA Functionality
	SET_BIT(SPCR_REG,CPOL);
	SET_BIT(SPCR_REG,CPHA);
	#endif
	//enable spi circuit
	SET_BIT(SPCR_REG,SPE);
}


u8 SPI_TRANSIVE(u8 data)
{
	#if SPI_MODE == MASTER
	PIN_WRITE(SS,LOW);
	SPDR_REG = data;
	while(GET_BIT(SPSR_REG,SPIF) == 0);
	PIN_WRITE(SS,HIGH);
	#elif SPI_MODE == SLAVE
	SPDR_REG = data;
	while(GET_BIT(SPSR_REG,SPIF) == 0);
	#endif
	return SPDR_REG;
}