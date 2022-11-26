/*
 * DIO.h
 *
 * Created: 15-Nov-22 12:07:45 AM
 *  Author: ahawh
 */ 

#ifndef DIO_H_
#define DIO_H_

#include "../../Utility/dataTypes.h"
#include "../../Utility/BitOperation.h"
#include "../registers.h"

// Ports name
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

// PIN Direction
#define INPUT  0
#define OUTPUT 1

// PIN State
#define PIN_LOW 0
#define PIN_HI 1

typedef enum DIO_Error_t
{
	DIO_OK, WRONG_PIN, WRONG_PORT, WRONG_DIRECTION, WRONG_VALUE
}DIO_Error_t;

uint8_t DIO_init(uint8_t port, uint8_t pinNumber, uint8_t pinDirection);

uint8_t DIO_write(uint8_t port, uint8_t pinNumber, uint8_t value);

uint8_t DIO_read(uint8_t port, uint8_t pinNumber, uint8_t *value);

uint8_t DIO_toggle(uint8_t port, uint8_t pinNumber);


#endif /* DIO_H_ */