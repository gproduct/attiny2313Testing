/*
 * portInit.c
 *
 * Created: 12/25/2015 10:38:16 AM
 *  Author: Sili
 */ 
#define F_CPU	11059200ULL

#include "portInit.h"
#include "mainFunctions.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int counter = 0;
void interruptInit()
{
	GIMSK= 1 << INT1;						//turning on the interupt (GIMSK register)
	MCUCR = 1 << ISC01 | 1 << ISC00;		//rising edge
	
	sei();
}
void portsInit()
{
	DDRB = 0x01;																							//leds init as output
	DDRD = 1 << PD4;																						//setting the PORTD PIN 4 as input for push button
	PORTD = 1 << PD4;																						//pull up for the pin
}
ISR(INT1_vect)								//run this if we have an external interrupt from PORTD PIN 4 (pushButton)
{
	counter++;
	_delay_ms(50);
}
