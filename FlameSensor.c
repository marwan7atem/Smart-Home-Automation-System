/*
 * FlameSensor.c
 *
 *  Created on: ٠٨‏/١٠‏/٢٠٢٤
 *      Author: LENOVO
 */
#include"common_macros.h"
#include"gpio.h"
#include"FlameSensor.h"
void FlameSensor_init(void)
{
	GPIO_setupPinDirection(FLAME_SENSOR_PORT_ID,FLAME_SENSOR_PIN_ID,PIN_INPUT);
}
uint8 FlameSensor_getValue(void)
{
	if(!(GPIO_readPin(FLAME_SENSOR_PORT_ID,FLAME_SENSOR_PIN_ID)))
		{
			return LOGIC_LOW;  // Turn off alarm
		}
		else
		{
		return LOGIC_HIGH;  // Turn on alarm
		}
}


