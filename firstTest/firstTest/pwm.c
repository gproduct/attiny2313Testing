/*
 * pwm.c
 *
 * Created: 12/29/2015 10:35:44 AM
 *  Author: Sili
 */ 
#define F_CPU	11059200ULL
#define DEBOUNCE 10

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "pwm.h"

void servo_init(unsigned int f_pwm)
{
	DDRB |= (1 << PINB2) | (1 << PINB3) | (1 << PINB4);
	DDRD |= (1 << PIND5);
	
	TCCR0A = (1 << COM0A1) | (1 << COM0B1) | (1 << WGM01) | (1 << WGM00);
	TCCR0B = (1 << CS01) | (1 << CS00);
	TCCR1A = (1 << COM1A1) | (1 << COM1B1) | (1 << WGM12) | (1 << WGM10);
	TCCR1B = (1 << CS11) | (1 << CS10);
	TCNT0 = 0;
	OCR0A = 0;
	OCR0B = 0;
	OCR1A = 0;
	OCR1B = 0;
}//END OF servo_init