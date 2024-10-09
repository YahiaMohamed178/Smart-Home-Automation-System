/*
 * dc_motor.h
 *
 *  Created on: Oct 7, 2024
 *      Author: Yahia
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define MOTOR_EN1_PORT_ID              PORTB_ID
#define MOTOR_EN1_PIN_ID               PIN3_ID

#define MOTOR_IN1_PORT_ID              PORTB_ID
#define MOTOR_IN1_PIN_ID               PIN0_ID

#define MOTOR_IN2_PORT_ID              PORTB_ID
#define MOTOR_IN2_PIN_ID               PIN1_ID


/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum{
	CLOCKWISE,ANTI_CLOCKWISE,STOP
}DcMotor_State;


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * function responsible for setting motor pins direction & initializing the dc motor as stop
 */
void DcMotor_Init(void);

/*
 * Description :
 * function responsible for controlling the motor state and speed
 */
void DcMotor_Rotate(DcMotor_State state, uint8 speed);

#endif /* DC_MOTOR_H_ */
