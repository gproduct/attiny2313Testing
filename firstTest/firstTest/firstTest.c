/*
 * firstTest.c
 *
 *  The first code that will run on my attint2313
 *  Author: Sili 
 */ 

#define F_CPU	11059200ULL
#define EPReg 0x0C

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void){
	unsigned char returned;
	PORTB = 0x01;
	EEPROM_write(EPReg, 0x01);
	returned = EEPROM_read(EPReg);
	if(returned == 0x01){
		PORTB = 0x01;
	}
	else{
		PORTB = 0x01;
	}
	while(1)
	{
		
		_delay_ms(1000);
	}
}
