/*
 * Delay.h
 *
 * Created: 22-Nov-22 10:36:45 AM
 *  Author: ahawh
 */ 


#ifndef DELAY_H_
#define DELAY_H_

#include "../../MCAL/Timer/Timer.h"

typedef enum DELAY_Error_t
{
	DELAY_OK, WRONG_DELAY
}DELAY_Error_t;


uint8_t delay_ms(float delay_ms);

#endif /* DELAY_H_ */