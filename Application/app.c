/*
 * app.c
 *
 * Created: 15-Nov-22 12:01:30 AM
 *  Author: ahawh
 */ 
#include "app.h"

uint8_t pedestrianRequest = 0;
uint8_t cycleCount = 0;
uint8_t carsState = CARS_GREEN;
uint8_t walkState = WALK_RED;
uint8_t previousCarState = CARS_RED;

volatile uint8_t errorResult = 0;




/*
	Initialize the application
	1. Initialize the Cars traffic light LEDs GPIOs
	2. Initialize the Pedestrian traffic light LEDs GPIOs
	3. Initialize the Pedestrian request button GPIO
	4. Enable the Rising Edge interrupt on that button 
 */
void app_init(void)
{
	// Cars traffic light LEDs
	errorResult = LED_init(CARS_PORT, CARS_RED_PIN); // Red
	errorResult = LED_init(CARS_PORT, CARS_YELLOW_PIN); // Yellow
	errorResult = LED_init(CARS_PORT, CARS_GREEN_PIN); // Green
	
	// Pedestrian traffic light LEDs
	errorResult = LED_init(WALK_PORT, WALK_RED_PIN); // Red
	errorResult = LED_init(WALK_PORT, WALK_YELLOW_PIN); // Yellow
	errorResult = LED_init(WALK_PORT, WALK_GREEN_PIN); // Green

	// Initialize the request button	
	errorResult = Button_Init(REQ_PORT, REQ_PIN);
	
	Button_Interrupt_init();
}

/*
	Application main loop
	1. Create loop that update the traffic light state every 500 Millisecond 
	2. If not in Pedestrian mode then cycle on the cars traffic light normally
	3. Also keep the Pedestrian traffic light in the RED state
	4. If in the Pedestrian mode then move to the Cars RED light as soon as possible 
	5. If the traffic light is in cars Green then turn the Cars & Pedestrian Yellow and move to the next step
	6. If the traffic light is in cars Yellow then turn the Pedestrian Yellow and after 5 Sec switch to Cars RED and move to the next step
	7. If the traffic light is in cars RED then switch to Pedestrian Green and after 5 Sec switch back to the normal mode.
 */
void app_loop(void)
{
	while (1)
	{
		if(pedestrianRequest == IDLE_STATE)
		{
			switch(carsState)
			{
				case CARS_RED:
					errorResult = LED_on(CARS_PORT, CARS_RED_PIN);
					errorResult = LED_off(CARS_PORT, CARS_YELLOW_PIN);
					errorResult = LED_off(CARS_PORT, CARS_GREEN_PIN);
					if(cycleCount == 10)
					{
						carsState = CARS_YELLOW;
						previousCarState = CARS_RED;
					}
					break;
				case CARS_YELLOW:
					errorResult = LED_off(CARS_PORT, CARS_RED_PIN);
					errorResult = LED_toggle(CARS_PORT, CARS_YELLOW_PIN);
					errorResult = LED_off(CARS_PORT, CARS_GREEN_PIN);
					if(cycleCount == 10)
					{
						if (previousCarState == CARS_RED)
						{
							carsState = CARS_GREEN;
						}
						else if (previousCarState == CARS_GREEN)
						{
							carsState = CARS_RED;
						}
					}
					break;
				case CARS_GREEN:
					errorResult = LED_off(CARS_PORT, CARS_RED_PIN);
					errorResult = LED_off(CARS_PORT, CARS_YELLOW_PIN);
					errorResult = LED_on(CARS_PORT, CARS_GREEN_PIN);
					if(cycleCount == 10)
					{
						carsState = CARS_YELLOW;
						previousCarState = CARS_GREEN;
					}
					break;
			}
	
			errorResult = LED_on(WALK_PORT, 0); //Walk red led
			errorResult = LED_off(WALK_PORT, 2); //Walk yellow led
			errorResult = LED_off(WALK_PORT, 4); //Walk green led
		}
		else if (pedestrianRequest == PEDESTRIAN_REQUEST)
		{
			switch(carsState)
			{
				case CARS_RED:
					errorResult = LED_on(CARS_PORT, CARS_RED_PIN);
					errorResult = LED_off(CARS_PORT, CARS_YELLOW_PIN);
					errorResult = LED_off(CARS_PORT, CARS_GREEN_PIN);
					errorResult = LED_off(WALK_PORT, WALK_RED_PIN);
					errorResult = LED_off(WALK_PORT, WALK_YELLOW_PIN);
					errorResult = LED_on(WALK_PORT, WALK_GREEN_PIN);
					if(cycleCount == 10)
					{
						carsState = CARS_YELLOW;
						previousCarState = CARS_RED;
						pedestrianRequest = IDLE_STATE;
					}
					break;
				case CARS_YELLOW:
					errorResult = LED_off(CARS_PORT, CARS_RED_PIN);
					errorResult = LED_toggle(CARS_PORT, CARS_YELLOW_PIN);
					errorResult = LED_off(CARS_PORT, CARS_GREEN_PIN);
					errorResult = LED_off(WALK_PORT, WALK_RED_PIN);
					errorResult = LED_toggle(WALK_PORT, WALK_YELLOW_PIN);
					errorResult = LED_off(WALK_PORT, WALK_GREEN_PIN);
					if(cycleCount == 10)
					{
						carsState = CARS_RED;
					}
					break;
				case CARS_GREEN:
					errorResult = LED_off(CARS_PORT, CARS_RED_PIN);
					errorResult = LED_toggle(CARS_PORT, CARS_YELLOW_PIN);
					errorResult = LED_off(CARS_PORT, CARS_GREEN_PIN);
					errorResult = LED_off(WALK_PORT, WALK_RED_PIN);
					errorResult = LED_toggle(WALK_PORT, WALK_YELLOW_PIN);
					errorResult = LED_off(WALK_PORT, WALK_GREEN_PIN);
					carsState = CARS_YELLOW;
					break;
			}
		}
		
		// Change state every 5 seconds (10 counts of 500ms)
		if(cycleCount == 10)
		{
			cycleCount = 0;
		}
		
		errorResult = delay_ms(500);
		cycleCount++;
	}
}

