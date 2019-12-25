#include "WWire.h"
extern uint8_t OUTdataArray[128];
extern uint8_t INdataArray[128];
extern EXdata	TPCEXcode;
extern EXdata	FPCEXcode;
extern EXDuedata DUEdata;
extern EXDuedata DUEdata;
extern	SimStatus	BitStatus;

typedef void(*Reqhandle)(void);
typedef void(*RecHandle)(int);
Reqhandle	myhandle;
RecHandle   rehandle;

int a;
void W_begin(void)
{
#ifndef SAMD21
if(IN_UBYTE3 == 0)	Wire.begin();
if(IN_UBYTE3 == 1)	Wire.begin(IN_UBYTE4);
if(IN_UBYTE3 == 2)	Wire.begin(IN_UINT1);
#endif
WWinstaller();
	//OUT_UBYTE4=0xa5;
	//Serial.write(&TPCEXcode.ByteData[0],8);	
}

void W_end(void)
{
a=10;
#ifdef esp8266
#else
//*//	Wire.end();
#endif 
}

void W_SetClock(void)
{
//*//	Wire.setClock(IN_ULONG);
}


void W_beginTransmission(void)
{
//*//	if(IN_UBYTE3 == 0) Wire.beginTransmission(IN_UBYTE4);
//*//	if(IN_UBYTE3 == 1) Wire.beginTransmission(IN_UINT1);	
}


void W_endTransmission(void)
{	
  //*//if(IN_UBYTE3 == 0)
	//*//OUT_UBYTE4 = Wire.endTransmission();
//*//	else
//*//	OUT_UBYTE4 = Wire.endTransmission(IN_UBYTE3);
	Serial.write(&TPCEXcode.ByteData[0],8);	
}


	//OUT_BYTE = Wire.requestFrom(IN_addr,IN_quantity);	
	//OUT_BYTE = Wire.requestFrom(IN_addr,IN_quantity,IN_stop);

void W_requestFrom(void)
{	
//*// if(IN_UBYTE3 == 0)		OUT_UBYTE4=Wire.requestFrom(IN_UBYTE4,IN_UBYTE5);
//*//	if(IN_UBYTE3 == 1)		OUT_UBYTE4=Wire.requestFrom(IN_UBYTE4,IN_UBYTE5,IN_UBYTE6);
//*//	if(IN_UBYTE3 == 2)		OUT_UBYTE4=Wire.requestFrom(IN_UINT1,IN_UINT2);
//*//	if(IN_UBYTE3 == 3)		OUT_UBYTE4=Wire.requestFrom((int)IN_UBYTE2,IN_UINT1,IN_UINT2);
	Serial.write(&TPCEXcode.ByteData[0],8);
}

#ifdef esp8266
void W_requestFrom1(void)
{
  Serial.write(&TPCEXcode.ByteData[0],8);
}
#else
void W_requestFrom1(void)
{
//*//	OUT_UBYTE4=Wire.requestFrom(IN_UBYTE4,IN_UBYTE5,OUT_DUE_ULONG1,IN_UBYTE6,IN_UBYTE7);
	Serial.write(&TPCEXcode.ByteData[0],8);
}
#endif
void W_write(void)
{
//*//  if(IN_UBYTE3==0)
//*//		OUT_ULONG=Wire.write(IN_ULONG);
//*//	if(IN_UBYTE3==1)
//*//		OUT_ULONG=Wire.write((char *)INdataArray);
//*//	if(IN_UBYTE3==2)
//*//		OUT_ULONG=Wire.write((char *)INdataArray,IN_UBYTE3);
//*//	Serial.write(&TPCEXcode.ByteData[0],8);
}

void W_available(void)
{
//*//	OUT_UBYTE4=Wire.available();
	Serial.write(&TPCEXcode.ByteData[0],8);
}


void W_read(void)
{
//*//	OUT_UBYTE4=Wire.read();
	Serial.write(&TPCEXcode.ByteData[0],8);
}

void W_peek(void)
{
  //*//Wire.peek();
}

void W_flush(void)
{
  //*//Wire.flush();
}


void requestEvent() {
	OUT_INTPT_Status=OUT_INTPT_Status|2;
}

void receiveEvent(int howMany) {
	OUT_INTPT_Action=howMany;
	OUT_INTPT_Status=OUT_INTPT_Status|4;	
}

//Registers a function to be called when a slave device receives a transmission from a master. 
void WWinstaller(void)
{
//*//Wire.onReceive(receiveEvent); //Wire.onReceive(takeAction);
//*//Wire.onRequest(requestEvent); //Wire.onRequest(takeAction);
}
