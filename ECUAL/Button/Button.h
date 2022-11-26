/*
 * Button.h
 *
 * Created: 15-Nov-22 12:11:12 AM
 *  Author: ahawh
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/INT/INT.h"

uint8_t Button_Init(uint8_t buttonPort, uint8_t buttonPin);
uint8_t Button_get_state(uint8_t buttonPort, uint8_t buttonPin, uint8_t* state);
void Button_Interrupt_init(void);

#endif /* BUTTON_H_ */