/*
 * ADC_config.h
 *
 *  Created on: Jan 8, 2022
 *      Author: aaa
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/*Select ADC Voltage Reference
 * Range: ADC_VCC / ADC_INTRNAL_VREF / ADC_EXTRNAL_VREF*/
#define ADC_VREF	ADC_EXTRNAL_VREF

/*Select ADC Adjust Result
 * Range: ADC_RIGHT / ADC_LEFT*/
#define ADC_ADJUST	ADC_RIGHT

/*Select ADC Prescaler
 * Range: DivisionFactorBy2 / DivisionFactorBy4/ DivisionFactorBy8 / DivisionFactorBy16 / DivisionFactorBy32
 * 		  DivisionFactorBy64 / DivisionFactorBy128*/
#define	ADC_PRESCALER	DivisionFactorBy128

#endif /* ADC_CONFIG_H_ */
