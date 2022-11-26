/*
 * Button.c
 *
 * Created: 15-Nov-22 12:10:58 AM
 *  Author: ahawh
 */ 
#include "Button.h"

/*
	Initialize the requested Button
	1. Initialize the requested Pin with direction Input using "DIO_init"
 */
uint8_t Button_Init(uint8_t buttonPort, uint8_t buttonPin)
{
	return DIO_init(buttonPort, buttonPin, INPUT);
}

/*
	Read the state of the requested Button 
	1. Read the requested Pin using "DIO_read"
	2. Return the state in the variable "state"
 */
uint8_t Button_get_state(uint8_t buttonPort, uint8_t buttonPin, uint8_t* state)
{
	return DIO_read(buttonPort, buttonPin, state);
}

/*
	Initialize Int0 to activate on the Rising Edge
	1. Enable the Global Interrupts
	2. Set the Int0 mode using "Int0_mode" to be active on the Rising Edge
	3. Enable the Int0
 */
void Button_Interrupt_init(void)
{
	global_int_enable();
	Int0_mode(FALLING_EDGE);
	Int0_enable();
}