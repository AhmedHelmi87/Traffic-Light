/*
 * INT.c
 *
 * Created: 15-Nov-22 9:43:33 AM
 *  Author: ahawh
 */ 
#include "INT.h"

/*
	Enable the global interrupts
	1. Set the 7th bit in the "SREG" register
 */
void global_int_enable(void)
{
	setBit(SREG, 7);
}

/*
	Disable the global interrupts
	1. Clear the 7th bit in the "SREG" register
 */
void global_int_disable(void)
{
	clrBit(SREG, 7);
}

/*
	Enable the Int0 interrupts
	1. Set the 6th bit in the "GICR" register
 */
void Int0_enable(void)
{
	setBit(GICR, 6);
}

/*
	Disable the Int0 interrupts
	1. Clear the 6th bit in the "GICR" register
 */
void Int0_disable(void)
{
	clrBit(GICR, 6);
}

/*
	Set the Int0 interrupts mode (Low Level - Any Edge - Falling Edge - Rising Edge)
	1. Check the mode requested and switch according
	2. Adjust the bits 0 & 1 in register "MUCUR" to the appropriate value according to the mode
 */
uint8_t Int0_mode(uint8_t mode)
{
	switch(mode)
	{
		case LOW_LEVEL:
			clrBit(MCUCR, 0);
			clrBit(MCUCR, 1);
			break;
		case ANY_EDGE:
			setBit(MCUCR, 0);
			clrBit(MCUCR, 1);
			break;
		case FALLING_EDGE:
			clrBit(MCUCR, 0);
			setBit(MCUCR, 1);
			break;
		case RISING_EDGE:
			setBit(MCUCR, 0);
			setBit(MCUCR, 1);
			break;
		default:
			return WRONG_MODE;
	}
	return INT_OK;
}