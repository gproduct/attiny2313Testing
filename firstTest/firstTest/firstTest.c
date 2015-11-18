/*
 * firstTest.c
 *
 *  The first code that will run on my attint2313
 *  Author: Sili 
 */ 
/*
* Description
* Using 2 leds to turn them on and off with a simple shift command
* Working great
*
*/
//unsigned long long
#define F_CPU	11059200ULL

#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	DDRB = 0x03;
	
    while(1)
    {
		PORTB = 0x01 << 1;
		_delay_ms(500);
		PORTB = 0x01;
		_delay_ms(500);
    }
}