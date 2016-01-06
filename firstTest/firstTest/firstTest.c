
/*
INFO MOTHERF

If the motorpseed is 31 the brakspeed is motorspeed *1.2
brake delay is 500 and the brakmotor variable is 255


*/


#define F_CPU	11059200ULL


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "pwm.h"
	
int pressed = 0;
int PCL = 0;
int RCL = 0;

int main(void){
	servo_init(50);
	while(1)
	{
		//0A white
		//1A right orange
		//0B keft orange
		//1B left
		//0b and 1b left motor
		OCR1A = 0;
		OCR0A = 255;
		OCR1B = 0;
		OCR0B = 255;
		/*if(PIND & (1<<PD4)) {
			PCL++;
			if(PCL > 500)
			{
				if(pressed == 0)
				{
					motor++;
					pressed = 1;
				}
				PCL = 0;
			}
		}
		else{
			RCL++;
			if(RCL > 500)
			{
				pressed = 0;
				RCL = 0;
			}
		}
		if(motor == 4)
		{
			PORTB = 0x01;
			motorSet(0);
			while(1);
			motor = 0;
		}
		else{
			PORTB = 0x00;
		}*/
	}
	return 0;
}