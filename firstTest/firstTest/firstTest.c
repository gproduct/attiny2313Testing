



#define F_CPU	11059200ULL
#define DEBOUNCE 10

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

	
		
void setup()
{
	
	DDRB = 0x01;
	
	DDRD &= ~(1<<PD4); //Define input on PC3
	PORTD |= (1<<PD4); // set pull up resistor
	
	GIMSK= 1 << INT1;						//turning on the interupt (GIMSK register)
	MCUCR = 1 << ISC01 | 1 << ISC00;		//rising edge
	
	sei();
}
int main(void){
	setup();
	int pressed = 0;
	int PCL = 0;
	int RCL = 0;
	
	while(1)
	{
		if(PIND & (1<<PD4)) {
			PCL++;
			if(PCL > 500)
			{
				if(pressed == 0)
				{
					PORTB = 0x01;
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
				PORTB = 0x00;
				RCL = 0;
			}
		}
	}
}