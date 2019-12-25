#include "pch.h"
#include "stdafx.h"
#include "SimEeprom.h"
uint8_t EEvalue;
uint8_t myeeprom[15]={ 11,22,33,44,55,66,77,88,99,21,22,23,24,25};

uint8_t eeprom_read_byte(const uint16_t Waddress)
{
	//functionGroup = AdvIO_begin;
	//functionNo = REGread;
	//OUT_INT1 = Waddress;
	//SendingDueData();
	//ReceivingDaTa();
	EEvalue= myeeprom[Waddress];
	return EEvalue;
	//return IN_BYTE1;
}

void eeprom_write_byte(const uint16_t Waddress, uint8_t value)
{
	//functionGroup = AdvIO_begin;
	//functionNo = REGwrite;
	//OUT_INT1 = Waddress;
	//SendingDueData();	
	EEvalue = value;
	myeeprom [Waddress] = value;
}

