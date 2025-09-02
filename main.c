/*
 * main.c
 *
 *  Created on: ٠٦‏/١٠‏/٢٠٢٤
 *      Author: LENOVO
 */
#include "adc.h"
#include "buzzer.h"
#include "dc_motor.h"
#include "flameSensor.h"
#include "lcd.h"
#include "ldr.h"
#include "led.h"
#include "lm35_sensor.h"
#include "pwm.h"
#include "gpio.h"
#include <avr/io.h>
#include <util/delay.h>

int main()
{
	uint16 Intensity;
	uint8 temp;
	uint8 motorSpeed = 0;
	char* motorState = "OFF";
	uint8 fireAlertActive = 0;

	// Initialization
	LCD_init();
	LEDS_init();
	DcMotor_Init();
	FlameSensor_init();
	Buzzer_init();
	GPIO_setupPinDirection(PORTA, PIN0, PIN_INPUT);
	GPIO_setupPinDirection(PORTA, PIN1, PIN_INPUT);
	ADC_init();
	// Initial LCD setup
	DcMotor_Rotate(OFF, 0);
	LCD_moveCursor(0, 3);
	LCD_displayString("FAN IS");
	LCD_moveCursor(1, 0);
	LCD_displayString("TEMP=");
	LCD_moveCursor(1, 8);
	LCD_displayString("LDR=   %");

	while (1)
	{

		if (FlameSensor_getValue())
		{

			if (!fireAlertActive)
			{
				LCD_clearScreen();  // Clear LCD to show the alert
				LCD_moveCursor(0, 0);
				LCD_displayString("Critical alert! ");
				Buzzer_on();
				fireAlertActive = 1;
			}
			continue;
		}
		else if (fireAlertActive)
		{
			// Clear the fire alert and reset the displa
			fireAlertActive = 0;
			LCD_clearScreen();
			LCD_moveCursor(0, 3);
			LCD_displayString("FAN IS");
			LCD_moveCursor(1, 0);
			LCD_displayString("TEMP=");
			LCD_moveCursor(1, 8);
			LCD_displayString("LDR=   %");
			Buzzer_off();
		}

		// Light Intensity Control based on LDR
		Intensity = LDR_getLightIntensity();
		LCD_moveCursor(1, 12);
		if (Intensity >= 100)
		{
			LCD_intgerToString((uint32)Intensity);
		}
		else
		{
			LCD_intgerToString((uint32)Intensity);
			LCD_displayCharacter(' ');
		}


		if (Intensity <= 15)
		{
			LED_on(LED_RED);
			LED_on(LED_GREEN);
			LED_on(LED_BLUE);
		}
		else if (Intensity >= 16 && Intensity <= 50)
		{
			LED_on(LED_RED);
			LED_on(LED_GREEN);
			LED_off(LED_BLUE);
		}
		else if (Intensity >= 51 && Intensity <= 70)
		{
			LED_on(LED_RED);
			LED_off(LED_GREEN);
			LED_off(LED_BLUE);
		}
		else
		{
			LED_off(LED_RED);
			LED_off(LED_GREEN);
			LED_off(LED_BLUE);
		}

		// Temperature-based Fan Speed Control
		temp = LM35_getTemperature();

		if (temp >= 40)
		{
			motorSpeed = 100;
			motorState = "ON ";
		}
		else if (temp >= 35 && temp < 40)
		{
			motorSpeed = 75;
			motorState = "ON ";
		}
		else if (temp >= 30 && temp < 35)
		{
			motorSpeed = 50;
			motorState = "ON ";
		}
		else if (temp >= 25 && temp < 30)
		{
			motorSpeed = 25;
			motorState = "ON ";
		}
		else
		{
			motorSpeed = 0;
			motorState = "OFF";
		}

		// Update fan speed and state
		DcMotor_Rotate(CW, motorSpeed);
		LCD_moveCursor(0, 10);
		LCD_displayString(motorState);

		// Display temperature
		LCD_moveCursor(1, 5);
		LCD_intgerToString(temp);
	}
}
