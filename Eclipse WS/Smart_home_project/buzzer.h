/*
 * buzzer.h
 *
 *  Created on: Oct 7, 2024
 *      Author: Yahia
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define BUZZER_PORT_ID        PORTD_ID
#define BUZZER_PIN_ID         PIN3_ID

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * function responsible for initializing the buzzer pin direction and set it off
 */
void Buzzer_init(void);

/*
 * Description :
 * function responsible for activating the buzzer
 */
void Buzzer_on(void);

/*
 * Description :
 * function responsible for deactivating the buzzer
 */
void Buzzer_off(void);


#endif /* BUZZER_H_ */
