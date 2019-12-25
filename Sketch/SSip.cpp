#include "SSip.h"
#include "Define.h"
#include <SPI.h>
 
extern uint8_t OUTdataArray[128];
extern uint8_t INdataArray[128];
extern EXdata		FPCEXcode;
extern EXdata		TPCEXcode;


#ifdef esp8266




#else
#ifdef debugging
IRS(SPI_STC_vect)		//SPI Slave interrupt
{
	OUT_INTPT_Status=OUT_INTPT_Status|8;
}
#endif

//SPISettings	mysettings(14000000, MSBFIRST, SPI_MODE0);
void S_begin(void)
{
SPI.begin();
OUT_UBYTE4=0xa5;
Serial.write(&TPCEXcode.ByteData[0],8);
}

void S_beginTransaction(void)
{
uint32_t Clock=IN_ULONG;
uint8_t BitOrder=IN_UBYTE2;
uint8_t DataMode=IN_UBYTE3;
SPISettings	mysettings(Clock, BitOrder,DataMode);
SPI.beginTransaction(mysettings);
}

void S_transfer(void)
{
	OUT_UBYTE4=SPI.transfer(IN_UBYTE4);	
	Serial.write(&TPCEXcode.ByteData[0],8);
}

void S_transferbuf(void)
{	
	SPI.transfer(INdataArray,IN_UBYTE4);
}

void S_endTransaction(void)
{
	SPI.endTransaction();
}



void S_end(void)
{
	SPI.end();
}

void S_setBitOrder(void)
{
	SPI.setBitOrder(IN_UBYTE4);	//bit order
}



void S_setDataMode(void)
{
	SPI.setDataMode(IN_UBYTE4); //data mode
}

void S_setClockDivider(void)
{
	SPI.setClockDivider(IN_UBYTE4); //Clock Divid
}


void S_SlaveInit32u4(void)
{//SPI.attachInterrupt(); 
	pinMode(MOSI, INPUT);	//16
	pinMode(MISO, OUTPUT);	//14
	pinMode(SCK, INPUT);	//15
	pinMode(SS, INPUT);		//17
	// enable SPI slave mode
	SPCR |= _BV(SPE);
	SPI.attachInterrupt();
	//IRS(SPI_STC_vect)
}


void SlaveTransfer(void)
{
SPDR = IN_UBYTE3;
OUT_UBYTE4 = SPDR;
}
#endif
