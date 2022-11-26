/*
 * LED.c
 *
 * Created: 15-Nov-22 12:11:33 AM
 *  Author: ahawh
 */ 
#include "LED.h"

/*
	Initialize the requested LED
	1. Initialize the requested Pin with direction Output
 */
uint8_t LED_init(uint8_t ledPort, uint8_t ledPin)
{
	return DIO_init(ledPort, ledPin, OUTPUT);
}

/*
	Turn ON the requested LED
	1. Write high to the LED GPIO using "DIO_write"
 */
uint8_t LED_on(uint8_t ledPort, uint8_t ledPin)
{
	return DIO_write(ledPort, ledPin, PIN_HI);
}

/*
	Turn OFF the requested LED
	1. Write LOW to the LED GPIO using "DIO_write"
 */
uint8_t LED_off(uint8_t ledPort, uint8_t ledPin)
{
	return DIO_write(ledPort, ledPin, PIN_LOW);
}

/*
	Toggle the requested LED
	1. Toggle to the LED GPIO using "DIO_toggle"
 */
uint8_t LED_toggle(uint8_t ledPort, uint8_t ledPin)
{
	return DIO_toggle(ledPort, ledPin);
}
