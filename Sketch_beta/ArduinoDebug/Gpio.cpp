#include "Gpio.h"  
extern uint8_t OUTdataArray[128];
extern uint8_t INdataArray[128];
extern EXdata	TPCEXcode;
extern EXdata	FPCEXcode;
extern EXDuedata DUEdata;

extern byte		InterruptStatus;
/*
#define		pin	 FPCEXcode.ST.COMB.BYTE[4]
#define		Mode FPCEXcode.ST.COMB.BYTE[5]
#define		TPC_BYTE TPCEXcode.ST.COMB.BYTE[0]		
#define		FPC_MAX_32	DUEdata.ST.COMB[0].UUINT32
#define		FPC_MIN_32	DUEdata.ST.COMB[1].UUINT32
*/
			//VerifyReturn=FunctionType;



void PinMode(void)
{
	pinMode(IN_UBYTE2,IN_UBYTE3);
}
void IORead(void)
{	
	OUT_UBYTE2 = digitalRead(IN_UBYTE2);	
	SendingData();
}
void IOWrite(void)
{
digitalWrite(IN_UBYTE4,IN_UBYTE5);
}
void AnalogRead(void)
{	
#ifdef esp8266
	analogRead(A0);
#else
	OUT_UBYTE2 = analogRead(IN_UBYTE2);
#endif
	SendingData();
}

void AnalogWrite(void)
{
	analogWrite(IN_UBYTE2,IN_UBYTE3);	
}

void Random(void)
{
	DUEdata.ST.COMB[0].ULONG=random(OUT_DUE_ULONG2,OUT_DUE_ULONG1);	
	SendingData();
}

void Handshaking(void)
{
	OUT_ULONG=15542933;	
	SendingData();
}

/*
void intfunction(void)
{
	//tell PC interrupt installed
	InterruptStatus=1;
	OUT_INTPT_Action=1;
}


void AttachInterrupt(void)
{
	attachInterrupt(IN_pin5,intfunction,IN_mode6);
	OUT_INTPT_Status=1;
}

void NoInterrupt(void)
{
	noInterrupts();
	OUT_INTPT_Status=0;
}
*/
