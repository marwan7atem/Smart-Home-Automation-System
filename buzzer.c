/*
 * buzzer.c
 *
 *  Created on: ٠٨‏/١٠‏/٢٠٢٤
 *      Author: LENOVO
 */
#include"buzzer.h"
#include"gpio.h"
void Buzzer_init(void)
{
	//Initializes the buzzer pin direction and turn off the buzzer
	GPIO_setupPinDirection(BUZZER_PORT_ID,BUZZER_PIN_ID,PIN_OUTPUT);
	GPIO_writePin(BUZZER_PORT_ID,BUZZER_PIN_ID,LOGIC_LOW);
}
void Buzzer_on(void)
{
	//Activates the buzzer
	GPIO_writePin(BUZZER_PORT_ID,BUZZER_PIN_ID,LOGIC_HIGH);
}
void Buzzer_off(void)
{
	GPIO_writePin(BUZZER_PORT_ID,BUZZER_PIN_ID,LOGIC_LOW);
}


