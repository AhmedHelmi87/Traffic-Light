/*
 * INT.h
 *
 * Created: 15-Nov-22 9:43:19 AM
 *  Author: ahawh
 */ 


#ifndef INT_H_
#define INT_H_

#include "../../Utility/dataTypes.h"
#include "../../Utility/BitOperation.h"
#include "../registers.h"

typedef enum INT_Error_t
{
	INT_OK, WRONG_MODE
}INT_Error_t;

typedef enum Int0_mode_t
{
	LOW_LEVEL, ANY_EDGE, FALLING_EDGE, RISING_EDGE
}Int0_mode_t;

#define EXT_INT0 __vector_1
#define EXT_INT1 __vector_2
#define EXT_INT2 __vector_3

#define ISR(INT_VECT)void INT_VECT(void) __attribute__((signal,used));\
void INT_VECT(void)

void global_int_enable(void);
void global_int_disable(void);

void Int0_enable(void);
void Int0_disable(void);
uint8_t Int0_mode(uint8_t mode);


#endif /* INT_H_ */