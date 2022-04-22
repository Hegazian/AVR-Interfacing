/*
 * CFile1.c
 *
 * Created: 2/23/2022 9:53:17 AM
 *  Author: aaa
 */ 

#include "DIO_Reg.h"
#include "BIT_MATH.h"
#include "STD_Types.h"
#include "TIMER1.h"
#include "TIMER1_CFG.h"
#include "TIMER1_REG.h"
#include <avr/interrupt.h>

u32 num_of_cm_timer1 = 0;
static u32  num_of_ovf = 0;
static u32  total_ticks = 0;
void (*TIMER1_CALL_BACK)(void);

void TIMER1_INIT(void)
{
	//SET_BIT(DDRD_REG,5);
	//to select CTC mode
	CLR_BIT(TCCR1A_REG,WGM10);
	CLR_BIT(TCCR1A_REG,WGM11);
	SET_BIT(TCCR1B_REG,WGM12);
	CLR_BIT(TCCR1B_REG,WGM13);
	
	//to select non-inverted mode
	CLR_BIT(TCCR1A_REG,COM1A0);
	SET_BIT(TCCR1A_REG,COM1A1);
	
	//enable ctc interrupt
	SET_BIT(TIMSK_REG,OCIE1A); 
	//to enable Global Interrupt
	SET_BIT(SREG_REG,GIE);
}

void TIMER1_SET_TIME(u32 desired_time)
{
	u32 tick_time = (TIMER1_PRESCALAR/CRYSTAL_FREQ);
	total_ticks   = ((desired_time*1000)/tick_time);
	u16 ocr_value = 0xFFFF ;
	while(total_ticks%ocr_value != 0)
	{
		ocr_value--;
	}
	num_of_cm_timer1 = total_ticks/ocr_value;
	OCRA1_REG = ocr_value - 1;
}

void TIMER1_START(void)
{
	SET_BIT(TCCR1B_REG,CS10);
	CLR_BIT(TCCR1B_REG,CS11);
	SET_BIT(TCCR1B_REG,CS12);
}

void TIMER1_STOP(void)
{
	CLR_BIT(TCCR1B_REG,CS10);
	CLR_BIT(TCCR1B_REG,CS11);
	CLR_BIT(TCCR1B_REG,CS12);
}

void TIMER1_SET_CALL_BACK(void(*ptr)(void))
{
	TIMER1_CALL_BACK = ptr ;
}

ISR(TIMER1_COMPA_vect)
{
	static u32 counter = 0;
	counter++;
	if(counter == num_of_cm_timer1)
	{
		TIMER1_CALL_BACK();
		counter = 0;
	}
}

void PWM1_INIT(void)
{
	SET_BIT(DDRD_REG,5);
	//to select fast pwm mode
	CLR_BIT(TCCR1A_REG,WGM10);
	SET_BIT(TCCR1A_REG,WGM11);
	SET_BIT(TCCR1B_REG,WGM11);
	SET_BIT(TCCR1B_REG,WGM11);
	
	//to select non-inverted mode
	CLR_BIT(TCCR1A_REG,COM1A0);
	SET_BIT(TCCR1A_REG,COM1A1);
}

void PWM1_SET_FREQUANCY(u32 frequancy)
{
	ICR1_REG = ((CRYSTAL_FREQ*1000000)/TIMER1_PRESCALAR)*frequancy;
}

void PWM1_SET_DUTY_CYCLE(u8 duty_cycle)
{  
	OCRA1_REG =(((312*(u32)duty_cycle)/100)-1);
}

void PWM1_START(void)
{
	SET_BIT(TCCR1B_REG,CS10);
	CLR_BIT(TCCR1B_REG,CS11);
	SET_BIT(TCCR1B_REG,CS12);	
}

void PWM1_STOP(void)
{
	CLR_BIT(TCCR1B_REG,CS10);
	CLR_BIT(TCCR1B_REG,CS11);
	CLR_BIT(TCCR1B_REG,CS12);
}