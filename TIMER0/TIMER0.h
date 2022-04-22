/*
 * TIMER0.h
 *
 * Created: 2/16/2022 1:22:09 PM
 *  Author: aaa
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#define NORMAL_MODE				1
#define CTC_MODE				2
#define PHASE_CORRECT_PWM_MODE	3
#define FAST_PWM_MODE			4	

#define NON_INVERTED_MODE	0
#define INVERTED_MODE		1

void TIMER0_INIT(void);

void TIMER0_SET_TIME(u32);

void TIMER0_START(void);

void TIMER0_STOP(void);

void PWM0_INIT(void);

void PWM0_SET_DUTY_CYCLE(u32);

void PWM0_START(void);

void PWM0_STOP(void);

void TIMER0_SET_CALL_BACK(void(*ptr)(void));

#endif /* TIMER0_H_ */