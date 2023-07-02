/*
 * Main.c
 *
 *  Created on: 2 Jul 2023
 *      Author: george yaccoup
 */
#include "DIO_init.h"
#include "DIO_private.h"
#include <util/delay.h>
#define SSG_PORT PORTC
#define SWITCH_INCRESE_GROUP DIO_GROUP_C
#define SWITCH_DECREAS_GROUP DIO_GROUP_C
#define SSG_PORT PORTA
#define SWITCH_INCRESE_PIN DIO_PIN_0
#define SWITCH_DECREAS_PIN DIO_PIN_1
#define SSG_display(Copy_num) SSG_PORT=(SSG_PORT&0xF0)|Copy_num

int main(){
	DIO_voidSetPinDirection(SWITCH_INCRESE_GROUP, SWITCH_INCRESE_PIN, DIO_INPUT);
	DIO_voidSetPinDirection(SWITCH_DECREAS_GROUP, SWITCH_DECREAS_PIN, DIO_INPUT);
	DIO_voidSetPinDirection(SSG_PORT, DIO_PIN_0,DIO_OUTPUT);
	DIO_voidSetPinDirection(SSG_PORT, DIO_PIN_1, DIO_OUTPUT);
	DIO_voidSetPinDirection(SSG_PORT, DIO_PIN_2, DIO_OUTPUT);
	DIO_voidSetPinDirection(SSG_PORT, DIO_PIN_3, DIO_OUTPUT);
	DIO_voidSetPinValue(SSG_PORT, DIO_PIN_0,DIO_LOW);
	DIO_voidSetPinValue(SSG_PORT, DIO_PIN_1,DIO_LOW);
	DIO_voidSetPinValue(SSG_PORT, DIO_PIN_2,DIO_LOW);
	DIO_voidSetPinValue(SSG_PORT, DIO_PIN_3,DIO_LOW);
	DIO_voidSetPinValue(SWITCH_INCRESE_GROUP, SWITCH_INCRESE_PIN,DIO_HIGH);
	DIO_voidSetPinValue(SWITCH_DECREAS_GROUP, SWITCH_DECREAS_PIN,DIO_HIGH);
	u8 Local_u8DisplayNum=0;
	while (1) {
		if (DIO_u8GetPinValue(SWITCH_INCRESE_GROUP, SWITCH_INCRESE_PIN) == 0)
			Local_u8DisplayNum++;
		if (DIO_u8GetPinValue(SWITCH_DECREAS_GROUP, SWITCH_DECREAS_PIN) == 0)
			Local_u8DisplayNum--;
		if (Local_u8DisplayNum==9)
			Local_u8DisplayNum=0;
		SSG_display(Local_u8DisplayNum);
		_delay_ms(500);
	}

}
