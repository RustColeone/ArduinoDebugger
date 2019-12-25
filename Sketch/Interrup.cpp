#include "Interrupt.h"
extern uint8_t OUTdataArray[128];
extern uint8_t INdataArray[128];
extern EXdata	TPCEXcode;
extern EXdata	FPCEXcode;
extern EXDuedata DUEdata;
byte		InterruptStatus;
byte		InterruptEnable;

void Int_Action(void)
{
	if(InterruptEnable==1)
		OUT_INTPT_Status=OUT_INTPT_Status|1;
}

void NoInterrupts(void)
{
	OUT_INTPT_Status=0;
	InterruptEnable=0;
	noInterrupts();
}

void IntEnable(void)
{
	OUT_INTPT_Status=0;
	InterruptEnable=1;
	interrupts();
}

void AttachInterrupt(void)
{
	OUT_INTPT_Status=0;
	attachInterrupt(IN_UBYTE2,Int_Action,IN_UBYTE3);
	//attachInterrupt(digitalPinToInterrupt(3),Int_Action,2);
	//noInterrupts();
}

//detachinterrupt()