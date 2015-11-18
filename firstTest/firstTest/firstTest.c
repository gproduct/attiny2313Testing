/*
 * firstTest.c
 *
 *  The first code that will run on my attint2313
 *  Author: Sili 
 */ 
/*
* Objectives
* We are using 1 led and the second PWM channel so I could learn how to change the ports
* 
*/
//unsigned long long
#define F_CPU	11059200ULL

#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	DDRB  = 0x08;//make the pin as output
	TCCR1A = (1 << COM1A1) | (1 << WGM00);//setup the pwm for that pin
	OCR1A = 0x10;//put a value for it
	TCCR1B = (1 << CS01);
	//in branch led we have some basic led code
    while(1)
    {
		uint8_t led;//because it mustn't go over 255
		for(led = 0;led<255;led++)
		{
			OCR1A = led;
			_delay_ms(50);	
		}
		_delay_ms(1000);
		OCR1A = 255;
		for(led = 255;led > 0;led--)
		{
			OCR1A = led;
			_delay_ms(50);
		}
		OCR1A = 0x00;
		_delay_ms(5000);
    }
}