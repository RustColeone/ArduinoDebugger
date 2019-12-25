#include "ESP8266int.h"
extern uint8_t OUTdataArray[128];
extern uint8_t INdataArray[128];
extern EXdata	TPCEXcode;
extern EXdata	FPCEXcode;
extern EXDuedata DUEdata;
extern Typecombine ESPTYPE; 
 char outbuffer[40]; 
 char intbuffer[40];
ESPCOM::ESPCOM(){};
void ESPCOM::BEGIN8266()	
{
	pinMode(IN_UBYTE4, OUTPUT);
	pin=IN_UBYTE4;
	SPI.beginTransaction(SPISettings(1400000, MSBFIRST, SPI_MODE0));
	SPI.begin();
}

	
void ESPCOM::WRITE4BYTE()	 
{
	digitalWrite(pin, LOW);	
	SPI.transfer(0x1);		//Send status
	SPI.transfer(IN_UBYTE4);		
	SPI.transfer(IN_UBYTE5);
	SPI.transfer(IN_UBYTE6);
	SPI.transfer(IN_UBYTE7);			 			
	digitalWrite(pin, HIGH);
}

void ESPCOM::READ4BYTE()
{
	digitalWrite(pin, LOW);
	SPI.transfer(0x04);
	OUT_UBYTE4 = SPI.transfer(0);
	OUT_UBYTE5 = SPI.transfer(0);
	OUT_UBYTE6 = SPI.transfer(0);
	OUT_UBYTE7 = SPI.transfer(0);	
	digitalWrite(pin, HIGH);
	SendingData();
}

void ESPCOM::WRITE32BYTE()	 
{byte ca;
do	{ca=Serial.available();
		if(ca>0)
		{Serial.readBytes(INdataArray,32);
		break;
		}
	}while(ca<=0);
	digitalWrite(pin, LOW);
	SPI.transfer(0x02);
	SPI.transfer(0x00);	
	for (int g = 0; g < 32; g++)
		{
		SPI.transfer(INdataArray[g]);
		}
	digitalWrite(pin, HIGH);
}	

void ESPCOM::READ32BYTE()
{	
	digitalWrite(pin, LOW);
	SPI.transfer(0x03);
	SPI.transfer(0x00);
	for (int gg = 0; gg < 32; gg++)
		{
		intbuffer[gg] = SPI.transfer(0);
		ESPTYPE.ULONG=10;
		}
	digitalWrite(pin, HIGH);
	Serial.write(intbuffer,32);
}

ESPCOM esp8266com;

void Read4byte()
{
	esp8266com.READ4BYTE();
}

void Write4byte()
{
	esp8266com.WRITE4BYTE();
}

void Read32byte()
{
	esp8266com.READ32BYTE();
}

void Write32byte()
{
	esp8266com.WRITE32BYTE();
}

void Begin8266()
{
	esp8266com.BEGIN8266();
}