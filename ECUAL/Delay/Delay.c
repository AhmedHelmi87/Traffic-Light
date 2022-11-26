/*
 * Delay.c
 *
 * Created: 22-Nov-22 10:36:31 AM
 *  Author: ahawh
 */ 
#include "Delay.h"

/*
	Create Delay function in Millisecond using Timer0
	1. Calculate the needed counts of the Timer0 Overflows to achieve the request Milliseconds
	2. Initialize Time0 using function "Timer0_init"
	3. Start Timer0 using function "Timer0_start"
	4. Go through Overflow counts needed and in each cycle do the following
	5. Loop until the Overflow flag received
	6. Clear the Timer0 Overflow flag for the next round
	7. By the End stop the Timer0 using function "Timer0_stop"
 */
uint8_t delay_ms(float delay_ms)
{
	if((delay_ms > 16000) || (delay_ms < 0))
	{
		return WRONG_DELAY;
	}
	
	uint8_t Timer0_OF = 0;
	float overflow_num = 0;
	
	overflow_num = delay_ms * 2000;
	overflow_num = overflow_num / 512;
	
	Timer0_init();
	
	Timer0_start();

	for(uint16_t i=0; i<overflow_num; i++)
	{
		while(Timer0_OF == 0)
		{
			Timer0_get_state(&Timer0_OF);
		}
		Timer0_clr_OF_flag();
		Timer0_OF = 0;
	}
	
	Timer0_stop();
	
	return DELAY_OK;
}