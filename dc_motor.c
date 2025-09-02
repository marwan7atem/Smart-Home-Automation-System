/*
 * dc_motor.c
 *
 *  Created on: ٠٨‏/١٠‏/٢٠٢٤
 *      Author: LENOVO
 */
#include"common_macros.h"
#include"gpio.h"
#include"dc_motor.h"
#include"pwm.h"
void DcMotor_Init(void)
{
	GPIO_setupPinDirection(INPUT1_PORT_ID,INPUT1_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(INPUT2_PORT_ID,INPUT2_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(ENAPLE1_PORT_ID,ENABLE1_PIN_ID,PIN_OUTPUT);

	GPIO_writePin(INPUT1_PORT_ID,INPUT1_PIN_ID,LOGIC_LOW);
	GPIO_writePin(INPUT2_PORT_ID,INPUT2_PIN_ID,LOGIC_LOW);
}
void DcMotor_Rotate(DcMotor_State state, uint8 speed)
{

	switch(state)
		{
	PWM_Timer0_Start(speed);
		case OFF:    // Stop
			GPIO_writePin(INPUT1_PORT_ID,INPUT1_PIN_ID,LOGIC_LOW);
			GPIO_writePin(INPUT2_PORT_ID,INPUT2_PIN_ID,LOGIC_LOW);

			break;
		case CW:   // CW
			GPIO_writePin(INPUT1_PORT_ID,INPUT1_PIN_ID,LOGIC_LOW);
			GPIO_writePin(INPUT2_PORT_ID,INPUT2_PIN_ID,LOGIC_HIGH);
			PWM_Timer0_Start(speed);
			break;
		case ACW:   // ACW
			GPIO_writePin(INPUT1_PORT_ID,INPUT1_PIN_ID,LOGIC_HIGH);
			GPIO_writePin(INPUT2_PORT_ID,INPUT2_PIN_ID,LOGIC_LOW);

			break;

		}
}


