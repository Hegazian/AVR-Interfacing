/*
 * TIMER0.c
 *
 * Created: 2/16/2022 1:21:50 PM
 *  Author: aaa
 */ 

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "TIMER0_CFG.h"
#include "TIMER0.h"
#include "TIMER0_REG.h"
#include "avr/interrupt.h"
#include "LED.h"
#include "DIO.h"

u32 num_of_cm = 0;
static u32  num_of_ovf = 0;
static u32  total_ticks = 0;
void (*TIMER0_CALL_BACK)(void);


void TIMER0_INIT(void)
{
	#if TIMER0_MODE	== NORMAL_MODE
	//to select Normal Mode
	CLR_BIT(TCCR0_REG,WGM00);
	CLR_BIT(TCCR0_REG,WGM01);
	//to enable TIMER0 Interrupt
	SET_BIT(TIMSK_REG,0);
	#elif TIMER0_MODE == CTC_MODE
	CLR_BIT(TCCR0_REG,WGM00);
	SET_BIT(TCCR0_REG,WGM01);
	//to enable TIMER0 Interrupt
	SET_BIT(TIMSK_REG,1);
	#endif
	//to enable Global Interrupt
	SET_BIT(SREG_REG,GIE);
	
}

void TIMER0_SET_TIME(u32 desired_time)
{
	u32 tick_time = (TIMER0_PRESCALAR/CRYSTAL_FREQ);
	total_ticks   = ((desired_time*1000)/tick_time); 
	#if TIMER0_MODE == NORMAL_MODE
	num_of_ovf = total_ticks/256;
	if(total_ticks%256 !=0)
	{
		TCNT0_REG = (256 - (total_ticks%256));
		num_of_ovf++;
	}
	#elif TIMER0_MODE == CTC_MODE
	u8 ocr_value = 255 ;
	while(total_ticks%ocr_value != 0)
	{
		ocr_value--;
	}
	num_of_cm = total_ticks/ocr_value;
	OCR0_REG = ocr_value-1;
	#endif
}

void TIMER0_START(void)
{
	SET_BIT(TCCR0_REG,CS00);
	CLR_BIT(TCCR0_REG,CS01);
	SET_BIT(TCCR0_REG,CS02);
}

void TIMER0_STOP(void)
{
	CLR_BIT(TCCR0_REG,CS00);
	CLR_BIT(TCCR0_REG,CS01);
	CLR_BIT(TCCR0_REG,CS02);
}

void PWM0_INIT(void)
{
	//set pwm pin to be output
	PIN_MODE(23,OUTPUT);
	#if PWM0_MODE == FAST_PWM_MODE
	//select fast pwm mode
	SET_BIT(TCCR0_REG,WGM00);
	SET_BIT(TCCR0_REG,WGM01);
	#elif PWM0_MODE == PHASE_CORRECT_PWM_MODE
	SET_BIT(TCCR0_REG,WGM00);
	CLR_BIT(TCCR0_REG,WGM01);
	#endif
	#if COMPARE_OUTPUT_MODE == INVERTED_MODE
	//select inverted mode
	SET_BIT(TCCR0_REG,COM00);
	SET_BIT(TCCR0_REG,COM01);
	#elif COMPARE_OUTPUT_MODE == NON_INVERTED_MODE
	//select non-inverted mode
	CLR_BIT(TCCR0_REG,COM00);
	SET_BIT(TCCR0_REG,COM01);
	#endif
}

void PWM0_SET_DUTY_CYCLE(u32 duty_cycle)
{	
	#if COMPARE_OUTPUT_MODE == INVERTED_MODE
		#if PWM0_MODE == FAST_PWM_MODE
		OCR0_REG = 255 - ((duty_cycle*256)/100);
		#elif PWM0_MODE == PHASE_CORRECT_PWM_MODE
		OCR0_REG = 255 - ((255*duty_cycle)/100);
		#endif
	#elif COMPARE_OUTPUT_MODE == NON_INVERTED_MODE
		#if PWM0_MODE == FAST_PWM_MODE
		OCR0_REG = (((256*duty_cycle)/100))-1;
		#elif PWM0_MODE == PHASE_CORRECT_PWM_MODE
		OCR0_REG = (255*duty_cycle)/100;
		#endif
	#endif
}

void PWM0_START(void)
{
	TIMER0_START();
}

void PWM0_STOP(void)
{
	TIMER0_STOP();
}

void TIMER0_SET_CALL_BACK(void(*ptr)(void))
{
	TIMER0_CALL_BACK = ptr ;
}

ISR(TIMER0_COMP_vect)
{
	static u32 counter = 0;
	counter++;
	if(counter == num_of_cm)
	{
		TIMER0_CALL_BACK();
		counter = 0;
	}
}

ISR(TIMER0_OVF_vect)
{
	static u32 counter = 0;
	counter++;
	if(counter == num_of_ovf)
	{
		TIMER0_CALL_BACK();
		counter = 0;
		TCNT0_REG = 256 - (total_ticks%256);
	}	
}