/*
	Interrupt handler for the Int0
	1. Check the current system state
	2. If the traffic light is working in the normal case then switch to pedestrian mode and reset the cycle counter
	3. If in the Pedestrian mode already then do nothing 
 */
ISR(EXT_INT0)
{
	if(pedestrianRequest == IDLE_STATE)
	{
		pedestrianRequest = PEDESTRIAN_REQUEST;
		cycleCount = 0;
		//Int0_disable();
	}
	//setBit(GIFR, 6);
}

/*
	Test all drivers APIs in both layers MCAL & ECUAL
 */
void test_drivers(void)
{
	volatile uint8_t testResult = 0;
	uint8_t readValue = 0;
	
	// Test DIO_init
	testResult = DIO_init('A', 9, INPUT); // Wrong Pin
	
	testResult = DIO_init('V', 6, INPUT); // Wrong Port
	
	testResult = DIO_init('A', 6, 4); // Wrong Direction
	
	testResult = DIO_init('A', 6, INPUT); // Valid
	
	// Test DIO_write
	testResult = DIO_write('A', 11, PIN_LOW); // Wrong Pin
	
	testResult = DIO_write('V', 6, PIN_LOW); // Wrong Port 
	
	testResult = DIO_write('A', 6, 3); // Wrong Value 
	
	testResult = DIO_write('A', 6, PIN_LOW); // Valid
	
	// Test DIO_read
	testResult = DIO_read('A', 11, &readValue); // Wrong Pin
	
	testResult = DIO_read('V', 6, &readValue); // Wrong Port
	
	testResult = DIO_read('A', 6, &readValue); // Valid
	
	// Test DIO_toggle
	testResult = DIO_toggle('A', 11); // Wrong Pin
	
	testResult = DIO_toggle('V', 6); // Wrong Port
	
	testResult = DIO_toggle('A', 6); // Valid
	
	// Test Int0_mode
	testResult = Int0_mode(5); // Wrong mode
	
	testResult = Int0_mode(RISING_EDGE); // valid
	
	// Test Button_Init
	testResult = Button_Init('A', 11); // Wrong Pin
	
	testResult = Button_Init('E', 6); // Wrong Port
	
	testResult = Button_Init('A', 5); // Valid
	
	// Test Button_get_state
	testResult = Button_get_state('A', 11, &readValue); // Wrong Pin
	
	testResult = Button_get_state('W', 3, &readValue); // Wrong Port
	
	testResult = Button_get_state('A', 2, &readValue); // Valid
	
	// Test LED_init
	testResult = LED_init('A', 9); // Wrong Pin
	
	testResult = LED_init('V', 6); // Wrong Port
		
	testResult = LED_init('A', 6); // Valid
	
	// Test LED_on
	testResult = LED_on('A', 11); // Wrong Pin
	
	testResult = LED_on('V', 6); // Wrong Port
		
	testResult = LED_on('A', 6); // Valid
	
	// Test LED_off
	testResult = LED_off('A', 11); // Wrong Pin
	
	testResult = LED_off('V', 6); // Wrong Port
	
	testResult = LED_off('A', 6); // Valid
	
	// Test LED_toggle
	testResult = LED_toggle('A', 11); // Wrong Pin
	
	testResult = LED_toggle('V', 6); // Wrong Port
	
	testResult = LED_toggle('A', 6); // Valid
	
	
	/*
		Test Delay Driver
	 */
	// Test delay_ms
	testResult = delay_ms(-10); // Wrong delay negative value
	
	testResult = delay_ms(20000); // Wrong delay over limitation

	testResult = delay_ms(1000); // Wrong delay negative value

	testResult += 1;
}