/*
 * dc_motor.c
 *
 *  Created on: Oct 7, 2024
 *      Author: Yahia
 */

#include "dc_motor.h"
#include "gpio.h"
#include "pwm.h"

/*******************************************************************************
 *                             Functions Definitions                           *
 *******************************************************************************/

/*
 * Description :
 * function responsible for setting motor pins direction & initializing the dc motor as stop
 */
void DcMotor_Init(void){
	GPIO_setupPinDirection(MOTOR_IN1_PORT_ID, MOTOR_IN1_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_IN2_PORT_ID, MOTOR_IN2_PIN_ID, PIN_OUTPUT);

	GPIO_writePin(MOTOR_IN1_PORT_ID, MOTOR_IN1_PIN_ID, LOGIC_LOW);
	GPIO_writePin(MOTOR_IN2_PORT_ID, MOTOR_IN2_PIN_ID, LOGIC_LOW);

}

/*
 * Description :
 * function responsible for controlling the motor state and speed
 */
void DcMotor_Rotate(DcMotor_State state, uint8 speed){
	switch(state){

	case CLOCKWISE:
		GPIO_writePin(MOTOR_IN1_PORT_ID, MOTOR_IN1_PIN_ID, LOGIC_HIGH);
		GPIO_writePin(MOTOR_IN2_PORT_ID, MOTOR_IN2_PIN_ID, LOGIC_LOW);
		break;

	case ANTI_CLOCKWISE:
		GPIO_writePin(MOTOR_IN1_PORT_ID, MOTOR_IN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(MOTOR_IN2_PORT_ID, MOTOR_IN2_PIN_ID, LOGIC_HIGH);
		break;

	case STOP:
		GPIO_writePin(MOTOR_IN1_PORT_ID, MOTOR_IN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(MOTOR_IN2_PORT_ID, MOTOR_IN2_PIN_ID, LOGIC_LOW);
		break;
	}

	PWM_Timer0_Start(speed);
}
