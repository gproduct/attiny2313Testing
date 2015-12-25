/*
 * eeprom.c
 *
 * Created: 12/22/2015 9:31:17 PM
 *  Author: Sili
 */
#define F_CPU	11059200ULL

#include "eeprom.h" 
#include <avr/io.h>
#include <util/delay.h>

void EEPROM_write(unsigned int uiAddress, unsigned char ucData)
{
	while(EECR & ( 1 << EEPE));//waiting for the completion of the prevoious write
	
	//setting address and data
	EEAR = uiAddress;
	EEDR = ucData;
	
	//writing logical one to EEMPE
	EECR |= (1<<EEMPE);
	
	//start eeprom write by setting eepe
	EECR |= (1<<EEPE);
}
unsigned char EEPROM_read(unsigned int uiAddress)
{
	//waiting for the previous write
	while(EECR & (1 << EEPE));
	
	//setting up the address register
	EEAR = uiAddress;
	
	//start reading with EERE
	EECR |= (1 << EERE);
	//return
	return EEDR;
}

unsigned char checkEEPROM(unsigned char address)
{
	unsigned char returned;
	returned = EEPROM_read(address);
	
	if(returned == 0x11 || returned == 0x22 || returned == 0x33)													//custom part
	{
		if(returned == 0x11){
			return 0x11;
		}
		else if(returned == 0x22){
			return 0x22;
		}
		else if(returned == 0x33){
			return 0x33;
		}
	}
	else{ return 0x00;}
}