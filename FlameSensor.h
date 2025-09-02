/*
 * FlameSensor.h
 *
 *  Created on: ٠٨‏/١٠‏/٢٠٢٤
 *      Author: LENOVO
 */

#ifndef FLAMESENSOR_H_
#define FLAMESENSOR_H_

#include"std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define FLAME_SENSOR_PORT_ID   PORTD_ID
#define FLAME_SENSOR_PIN_ID    PIN2_ID
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void FlameSensor_init(void);
uint8 FlameSensor_getValue(void);


#endif /* FLAMESENSOR_H_ */
