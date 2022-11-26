/*
 * DIO.c
 *
 * Created: 15-Nov-22 12:07:31 AM
 *  Author: ahawh
 */ 
#include "DIO.h"


/*
	Initialize the GPIO Pin
	1. Check the port requested and switch according to the appropriate DDR register
	2. Check direction requested and Clear or Set the bit in the DDR register according
	3. Select the bit in the register according to the Pin requested
 */
uint8_t DIO_init(uint8_t port, uint8_t pinNumber, uint8_t pinDirection)
{
	if(pinNumber > 8)
	{
		return WRONG_PIN;
	}
	
	switch(port)
	{
		case PORT_A:
			if(pinDirection == INPUT)
			{
				clrBit(DDRA,pinNumber); 
			}
			else if(pinDirection == OUTPUT)
			{
				setBit(DDRA,pinNumber);
			}
			else
			{
				return WRONG_DIRECTION;
			}
			break;
		case PORT_B:
			if(pinDirection == INPUT)
			{
				clrBit(DDRB,pinNumber);
			}
			else if(pinDirection == OUTPUT)
			{
				setBit(DDRB,pinNumber);
			}
			else
			{
				return WRONG_DIRECTION;
			}
			break;
		case PORT_C:
			if(pinDirection == INPUT)
			{
				clrBit(DDRC,pinNumber);
			}
			else if(pinDirection == OUTPUT)
			{
				setBit(DDRC,pinNumber);
			}
			else
			{
				return WRONG_DIRECTION;
			}
			break;
		case PORT_D:
			if(pinDirection == INPUT)
			{
				clrBit(DDRD,pinNumber);
			}
			else if(pinDirection == OUTPUT)
			{
				setBit(DDRD,pinNumber);
			}
			else
			{
				return WRONG_DIRECTION;
			}
			break;
		default:
			return WRONG_PORT;
	}
	return DIO_OK;
}

/*
	Write to output GPIO Pin
	1. Check the port requested and switch according to the appropriate PORT register
	2. Check the value requested and Clear or Set the bit in the PORT register according
	3. Select the bit in the register according to the Pin requested
 */
uint8_t DIO_write(uint8_t port, uint8_t pinNumber, uint8_t value)
{
	if(pinNumber > 8)
	{
		return WRONG_PIN;
	}
	
	switch(port)
	{
		case PORT_A:
			if(value == PIN_LOW)
			{
				clrBit(PORTA,pinNumber);
			}
			else if(value == PIN_HI)
			{
				setBit(PORTA,pinNumber);
			}
			else
			{
				return WRONG_VALUE;
			}
			break;
		case PORT_B:
			if(value == PIN_LOW)
			{
				clrBit(PORTB,pinNumber);
			}
			else if(value == PIN_HI)
			{
				setBit(PORTB,pinNumber);
			}
			else
			{
				return WRONG_VALUE;
			}
			break;
		case PORT_C:
			if(value == PIN_LOW)
			{
				clrBit(PORTC,pinNumber);
			}
			else if(value == PIN_HI)
			{
				setBit(PORTC,pinNumber);
			}
			else
			{
				return WRONG_VALUE;
			}
			break;
		case PORT_D:
			if(value == PIN_LOW)
			{
				clrBit(PORTD,pinNumber);
			}
			else if(value == PIN_HI)
			{
				setBit(PORTD,pinNumber);
			}
			else
			{
				return WRONG_VALUE;
			}
			break;
		default:
			return WRONG_PORT;
	}
	return DIO_OK;
}

/*
	Read from input GPIO Pin
	1. Check the port requested and switch according to the appropriate PIN register
	2. Read the bit in the register according to the Pin requested
	3. Store it in the "value" variable received
 */
uint8_t DIO_read(uint8_t port, uint8_t pinNumber, uint8_t *value)
{
	if(pinNumber > 8)
	{
		return WRONG_PIN;
	}
	
	switch(port)
	{
		case PORT_A:
			*value = getBit(PINA, pinNumber);
			break;
		case PORT_B:
			*value = getBit(PINB, pinNumber);
			break;
		case PORT_C:
			*value = getBit(PINC, pinNumber);
			break;
		case PORT_D:
			*value = getBit(PIND, pinNumber);
			break;
		default:
			return WRONG_PORT;
	}
	return DIO_OK;
}

/*
	Toggle output GPIO Pin
	1. Read the current Pin value in the Port requested using "DIO_read" function
	2. Check the current value of that Pin
	3. Write the opposite value to that Pin in the port requested using "DIO_write" function
 */
uint8_t DIO_toggle(uint8_t port, uint8_t pinNumber)
{
	uint8_t currentValue = 0;
	uint8_t readResult = 0;
	readResult = DIO_read(port, pinNumber, &currentValue);
	if (readResult == DIO_OK)
	{
		if(currentValue == PIN_LOW)
		{
			return DIO_write(port, pinNumber, PIN_HI);
		}
		else
		{
			return DIO_write(port, pinNumber, PIN_LOW);
		}
	}
	else
	{
		return readResult;
	}
}
