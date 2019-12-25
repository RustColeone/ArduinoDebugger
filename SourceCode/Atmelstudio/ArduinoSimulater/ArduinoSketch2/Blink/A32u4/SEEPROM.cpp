
#include "AdvIO.h"
#include <EEPROM.h>

extern uint8_t OUTdataArray[128];
extern uint8_t INdataArray[128];
extern EXdata	TPCEXcode;
extern EXdata	FPCEXcode;
extern EXDuedata DUEdata;

#ifdef esp8266
void EEPROMBEGIN(void)
{
	EEPROM.begin(IN_UINT1);
}

void EEPROMEND(void)
{
	EEPROM.end();
}
#endif



void EEPROMREAD(void)
{
	OUT_UBYTE2=EEPROM.read(IN_UINT1);
	Serial.write(&TPCEXcode.ByteData[0],8);
}

void EEPROMWRITE(void)
{
	EEPROM.write(IN_UINT1,IN_UBYTE2);
}




void REGISTERWRITE(void)
{	byte aa=IN_UBYTE5;
//DDRB = 0;
//PORTB = 0x55;
	if(aa==0x10)
		_SFR_IO8(IN_UBYTE4)=IN_UBYTE2;
	if(aa==0x20)
		_SFR_IO16(IN_UBYTE4)=IN_UBYTE2;
	if(aa==0x30)
		_SFR_MEM8(IN_UBYTE4)=IN_UBYTE2;
	if(aa==0x40)
		_SFR_MEM16(IN_UBYTE4)=IN_UBYTE2;	
}

void REGISTERREAD(void)
{	byte aa=IN_UBYTE5;
	if(aa==0x10)
		OUT_UBYTE2=_SFR_IO8(IN_UBYTE4);
	if(aa==0x20)
		OUT_UBYTE2=_SFR_IO16(IN_UBYTE4);
	if(aa==0x30)
		OUT_UBYTE2=_SFR_MEM8(IN_UBYTE4);
	if(aa==0x40)
		OUT_UBYTE2=_SFR_MEM16(IN_UBYTE4);
	Serial.write(&TPCEXcode.ByteData[0],8);
}
