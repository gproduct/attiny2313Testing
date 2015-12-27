/*
 * firstTest.c
 *
 *  The first code that will run on my attint2313
 *  Author: Sili 
 */ 

#define F_CPU	11059200ULL

#include <avr/io.h>
#include <util/delay.h>

void setup()
{
	
	DDRB = 0x04;
	
	DDRD &= ~(1<<PD4); //Define input on PC3
	PORTD |= (1<<PD4); // set pull up resistor
}
int main(void){
	setup();
		
	int counted = 0;
	while(1)
	{
		if(PIND & (1<<PD4)) {
			counted++;
			_delay_ms(400);
		}
		if(counted == 5){
			PORTB = 0x04;
		}
		else if(counted == 7){
			PORTB = 0x04;
		}
		else{
			PORTB = 0x00;
		}
		_delay_ms(100);
	}
}
