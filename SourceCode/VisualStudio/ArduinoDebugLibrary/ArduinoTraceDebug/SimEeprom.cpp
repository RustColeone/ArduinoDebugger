#include "pch.h"
#include "SimEeprom.h"
#include "ArduinoDebugLibrary.h"
#include "ArduinoTraceDebug.h"
uint8_t EEvalue;
uint8_t myeeprom[100]={ 11,22,33,44,55,66,77,88,99,21,22,23,24,25};

uint8_t eeprom_read_byte(const uint16_t Waddress)
{
#ifdef trueeeprom
	EEvalue = AVIO.EEPROMREAD(Waddress);
#else
	EEvalue= myeeprom[Waddress];	
#endif
	return EEvalue;
}

void eeprom_write_byte(const uint16_t Waddress, uint8_t value)
{
#ifdef trueeeprom
	AVIO.EEPROMWRITE(Waddress,value);
#else
	EEvalue = value;
	myeeprom [Waddress] = value;
#endif
}

