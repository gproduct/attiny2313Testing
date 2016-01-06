
/*
INFO MOTHERF

If the motorpseed is 31 the brakspeed is motorspeed *1.2
brake delay is 500 and the brakmotor variable is 255


*/


#define F_CPU	11059200ULL
#define LEFT 1
#define RIGHT 0
#define CW 1
#define CCW 0

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "pwm.h"
	
	
int pressed = 0;
int PCL = 0;
int RCL = 0;
void motor(int side, int8_t speed, int direction)
{
	//0A white
		//1A right orange
		//0B keft orange
		//1B left
		//0b and 1b left motor
		/*OCR1A = 0;
		OCR0A = 255;
		OCR1B = 0;
		OCR0B = 255;*/
	if(side == LEFT)
	{
		if(direction == CW)
		{
			OCR1B = 0;
			OCR0B = speed;
		}
		else if(direction == CCW)
		{
			OCR1B = speed;
			OCR0B = 0;
		}
	}
	else if(side == RIGHT)
	{
		if(direction == CW)
		{
			OCR0A = 0;
			OCR1A = speed;
		}	
		else if(direction == CCW)
		{
			OCR0A = speed;
			OCR1A = 0;
		}
	}
}
int main(void){
	servo_init(50);
	while(1)
	{
		
		motor(LEFT, 255, CCW);
		motor(RIGHT,255,CW);
		//button presses
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