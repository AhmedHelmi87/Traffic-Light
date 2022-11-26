/*
 * Timer.c
 *
 * Created: 15-Nov-22 12:08:42 AM
 *  Author: ahawh
 */ 
#include "Timer.h"

/*
	Initialize the Timer0
	1. Adjust the configuration of the Timer0 using register "TCCR0"
	2. Adjust the Timer0 start count to Zero
 */
void Timer0_init(void)
{
	TCCR0 = 0x00;
	TCNT0 = 0x00;
}

/*
	Start the Timer0 counting
	1. Adjust the clock source of the Timer0 using register "TCCR0"
	2. Adjust the source to the system clock with no prescaler for higher accuracy, then the Timer0 will count accordingly
 */
void Timer0_start(void)
{
	TCCR0 |= 0x01;
}

/*
	Stop the Timer0 counting
	1. Adjust the clock source of the Timer0 using register "TCCR0"
	2. Adjust the source to the "No Clock source" to stop counting
 */
void Timer0_stop(void)
{
	TCCR0 = 0x00;
}

/*
	Check the Timer0 Overflow state
	1. Read the bit number 0 in the register "TIFR"
	2. Store the Timer0 Overflow state in the "State" variable
 */
void Timer0_get_state(uint8_t *state)
{
	*state = getBit(TIFR,0);
}

/*
	Clear the Timer0 Overflow state
	1. Set the bit number 0 in the register "TIFR" to clear the Overflow bit
 */
void Timer0_clr_OF_flag(void)
{
	setBit(TIFR,0);
}

