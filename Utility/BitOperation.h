/*
 * BitOperation.h
 *
 * Created: 15-Nov-22 12:31:33 AM
 *  Author: ahawh
 */ 


#ifndef BITOPERATION_H_
#define BITOPERATION_H_

#define  setBit(reg,bit)     	reg |= (1<<bit)
#define  clrBit(reg,bit)        reg &= ~(1<<bit)
#define  toggleBit(reg,bit)     reg ^= (1<<bit)
#define  getBit(reg,bit)        ((reg & (1<<bit)) >> bit)

#endif /* BITOPERATION_H_ */