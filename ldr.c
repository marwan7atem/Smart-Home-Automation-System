/*
 * ldr.c
 *
 *  Created on: ٠٨‏/١٠‏/٢٠٢٤
 *      Author: LENOVO
 */
#include<avr/io.h>
#include<util/delay.h>
#include"common_macros.h"
#include"gpio.h"
#include"adc.h"
#include"ldr.h"

// function Reads the LDR sensor value and returns the light intensity.

uint16 LDR_getLightIntensity(void)
{
	uint16 adcValue =0;
	uint16 lightIntensity =0;

	adcValue = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);
    float64 sensorVoltage = (adcValue * ADC_REF_VOLT_VALUE) / ADC_MAXIMUM_VALUE;
    lightIntensity = (uint16)(sensorVoltage * LDR_SENSOR_MAX_LIGHT_INTENSITY / LDR_SENSOR_MAX_VOLT_VALUE);

    if (lightIntensity > LDR_SENSOR_MAX_LIGHT_INTENSITY) {
        lightIntensity = LDR_SENSOR_MAX_LIGHT_INTENSITY;
    }

    return lightIntensity;
}


