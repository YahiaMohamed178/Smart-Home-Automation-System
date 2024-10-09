/*
 * flame_sensor.c
 *
 *  Created on: Oct 7, 2024
 *      Author: Yahia
 */

#include "flame_sensor.h"
#include "gpio.h"

/*******************************************************************************
 *                             Functions Definitions                           *
 *******************************************************************************/

/*
 * Description :
 * function responsible for initializing the flame sensor pin direction
 */
void FlameSensor_init(void){
	 GPIO_setupPinDirection(FLAME_SENSOR_PORT_ID, FLAME_SENSOR_PIN_ID, PIN_INPUT);
}

/*
 * Description :
 * function responsible for reading the value from the flame sensor
 */
uint8 FlameSensor_getValue(void){
	return GPIO_readPin(FLAME_SENSOR_PORT_ID, FLAME_SENSOR_PIN_ID);
}

