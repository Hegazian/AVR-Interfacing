/*
 * UART.c
 *
 * Created: 2/28/2022 9:20:33 AM
 *  Author: aaa
 */ 

#include "BIT_MATH.h"
#include "STD_Types.h"
#include "UART.h"
#include "DIO_Reg.h"
#include "UART_REG.h"
#include "UART_CFG.h"

void UART_INIT(void)
{
	//select UCSRC
	u8 UCSRC_value = 0b10000000;
	//to select PD1 (Tx) ->OUTPUT
	SET_BIT(DDRD_REG,1);
	//to select PD0 (Rx) ->INPUT
	CLR_BIT(DDRD_REG,0);
	
	#if CHARACTER_SIZE == 8
	SET_BIT(UCSRC_value,1);
	SET_BIT(UCSRC_value,2);
	CLR_BIT(UCSRB_REG,2);
	#elif CHARACTER_SIZE == 7
	
	#elif CHARACTER_SIZE == 6
		
	#elif CHARACTER_SIZE == 5
	#endif
		
	#if PARITY_CHECK == ODD
	SET_BIT(UCSRC_value,4);
	SET_BIT(UCSRC_value,5);
	#elif PARITY_CHECK == EVEN
	
	#elif PARITY_CHECK == NON
	#endif
		
	#if STOP_BIT == 1
	
	#elif STOP_BIT == 2
	SET_BIT(UCSRC_value,3);		
	#endif
	
	#if BAUD_RATE == 9600
	//to select baud rate 9600
	UBRRL_REG = 103;
	#elif BAUD_RATE == 115200
	//UBRRL = 
	#elif BAUD_RATE == 38400
	//UBRRL = 
	#endif
	
	//set configrations to UCSRC Register
	UCSRC_REG = UCSRC_value;
	
	//to enable Tx
	SET_BIT(UCSRB_REG,4);
	//to enable Rx
	SET_BIT(UCSRB_REG,3);
}

void UART_SEND(u8 data)
{
	UDR_REG = data;
	//check transmitter flag
	while(GET_BIT(UCSRA_REG,6)==0);
}

u8 UART_RECEIVE(void)
{
	//check reciever flag
	while(GET_BIT(UCSRA_REG,7)==0);
	return UDR_REG;
}