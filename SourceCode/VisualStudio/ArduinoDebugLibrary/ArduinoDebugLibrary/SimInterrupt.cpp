#include "pch.h"
#include "stdafx.h"
#include "SimInterrupt.h"
//#include "SimGPIO.h"
#include <stdio.h>


extern interrupststus	INTRRUPT;


extern voidv interruptfunction;

void defaultpt(void)
{
	printf("interrup error\n\r");
	INTRRUPT.Bits.interruptststus = 0;
}


void defaultSpi(void)
{
	printf("SPI slave interrup error\n\r");
	INTRRUPT.Bits.interruptststus = 0;
}

void noInterrupts(void)
{
	INTRRUPT.Bits.interruptststus = 0;
	functionGroup = Gpio;
	functionNo = interruptOff;
	SendingData();
}
void interrupts(void)
{
	INTRRUPT.Bits.interruptststus = 1;
	functionGroup = Gpio;
	functionNo = interruptOn;
	SendingData();
}

void attachInterrupt(Byte pt1, voidv pt,Byte WaveFormCHANGE)	//set as gpio function
{
	if ((pt1 >= 0 && pt1 <= 3) || pt1 == 7)
	{		
		functionGroup = Gpio;
		functionNo = interruptAct;
		interruptfunction = pt;
		OUT_BYTE2 = pt1;
		OUT_BYTE3 = WaveFormCHANGE;
		SendingData();
		printf("Interrupt installed \n\r");		
	}
	else
		printf("Interrupt Pin not in the range 0,1,2,3 & 7\n\r");
}
