/*
 * flame_sensor.h
 *
 *  Created on: Oct 7, 2024
 *      Author: Yahia
 */

#ifndef FLAME_SENSOR_H_
#define FLAME_SENSOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define FLAME_SENSOR_PORT_ID        PORTD_ID
#define FLAME_SENSOR_PIN_ID         PIN2_ID

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * function responsible for initializing the flame sensor pin direction
 */
void FlameSensor_init(void);

/*
 * Description :
 * function responsible for reading the value from the flame sensor
 */
uint8 FlameSensor_getValue(void);

#endif /* FLAME_SENSOR_H_ */
