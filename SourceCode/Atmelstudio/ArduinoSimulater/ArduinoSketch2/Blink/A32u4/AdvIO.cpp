
#include "AdvIO.h"
#include <EEPROM.h>

extern uint8_t OUTdataArray[128];
extern uint8_t INdataArray[128];
extern EXdata	TPCEXcode;
extern EXdata	FPCEXcode;
extern EXDuedata DUEdata;

typedef void(*reset_t)(void);

void _noTone(void)
{
	noTone(IN_UBYTE2);
}
void _pulseIn(void)
{
	OUT_ULONG=pulseIn(IN_UBYTE2,IN_UBYTE3,IN_ULONG);//value is high low	
	Serial.write(&TPCEXcode.ByteData[0],8);
}


void _pulseInLong(void)
{
	if(IN_ULONG>0)
	OUT_ULONG=pulseInLong(IN_UBYTE2,IN_UBYTE3,IN_ULONG);
	else
	OUT_ULONG=pulseInLong(IN_UBYTE2,IN_UBYTE3);
	Serial.write(&TPCEXcode.ByteData[0],8);
}

void _shiftIn(void)
{
OUT_UBYTE4=shiftIn(IN_UBYTE2,IN_UBYTE6,IN_UBYTE7);
Serial.write(&TPCEXcode.ByteData[0],8);
}

void _shiftOut(void)
{
shiftOut(IN_UBYTE2,IN_UBYTE6,IN_UBYTE7,IN_UBYTE3);
}

void _tone(void)
{	
	tone(IN_UBYTE2,IN_UINT1);
}

void _tone1(void)
{
	tone(IN_UBYTE2,IN_DUE_INT1,IN_ULONG);
}



void Version(void)
{
	OUT_ULONG=123;
	Serial.write(&TPCEXcode.ByteData[0],8);
}

