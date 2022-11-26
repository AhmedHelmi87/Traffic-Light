/*
 * LED.h
 *
 * Created: 15-Nov-22 12:11:51 AM
 *  Author: ahawh
 */ 

#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO/DIO.h"

uint8_t LED_init(uint8_t ledPort, uint8_t ledPin);

uint8_t LED_on(uint8_t ledPort, uint8_t ledPin);

uint8_t LED_off(uint8_t ledPort, uint8_t ledPin);

uint8_t LED_toggle(uint8_t ledPort, uint8_t ledPin);



#endif /* LED_H_ */