#include "Common.h"
#include "Interrupt.h"
#include <EEPROM.h>
//#include <avr/boot.h>
extern uint8_t OUTdataArray[128];
extern uint8_t INdataArray[128];
extern EXdata	TPCEXcode;
extern EXdata	FPCEXcode;
extern byte Rxstatus;
extern byte InterruptEnable;
typedef void(*test_t)(void);

//Last modify 3/3/2019
//Default baud speed for communication

#ifdef esp8266
 pointer_to_function  my_fun_pointer[6][14]={
	 {PinMode,IORead,IOWrite,AnalogRead,AnalogWrite,Random,NoInterrupts,IntEnable,AttachInterrupt},
	 {_delayms,_micros,_millis},
	 {_noTone,_pulseIn,_pulseInLong,_shiftIn,_shiftOut,_tone,_tone1,Version,EEPROMWRITE,EEPROMREAD},//REGISTERWRITE,REGISTERREAD},		 
	 {W_begin,W_end,W_SetClock,W_beginTransmission,W_endTransmission,W_requestFrom,W_requestFrom1,W_write,W_available,W_read,W_peek,W_flush,WWinstaller},
  // {S_begin,S_beginTransaction,S_transfer,S_transferbuf,S_endTransaction,S_end,S_setBitOrder,S_setDataMode,S_setClockDivider},
   //{S_AVAILABLE,S_AVAILABLEFORWRITE,S_BEGIN,S_END,S_FLUSH,S_PEEK,S_READ,S_READBYTE,S_WRITE,S_PRINT},
 };
 #else
 pointer_to_function  my_fun_pointer[7][14]={
	 {PinMode,IORead,IOWrite,AnalogRead,AnalogWrite,Random,Handshaking,NoInterrupts,IntEnable,AttachInterrupt},//0
	 {_delayms,_micros,_millis,_getID},//1
	 {_noTone,_pulseIn,_pulseInLong,_shiftIn,_shiftOut,_tone,_tone1,Version,EEPROMWRITE,EEPROMREAD,REGISTERWRITE,REGISTERREAD},		//2
	 {S_AVAILABLE,S_AVAILABLEFORWRITE,S_BEGIN,S_END,S_FLUSH,S_PEEK,S_READ,S_READBYTE,S_WRITE,S_PRINT},//3 Serial
	 {S_begin,S_beginTransaction,S_transfer,S_transferbuf,S_endTransaction,S_end,S_setBitOrder,S_setDataMode,S_setClockDivider},	 //4 SPI
	 {W_begin,W_end,W_SetClock,W_beginTransmission,W_endTransmission,W_requestFrom,W_requestFrom1,W_write,W_available,W_read,W_peek,W_flush,WWinstaller},	 //5
	 {Begin8266,Write4byte,Read4byte,Write32byte,Read32byte},//6
 };
 #endif



//int bb,tt;
void setup()
{Serial.begin(BAUD);
//EEDR |= 2;
//EEDR |= EECR << 1;
//	Rxstatus= sizeof(unsigned long); 
/*
	int aa=0;
	EEPROM[10]=100;
	EEPROM[11]=101;
	EEPROM[12]=102;
	EEPROM[13]=103;
	EEPROM[14]=104;
	EEPROMWRITE();
	EEPROMWRITE();
	EEPROMWRITE();
	bb=EEPROM[10];
	bb=EEPROM[11];
	bb=EEPROM[12];
	bb=EEPROM[13];
	bb=EEPROM[14];
*/
}




void loop()
{
byte swcode=ReceivingData();
//if(InterruptEnable==1)
//NoInterrupts();
//interrupts();
if(swcode>0)//>=8
	{	
	my_fun_pointer[low4Bit(FPCEXcode.ST.FunctionGroup)][FPCEXcode.ST.FunctionNo]();
	swcode=0;
	}
}	
	
