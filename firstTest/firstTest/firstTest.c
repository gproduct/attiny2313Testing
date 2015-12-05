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


void servo_init(unsigned int f_pwm)
{
	DDRB |= (1 << PINB2) | (1 << PINB3) | (1 << PINB4);
	
	TCNT1 = 0;
	OCR1A = 0;
	OCR1B = 0;
	OCR0A = 0;
	
	TCCR1A = (1 << COM1A1) | (1 << COM1A0) | (1 << COM1B1) | (1 << COM1B0) | (1 << WGM11);
	TCCR1B = (1 << WGM12) | (1 << WGM13) | (1 << CS11); // PRESKALER = 1
	ICR1 = ((double)F_CPU) / (8 * f_pwm) - 0.5; // FREKVENCIJA PWMA JE ~19kHz
}//END OF servo_init


void servo_position1(unsigned char dutyCycle)
{
	/*if((dutyCycle < 65) || (dutyCycle > 175))
	{
		dutyCycle = 150;
	}*/
	OCR1A = ((double)ICR1 / 255) * dutyCycle + 0.5;
	
}//END OF servo_position

void servo_position2(unsigned char dutyCycle)
{
	/*if((dutyCycle < 110) || (dutyCycle >220))
	{
		dutyCycle = 160;
	}*/
		OCR1B = ((double)ICR1 / 255) * dutyCycle + 0.5;
	
}//END OF servo_position
int main(void)
{
	servo_init(50);
	while(1)
	{
		_delay_ms(500);
		servo_position2(234);
		_delay_ms(500);
		servo_position2(228);
		_delay_ms(500);
		
		/*servo_position2(234);
		_delay_ms(500);*/
	}
}