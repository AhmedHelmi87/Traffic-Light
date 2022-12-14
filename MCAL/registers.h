/*
 * registers.h
 *
 * Created: 15-Nov-22 12:25:01 AM
 *  Author: ahawh
 */ 
#include "../Utility/dataTypes.h"

#ifndef REGISTERS_H_
#define REGISTERS_H_

/* General */
#define SREG   (*(volatile uint8_t *)(0x5F))

/* PORTA Registers */
#define PORTA  (*(volatile uint8_t *)(0x3B)) 
#define DDRA   (*(volatile uint8_t *)(0x3A)) 
#define PINA   (*(volatile uint8_t *)(0x39)) 

/* PORTB Registers */
#define PORTB  (*(volatile uint8_t *)(0x38))
#define DDRB   (*(volatile uint8_t *)(0x37))
#define PINB   (*(volatile uint8_t *)(0x36))

/* PORTC Registers */
#define PORTC  (*(volatile uint8_t *)(0x35))
#define DDRC   (*(volatile uint8_t *)(0x34))
#define PINC   (*(volatile uint8_t *)(0x33))

/* PORTD Registers */
#define PORTD  (*(volatile uint8_t *)(0x32))
#define DDRD   (*(volatile uint8_t *)(0x31))
#define PIND   (*(volatile uint8_t *)(0x30))

/* Timer0 Registers */
#define TCCR0  (*(volatile uint8_t *)(0x53))
#define TCNT0  (*(volatile uint8_t *)(0x52))
#define TIFR   (*(volatile uint8_t *)(0x58))

/* Interrupt Registers */
#define GICR   (*(volatile uint8_t *)(0x5B)) 
#define MCUCR  (*(volatile uint8_t *)(0x55))
#define MCUCSR  (*(volatile uint8_t *)(0x54))
#define GIFR   (*(volatile uint8_t *)(0x5A))


#endif /* REGISTERS_H_ */