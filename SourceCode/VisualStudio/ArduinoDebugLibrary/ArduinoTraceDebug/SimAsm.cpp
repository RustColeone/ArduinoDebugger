#include "pch.h"
#include "SimAsm.h"
#include "ArduinoDebugLibrary.h"
#include "ArduinoTraceDebug.h"
uint8_t REGvalue;

uint8_t Register_read_byte(const uint16_t Waddress)
{
	REGvalue=AVIO.REGISTERREAD(Waddress);
	return REGvalue;
}

void Register_write_byte(const uint16_t Waddress, uint8_t value)
{	
	AVIO.REGISTERWRITE(Waddress, value);
}