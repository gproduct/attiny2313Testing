
/*
INFO MOTHERF

If the motorpseed is 31 the brakspeed is motorspeed *1.2
brake delay is 500 and the brakmotor variable is 255


*/


#define F_CPU	11059200ULL
#define DEBOUNCE 10
#define SLOW	50
#define NORMAL	190
#define FAST	250
#define MOTORSPEED 31
#define BRAKESPEED MOTORSPEED*1.1
#define BRAKEDELAY 100

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "pwm.h"
	
int pressed = 0;
int PCL = 0;
int RCL = 0;

int brake = 0;
int motor = -1;		
void motorSet(int speed)
{
	servo_position2(speed);
}
void brakeMotor(int speed)
{
	servo_position1(speed);
	_delay_ms(185);
	servo_position1(BRAKESPEED);
	
	while(1);
}
void setup()
{
	
	DDRB = 0x03;
	
	DDRD &= ~(1<<PD4); //Define input on PC3
	PORTD |= (1<<PD4); // set pull up resistor
}
int main(void){
	setup();
	servo_init(50);
	
	while(1)
	{
		motorSet(MOTORSPEED);
		_delay_ms(2000);
		brake = 1;
		if(brake == 1)
		{
			brakeMotor(255);
			brake = 0;
		}
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
}