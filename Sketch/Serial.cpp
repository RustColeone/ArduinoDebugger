#include "Serial.h"  
#include "Define.h"

extern uint8_t OUTdataArray[128];
extern uint8_t INdataArray[128];
extern EXdata		FPCEXcode;
extern EXdata		TPCEXcode;

#ifdef UNO
//#include "..\..\..\ArduinoSketch2\ArduinoCore\include\libraries\SoftwareSerial\src\SoftwareSerial.h"
#include "SoftwareSerial.h"
SoftwareSerial MySerial(2, 3); // RX, TX
#endif
int testbyte;


#ifdef esp8266
#else
void S_IF(void)
{
}
void S_AVAILABLE(void)
{
	OUT_UBYTE4=DebugSerial.available();	
	DebugSerial.write(&TPCEXcode.ByteData[0],8);
}
void S_AVAILABLEFORWRITE(void)
{
	OUT_UBYTE4=DebugSerial.availableForWrite();	
	DebugSerial.write(&TPCEXcode.ByteData[0],8);
}


void S_BEGIN(void)
{	
if(IN_UBYTE3 ==1)  DebugSerial.begin(IN_ULONG);
#ifdef leonardo
if(IN_UBYTE3 ==0)	DebugSerial.begin(IN_ULONG,(unsigned char)IN_UBYTE4);
#endif
}

void S_END(void)
{DebugSerial.end();
}


void S_FLUSH(void)
{
DebugSerial.flush();
}

void S_PEEK(void)
{
OUT_UBYTE4=DebugSerial.peek();
SendingData();
}
void S_PRINT(void)	//println and write
{
byte type=IN_UBYTE3 & 0x1f;
byte mode=IN_UBYTE3>>5;
if(mode==1)		OUT_UBYTE4=DebugSerial.print(IN_ULONG,type);
if(mode==2)		OUT_UBYTE4=DebugSerial.print(IN_ULONG,type);	//printer character
if(mode==3)		OUT_UBYTE4=DebugSerial.println(IN_ULONG,type);
if(mode==4)		OUT_UBYTE4=DebugSerial.print(IN_FLOAT,type);
//if(mode==5)		OUT_UBYTE1=Serial1.println(IN_ULONG,type);
if(mode==6)		OUT_UBYTE4=DebugSerial.write(IN_UBYTE4);
SendingData();
}

void S_READ(void)
{
OUT_UBYTE4=DebugSerial.read();
SendingData();
}
void S_READBYTE(void)
{int bytecount;
OUT_UBYTE4 = DebugSerial.readBytes(OUTdataArray,IN_UINT1);
bytecount=OUT_UBYTE4;
bytecount=((bytecount-1)/8)+1;
testbyte=bytecount;
SendingData();
SendingArray(bytecount);
}

void S_WRITE(void)
{
OUT_UBYTE4=DebugSerial.write(INdataArray,IN_UINT1);
SendingData();
}

#endif
