/*
 * led_program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: mariam el kess
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "led_interface.h"
#include "DIO_interface.h"

#include "AVR_DIO_REG.h"
#include "led_precfg.h"


void DIO_LED_VOIDINIT (void){
	MCAL_DIO_u8SetPinDir( LED0 , DIO_OUTPUT);
	MCAL_DIO_u8SetPinDir( LED1 , DIO_OUTPUT);
}

void LED_ON (uint8_t Copy_PORTNO,uint8_t Copy_PINNO){
	MCAL_DIO_u8SetPinValue(Copy_PORTNO,Copy_PINNO,DIO_HIGH);
}

void LED_OFF (uint8_t Copy_PORTNO,uint8_t Copy_PINNO){
	MCAL_DIO_u8SetPinValue(Copy_PORTNO,Copy_PINNO,DIO_LOW);
}
