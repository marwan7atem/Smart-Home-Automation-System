/*
 * led.c
 *
 *  Created on: ٠٨‏/١٠‏/٢٠٢٤
 *      Author: LENOVO
 */
#include"common_macros.h"
#include"led.h"
#include"gpio.h"
void LEDS_init(void)
{
	//Setup the direction of the required pin as output pin
	GPIO_setupPinDirection(LED_RED_PORT_ID,LED_RED_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LED_GREEN_PORT_ID,LED_GREEN_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LED_BLUE_PORT_ID,LED_BLUE_PIN_ID,PIN_OUTPUT);
	//turn of all leds
#if(LED_CONNECTION_TYPE == POSITIVE_LOGIC)

		GPIO_writePin(LED_RED_PORT_ID,LED_RED_PIN_ID,LOGIC_LOW);
		GPIO_writePin(LED_GREEN_PORT_ID,LED_GREEN_PIN_ID,LOGIC_LOW);
		GPIO_writePin(LED_BLUE_PORT_ID,LED_BLUE_PIN_ID,LOGIC_LOW);

#elif(LED_CONNECTION_TYPE == NEGATIVE_LOGIC)
		GPIO_writePin(LED_RED_PORT_ID,LED_RED_PIN_ID,LOGIC_HIGH);
		GPIO_writePin(LED_GREEN_PORT_ID,LED_GREEN_PIN_ID,LOGIC_HIGH);
		GPIO_writePin(LED_BLUE_PORT_ID,LED_BLUE_PIN_ID,LOGIC_HIGH);
#endif
}

void LED_on(LED_ID id)
{
#if(LED_CONNECTION_TYPE == POSITIVE_LOGIC)
	switch(id)
	{
	case 0:
		GPIO_writePin(LED_RED_PORT_ID,LED_RED_PIN_ID,LOGIC_HIGH);
		break;
	case 1:
		GPIO_writePin(LED_GREEN_PORT_ID,LED_GREEN_PIN_ID,LOGIC_HIGH);
		break;
	case 2:
		GPIO_writePin(LED_BLUE_PORT_ID,LED_BLUE_PIN_ID,LOGIC_HIGH);
		break;
	}


#elif(LED_CONNECTION_TYPE == NEGATIVE_LOGIC)
	switch(id)
		{
		case 0:
			GPIO_writePin(LED_RED_PORT_ID,LED_RED_PIN_ID,LOGIC_LOW);
			break;
		case 1:
			GPIO_writePin(LED_GREEN_PORT_ID,LED_GREEN_PIN_ID,LOGIC_LOW);
			break;
		case 2:
			GPIO_writePin(LED_BLUE_PORT_ID,LED_BLUE_PIN_ID,LOGIC_LOW);
			break;
		}

#endif
}

void LED_off(LED_ID id)
{
#if(LED_CONNECTION_TYPE == POSITIVE_LOGIC)
	switch(id)
	{
	case 0:
		GPIO_writePin(LED_RED_PORT_ID,LED_RED_PIN_ID,LOGIC_LOW);
		break;
	case 1:
		GPIO_writePin(LED_GREEN_PORT_ID,LED_GREEN_PIN_ID,LOGIC_LOW);
		break;
	case 2:
		GPIO_writePin(LED_BLUE_PORT_ID,LED_BLUE_PIN_ID,LOGIC_LOW);
		break;
	}
#elif(LED_CONNECTION_TYPE == NEGATIVE_LOGIC)
	switch(id)
	{
	case 0:
		GPIO_writePin(LED_RED_PORT_ID,LED_RED_PIN_ID,LOGIC_HIGH);
		break;
	case 1:
		GPIO_writePin(LED_GREEN_PORT_ID,LED_GREEN_PIN_ID,LOGIC_HIGH);
		break;
	case 2:
		GPIO_writePin(LED_BLUE_PORT_ID,LED_BLUE_PIN_ID,LOGIC_HIGH);
		break;
	}
#endif
}



