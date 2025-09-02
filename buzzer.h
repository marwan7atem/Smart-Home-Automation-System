/*
 * buzzer.h
 *
 *  Created on: ٠٨‏/١٠‏/٢٠٢٤
 *      Author: LENOVO
 */

#ifndef BUZZER_H_
#define BUZZER_H_
#include"std_types.h"

#define BUZZER_PORT_ID   PORTD_ID
#define BUZZER_PIN_ID    PIN3_ID

void Buzzer_init(void);

void Buzzer_on(void);

void Buzzer_off(void);



#endif /* BUZZER_H_ */
