/*
 * pwm.c
 *
 *  Created on: ٠٨‏/١٠‏/٢٠٢٤
 *      Author: LENOVO
 */
#include<avr/io.h>
#include<util/delay.h>
#include"pwm.h"
#include"gpio.h"
#include"common_macros.h"

void PWM_Timer0_Start(uint8 duty_cycle)
{
	//set initial value
	 TCNT0=0;
	 // sets the required duty cycle
	 OCR0=(duty_cycle*255)/100;
	 // configures OC0 as the output pin.
	 SET_BIT(DDRB,3);
	 //set fast PWM mode
	 TCCR0|=(1<<WGM01)|(1<<WGM00);
	 //Set non inverting mode
	 TCCR0|=(1<<COM01);
	 //set 1024 prescaler
	 TCCR0|=(1<<CS02)|(1<<CS00);

}



