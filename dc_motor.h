/*
 * dc_motor.h
 *
 *  Created on: ٠٨‏/١٠‏/٢٠٢٤
 *      Author: LENOVO
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include"std_types.h"
#include"gpio.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define INPUT1_PORT_ID    PORTB_ID
#define INPUT1_PIN_ID     PIN0_ID
#define INPUT2_PORT_ID    PORTB_ID
#define INPUT2_PIN_ID     PIN1_ID
#define ENAPLE1_PORT_ID   PORTB_ID
#define ENABLE1_PIN_ID    PIN3_ID
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void DcMotor_Init(void);
typedef enum
{
	OFF,CW,ACW
}DcMotor_State;
void DcMotor_Rotate(DcMotor_State state, uint8 speed);



#endif /* DC_MOTOR_H_ */
