/*
 * Timer.h
 *
 * Created: 15-Nov-22 12:08:29 AM
 *  Author: ahawh
 */ 

#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utility/dataTypes.h"
#include "../../Utility/BitOperation.h"
#include "../registers.h"

void Timer0_init(void);

void Timer0_start(void);

void Timer0_stop(void);

void Timer0_get_state(uint8_t *state);

void Timer0_clr_OF_flag(void);

#endif /* TIMER_H_ */