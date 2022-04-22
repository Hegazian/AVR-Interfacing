/*
 * I2C.h
 *
 * Created: 3/1/2022 10:00:22 AM
 *  Author: aaa
 */ 


#ifndef I2C_H_
#define I2C_H_


void I2C_INIT(void);

void I2C_START_COND(void);

void I2C_STOP_COND(void);

void I2C_REPEAT_START(void);

void I2C_SEND_SLAVE_ADD_WRITE(u8);

void I2C_SEND_SLAVE_ADD_READ(u8);

void I2C_SEND_BYTE(u8);

u8 I2C_READ_BYTE(void);

#endif /* I2C_H_ */