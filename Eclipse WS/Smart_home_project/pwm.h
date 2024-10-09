/*
 * pwm.h
 *
 *  Created on: Oct 6, 2024
 *      Author: Yahia
 */

#ifndef PWM_H_
#define PWM_H_

#include "std_types.h"


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initializing Timer0 in PWM mode
 */
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_H_ */
