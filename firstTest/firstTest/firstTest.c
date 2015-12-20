/*
 * firstTest.c
 *
 *  The first code that will run on my attint2313
 *  Author: Sili 
 */ 
/*
* Objectives
* idk
* 
*/
//unsigned long long
#define F_CPU	11059200ULL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define DataPort PORTB
#define DataDDR DDRB

ISR(INT1_vect)								//run this if we have an external interrupt from PORTD PIN 4 (pushButton)
{
	unsigned char i,temp;
	
	_delay_ms(100);
	temp = DataPort;
	
	for(i = 0; i < 5; i++)
	{
		DataPort = 0x00;
		_delay_ms(500);
		DataPort = 0xff;
		_delay_ms(500);
	}
	DataPort = temp;
}
int main(void)
{
	DDRD = 1 << PD4;						//setting the PORTD PIN 4 as input for push button
	PORTD = 1 << PD4;						//pull up for the pin
	
	DataDDR = 0xff;							//portb as output for the leds
	DataPort = 0x01;						//init for just one led
	
	GIMSK= 1 << INT1;						//turning on the interupt (GIMSK register)
	MCUCR = 1 << ISC01 | 1 << ISC00;		//rising edge
	
	sei();
	
    while(1)
    {
        if(DataPort == 0x08){				//if at the end of (1000) then start over
			DataPort = 1;
		}
		else
			DataPort = DataPort << 1;		//shift it so it will turn on the next led
		_delay_ms(500);
    }
}