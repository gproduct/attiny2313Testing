/*
 * mainFunctions.c
 *
 * Created: 12/25/2015 10:42:47 AM
 *  Author: Sili
 */ 
#define F_CPU	11059200ULL

#include "portInit.h"
#include "mainFunctions.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void setPBNULL()
{
	PORTB = 0x00;
}