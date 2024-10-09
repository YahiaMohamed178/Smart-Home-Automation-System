/*
 * pwm.c
 *
 *  Created on: Oct 6, 2024
 *      Author: Yahia
 */

#include <avr/io.h>
#include "pwm.h"
#include "common_macros.h"
#include "gpio.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void PWM_Timer0_Start(uint8 duty_cycle){

	/******** set OC0(PB3) as output pin **********/
	GPIO_setupPinDirection(PORTB_ID, PIN3_ID, PIN_OUTPUT);
	/******* initialize Timer0 *********/
	TCNT0 =0;
	/*TCCR0 register bits description:
	 * FOC0 = 0 for PWM mode
	 * WGM01:0 = 11 for fast PWM
	 * COM01:0 = 10 FOR NON-INVERTING mode
	 * CS02:0 = 101 FOR clk/1024 prescaler
	 */
	TCCR0 = (1<<WGM01) | (1<<WGM00) | (1<<COM01) | (1<<CS02) | (1<<CS00);
	/* OCR0 register to set the duty cycle
	 * since it is a percentage we will multiply by 255(8-bit) then divide by 100
	 */
	OCR0 = (duty_cycle *255)/100;
}
