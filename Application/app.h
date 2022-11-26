/*
 * app.h
 *
 * Created: 15-Nov-22 12:02:04 AM
 *  Author: ahawh
 */ 

#ifndef APP_H_
#define APP_H_

#include "../ECUAL/Delay/Delay.h"
#include "../ECUAL/LED/LED.h"
#include "../ECUAL/Button/Button.h"

#define IDLE_STATE         0
#define PEDESTRIAN_REQUEST 1

#define CARS_RED    1
#define CARS_YELLOW 2
#define CARS_GREEN  3

#define WALK_RED    1
#define WALK_YELLOW 2
#define WALK_GREEN  3

#define CARS_PORT       PORT_A
#define CARS_RED_PIN    0
#define CARS_YELLOW_PIN 2
#define CARS_GREEN_PIN  4

#define WALK_PORT       PORT_B
#define WALK_RED_PIN    0
#define WALK_YELLOW_PIN 2
#define WALK_GREEN_PIN  4

#define REQ_PORT        PORT_D
#define REQ_PIN         2

void app_init(void);
void app_loop(void);
void test_drivers(void);

#endif /* APP_H_ */