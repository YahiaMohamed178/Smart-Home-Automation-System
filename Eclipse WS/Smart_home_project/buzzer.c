/*
 * buzzer.c
 *
 *  Created on: Oct 7, 2024
 *      Author: Yahia
 */

#include "buzzer.h"
#include "gpio.h"

/*******************************************************************************
 *                             Functions Definitions                           *
 *******************************************************************************/

/*
 * Description :
 * function responsible for initializing the buzzer pin direction and set it off
 */
void Buzzer_init(void){

	GPIO_setupPinDirection(BUZZER_PORT_ID, BUZZER_PIN_ID, PIN_OUTPUT);

	GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_LOW);
}

/*
 * Description :
 * function responsible for activating the buzzer
 */
void Buzzer_on(void){

	GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_HIGH);

}

/*
 * Description :
 * function responsible for deactivating the buzzer
 */
void Buzzer_off(void){

	GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_LOW);
}
