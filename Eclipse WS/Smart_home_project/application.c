/*
 * application.c
 *
 *  Created on: Oct 6, 2024
 *      Author: Yahia
 */

#include "lcd.h"
#include "led.h"
#include "buzzer.h"
#include "dc_motor.h"
#include "flame_sensor.h"
#include "lm35_sensor.h"
#include "ldr.h"
#include "adc.h"
#include <util/delay.h>


uint8 prev_fan_state=0;
uint8 current_fan_state=0;
uint8 prev_flame=0;

/*******************************************************************************
 *                        Application Functions                                 *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for controlling the smart home lighting
 */
void lightingControl(uint16 intensity){
	if(intensity <15){
		LED_on(RED_LED);
		LED_on(GREEN_LED);
		LED_on(BLUE_LED);
	}
	else if(intensity >=15 && intensity <=50){
		LED_on(RED_LED);
		LED_on(GREEN_LED);
		LED_off(BLUE_LED);
	}
	else if(intensity >50 && intensity <=70){
		LED_on(RED_LED);
		LED_off(GREEN_LED);
		LED_off(BLUE_LED);
	}
	else{
		LED_off(RED_LED);
		LED_off(GREEN_LED);
		LED_off(BLUE_LED);
	}
}

/*
 * Description :
 * Function responsible for controlling fan speed
 */
void fanSpeedControl(uint8 temp){
	if(temp>=40){
		DcMotor_Rotate(CLOCKWISE, 100);
		current_fan_state=1;
	}
	else if(temp>=35){
		DcMotor_Rotate(CLOCKWISE, 75);
		current_fan_state=1;
	}
	else if(temp>=30){
		DcMotor_Rotate(CLOCKWISE, 50);
		current_fan_state=1;
	}
	else if(temp>=25){
		DcMotor_Rotate(CLOCKWISE, 25);
		current_fan_state=1;
	}
	else{
		DcMotor_Rotate(STOP, 0);
		current_fan_state=0;
	}



	if(current_fan_state!=prev_fan_state ){
		if(current_fan_state==1){
			LCD_clearScreen();
			LCD_displayStringRowColumn(0,0,"FAN is ON");
		}
		else{
			LCD_clearScreen();
			LCD_displayStringRowColumn(0,0,"FAN is OFF");
		}
	}

	prev_fan_state=current_fan_state;

}

/*
 * Description :
 * Function responsible for fire detection and alert
 */
void fireDetector(uint8 flame){
	if(flame!=prev_flame){
		if(flame){
			Buzzer_on();
			LCD_clearScreen();
			LCD_displayStringRowColumn(0,0,"CRITICAL ALERT!!");
		}
		else{
			Buzzer_off();
			LCD_clearScreen();
			prev_fan_state=!(current_fan_state);
		}
		prev_flame=flame;
		_delay_ms(50);
	}

}
int main(void){

	/*******************************************************************************
	 *                                Local Variables                              *
	 *******************************************************************************/

	uint8 flame_detected=0;
	uint8 temperature=0;
	uint16 light_intensity=0;

	/*******************************************************************************
	 *                                Drivers Initialization                       *
	 *******************************************************************************/

	LCD_init();
	LEDS_init();
	Buzzer_init();
	DcMotor_Init();
	FlameSensor_init();
	ADC_init();

	/************** Initial Display *************/
	LCD_clearScreen();
	LCD_displayStringRowColumn(0,0,"FAN is OFF");

	while(1){

		flame_detected = FlameSensor_getValue();
		temperature = LM35_getTemperature();
		light_intensity = LDR_getLightIntensity();

		fireDetector(flame_detected);
		if(flame_detected){
			continue;                                    /*****stop displaying until fire is off*******/
		}
		lightingControl(light_intensity);
		fanSpeedControl(temperature);

		LCD_displayStringRowColumn(1,0,"Temp=");
		LCD_intgerToString(temperature);
		LCD_displayString("C LDR=");
		LCD_intgerToString(light_intensity);
		LCD_displayString("% ");

		_delay_ms(50);
	}

	return 0;
}
