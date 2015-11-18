/*
 * firstTest.c
 *
 *  The first code that will run on my attint2313
 *  Author: Sili 
 */ 
/*
* Objectives
* Set F_CPU :)
* 
*/
//unsigned long long
#define F_CPU	11059200ULL

#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	DDRB = 0x01;
    while(1)
    {
        PORTB = 0x01;
		_delay_ms(1000);
		PORTB = 0x00;
		_delay_ms(1000);
    }
}