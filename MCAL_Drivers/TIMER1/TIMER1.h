/*
 * TIMER1.h
 *
 * Created: 2/23/2022 9:53:42 AM
 *  Author: aaa
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

#define NORMAL_MODE				1
#define CTC_MODE				2
#define PHASE_CORRECT_PWM_MODE	3
#define FAST_PWM_MODE			4

#define NON_INVERTED_MODE	0
#define INVERTED_MODE		1

void TIMER1_INIT(void);

void TIMER1_SET_TIME(u32);

void TIMER1_START(void);

void TIMER1_STOP(void);

void PWM1_INIT(void);

void PWM1_SET_FREQUANCY(u32);

void PWM1_SET_DUTY_CYCLE(u8);

void PWM1_START(void);

void PWM1_STOP(void);

void TIMER1_SET_CALL_BACK(void(*ptr)(void));



#endif /* TIMER1_H_ */