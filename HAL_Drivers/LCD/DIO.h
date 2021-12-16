/*
 * DIO.h
 *
 *  Created on: Dec 5, 2021
 *      Author: aaa
 */

#ifndef DIO_H_
#define DIO_H_



/***************************************************************************/
/**************************public Macros********************************/
/**************************************************************************/
/*Value States*/
#define HIGH	1
#define LOW		0

/*Mode States*/
#define INPUT	0
#define OUTPUT	1

/*PORTS ID*/
#define PORTA	0
#define PORTB	1
#define PORTC	2
#define PORTD	3

/*PINS ID*/
#define PIN0	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7

/***************************************************************************/
/**************************public functions********************************/
/**************************************************************************/

/* This function is used to set Mode (direction)[INPUT/OUTPUT] of a particular pin in particular port*/
/*this function return void(Nothing) and take 3 inputs (arguments)  1-The Number of pin in Port(0-7)
 * 																	2-Port ID(PORTA-PORTB-PORTC-PORTD)
 * 																	3-Pin Mode[INPUT/OUTPUT]*/
void SetPinMode(u8 PinId,u8 PortId,u8 PinMode);

/* This function is used to set Value [HIGH(1)/LOW(0)] of a particular pin in particular port*/
/*this function return void(Nothing) and take 3 inputs (arguments)  1-The Number of pin in Port(0-7)
 * 																	2-Port ID(PORTA-PORTB-PORTC-PORTD)
 * 																	3-Pin Value[HIGH(1)/LOW(0)]*/
void SetPinValue(u8 PinId,u8 PortId,u8 PinValue);

/* This function is used to set Mode (direction)[INPUT/OUTPUT] of a particular port(All pins in port)*/
/*this function return void(Nothing) and take 2 inputs (arguments)  1-Port ID(PORTA-PORTB-PORTC-PORTD)
 * 																	2-port Mode[INPUT/OUTPUT]*/
void SetPortMode(u8 PortId,u8 PortMode);

/* This function is used to set Value [HIGH(1)/LOW(0)] of a particular port(All pins in port)*/
/*this function return void(Nothing) and take 2 inputs (arguments)  1-Port ID(PORTA-PORTB-PORTC-PORTD)
 * 																	2-port Value[HIGH(1)/LOW(0)]*/
void SetPortValue(u8 PortId,u8 PortValue);

/* This function is used to GET The Value of a particular pin in particular port [HIGH(1)/LOW(0)]*/
/*this function return u8 (The Value of The Pin) and take 2 inputs (arguments)  1-Pin ID(PIN0......PIN7)
 * 																				2-Port ID(PORTA-PORTB-PORTC-PORTD)*/
u8 GetPinValue(u8 PinId,u8 PortId);



#endif /* DIO_H_ */
