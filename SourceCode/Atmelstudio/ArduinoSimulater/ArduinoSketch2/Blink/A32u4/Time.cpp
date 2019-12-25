#include "Time.h"
#include "Define.h"
extern uint8_t OUTdataArray[128];
extern uint8_t INdataArray[128];
extern EXdata	FPCEXcode;
extern EXdata	TPCEXcode;
extern EXDuedata DUEdata;

void _delayms(void)
{
	delay(IN_ULONG);  
	Serial.write(&TPCEXcode.ByteData[0],8);
}

void _micros(void)
{
	OUT_ULONG=micros();
	Serial.write(&TPCEXcode.ByteData[0],8);
}

void _millis(void)
{
	OUT_ULONG=millis();
	Serial.write(&TPCEXcode.ByteData[0],8);
}

void _getID(void)
{
	#ifdef  UNO
	OUT_ULONG=123;
	#endif
	
	#ifdef  leonardo
	OUT_ULONG=456;
	#endif
	Serial.write(&TPCEXcode.ByteData[0],8);
}