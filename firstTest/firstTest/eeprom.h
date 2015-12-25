/*
 * eeprom.h
 *
 * Created: 12/22/2015 9:31:59 PM
 *  Author: Sili
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

void EEPROM_write(unsigned int uiAddress, unsigned char ucData);
unsigned char EEPROM_read(unsigned int uiAddress);
unsigned char checkEEPROM(unsigned char address);

#endif /* EEPROM_H_ */