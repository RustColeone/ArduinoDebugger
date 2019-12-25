///////////////////////////////////////////////////////////
//
//
//Change Define.h for Leonado or uno
//
///////////////////////////////////////////////////////////
#include "Common.h"
#include "Interrupt.h"

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


pointer_to_function  my_fun_pointer[7][14]={
	 {PinMode,IORead,IOWrite,AnalogRead,AnalogWrite,Random,Handshaking,NoInterrupts,IntEnable,AttachInterrupt},//0
	 {_delayms,_micros,_millis,_getID},//1
#ifdef	 SAMD21 
	 {_noTone,_pulseIn,_pulseInLong,_shiftIn,_shiftOut,_tone,_tone1,Version},//EEPROMWRITE,EEPROMREAD,REGISTERWRITE,REGISTERREAD},		//2
#else
  #ifdef esp8266
   {_noTone,_pulseIn,_pulseInLong,_shiftIn,_shiftOut,_tone,_tone1,Version,EEPROMWRITE,EEPROMREAD},//REGISTERWRITE,REGISTERREAD},    //2
  #else
   {_noTone,_pulseIn,_pulseInLong,_shiftIn,_shiftOut,_tone,_tone1,Version,EEPROMWRITE,EEPROMREAD,REGISTERWRITE,REGISTERREAD},    //2
  #endif 
#endif  
	 {S_AVAILABLE,S_AVAILABLEFORWRITE,S_BEGIN,S_END,S_FLUSH,S_PEEK,S_READ,S_READBYTE,S_WRITE,S_PRINT},//3 Serial
	 {S_begin,S_beginTransaction,S_transfer,S_transferbuf,S_endTransaction,S_end,S_setBitOrder,S_setDataMode,S_setClockDivider},	 //4 SPI
	 {W_begin,W_end,W_SetClock,W_beginTransmission,W_endTransmission,W_requestFrom,W_requestFrom1,W_write,W_available,W_read,W_peek,W_flush,WWinstaller},	 //5
	 {Begin8266,Write4byte,Read4byte,Write32byte,Read32byte},//6
 };




//int bb,tt;
void setup()
{Serial.begin(115200);//BAUD
//EEDR |= 2;
//EEDR |= EECR << 1;
//	Rxstatus= sizeof(unsigned long); 
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
	
