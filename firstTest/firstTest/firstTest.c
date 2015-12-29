



#define F_CPU	11059200ULL
#define DEBOUNCE 10

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

	
int pressed = 0;
int PCL = 0;
int RCL = 0;

int motor = -1;		
void setup()
{
	
	DDRB = 0x03;
	
	DDRD &= ~(1<<PD4); //Define input on PC3
	PORTD |= (1<<PD4); // set pull up resistor
}
int main(void){
	setup();
	while(1)
	{
		if(PIND & (1<<PD4)) {
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
			_delay_ms(500);
			motor = 0;
		}
		else{
			PORTB = 0x00;
		}
		
	}
}