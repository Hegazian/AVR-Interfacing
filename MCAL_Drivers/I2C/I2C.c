/*
 * I2C.c
 *
 * Created: 3/1/2022 10:00:04 AM
 *  Author: aaa
 */ 

#include "STD_Types.h"
#include "I2C.h"
#include "I2C_REG.h"
#include "I2C_CFG.h"
void I2C_INIT(void)
{
	#if I2C_MODE == MASTER
	//set scl frequency
	TWBR = (((CRYSTAL_FREQ*1000)/SCL_FREQ)-16)/2;
	
	#elif I2C_MODE == SLAVE
	TWAR = (SLAVE_ADDRESS << 1);
	#endif
	SET_BIT(TWCR,2);
}

void I2C_START_COND(void)
{
	SET_BIT(TWCR,7);
	SET_BIT(TWCR,5);
	while(GET_BIT(TWCR,7) == 0);
	while((TWSR & 0xF8) != 0x08);
}

void I2C_STOP_COND(void)
{
	SET_BIT(TWCR,7);
	SET_BIT(TWCR,4);
	while(GET_BIT(TWCR,7) == 0);
}

void I2C_REPEAT_START(void)
{
	SET_BIT(TWCR,7);
	SET_BIT(TWCR,5);
	while(GET_BIT(TWCR,7) == 0);
	while((TWSR & 0xF8) != 0x10);
}

void I2C_SEND_SLAVE_ADD_WRITE(u8 address)
{
	SET_BIT(TWCR,7);
	TWDR = (address << 1);
	while(GET_BIT(TWCR,7) == 0);
	while((TWSR & 0xF8) != 0x18);
}

void I2C_SEND_SLAVE_ADD_READ(u8 address)
{
	SET_BIT(TWCR,7);
	TWDR = (address << 1)|1;
	while(GET_BIT(TWCR,7) == 0);
	while((TWSR & 0xF8) != 0x40);
}

void I2C_SEND_BYTE(u8 byte)
{
	SET_BIT(TWCR,7);
	TWDR = byte;	
	while(GET_BIT(TWCR,7) == 0);
	while((TWSR & 0xF8) != 0x28);
}

u8 I2C_READ_BYTE(void)
{
	SET_BIT(TWCR,7);
	while(GET_BIT(TWCR,7) == 0);
	while((TWSR & 0xF8) != 0x50);
	return TWDR;
}



