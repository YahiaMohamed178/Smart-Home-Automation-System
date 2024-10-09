/*
 * ldr.c
 *
 *  Created on: Oct 7, 2024
 *      Author: Yahia
 */

#include "ldr.h"
#include "adc.h"

/*
 * Description :
 * Function responsible for reading the sensor value and returning the light intensity
 */
uint16 LDR_getLightIntensity(void){

	uint16 temp_value = 0;

	uint16 adc_value = 0;

	/* Read ADC channel where the ldr sensor is connected */
	adc_value = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

	/* Calculate the light intensity from the ADC value*/
	temp_value = (uint16)(((uint32)adc_value*LDR_SENSOR_MAX_LIGHT_INTENSITY*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*LDR_SENSOR_MAX_VOLT_VALUE));

	return temp_value;

}
