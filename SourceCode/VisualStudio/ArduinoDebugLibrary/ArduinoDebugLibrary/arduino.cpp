#include "pch.h"
#include "stdafx.h"
#include "arduino.h"
#include "SimInterrupt.h"

int BoardType;
char OUTarray[128];
char INarray[128];
EXdata	FPCEXcode;
EXdata	TPCEXcode;
EXDuedata	DUEdata;
interrupststus	INTRRUPT;

Byte poolingcount=0;

voidv interruptfunction;
voidv onRequestfunction;
bytei onReceivefunction;
voidv SPI_Slave_interrupt;

InternalSerial MyPort;

bool TestComport()
{
	return MyPort.IsConnected();
}

/*
#define TX_Array		0b0001
#define TX_RX			0b0010
#define TX_DUE			0b0100
#define TX_TX			0b1000
*/

void SendingDataTimeout()
{
	
		FPCEXcode.ST.FunctionGroup = FPCEXcode.ST.FunctionGroup | 0x10;	//tx once	
		MyPort.WriteData(&FPCEXcode.ByteData[0], 8);
}

void SendingData()
{
	poolingcount++; //over 5 will request sent back
	if (poolingcount > 5 && INTRRUPT.BYTES != 0)
		{
		FPCEXcode.ST.FunctionGroup = FPCEXcode.ST.FunctionGroup | 0x90;	//0x0x90
		MyPort.WriteData(&FPCEXcode.ByteData[0], 8);
		ReceivingDaTa();
		poolingcount = 0;
		}
	else
	{
		FPCEXcode.ST.FunctionGroup = FPCEXcode.ST.FunctionGroup | 0x10;	//tx once	
		MyPort.WriteData(&FPCEXcode.ByteData[0], 8);
	}
}

void SendingData8266(char *buffer, unsigned int nbChar)
{
	MyPort.WriteData(buffer, nbChar);
}
//MyPort.ReadData(&INarray[offset], 8);
void ReceivingDaTa8266(char *buffer, unsigned int nbChar)
{
	int avaliable;
	do {
		avaliable = MyPort.ReadData(buffer, nbChar);
	} while (avaliable <= 0);	
}

void SendingDueData()
{
	poolingcount++;	//over 5 will request sent back
	if (poolingcount > 5 && INTRRUPT.BYTES != 0)
		FPCEXcode.ST.FunctionGroup = FPCEXcode.ST.FunctionGroup | 0xa0;	//0x0xA0		
	else
		FPCEXcode.ST.FunctionGroup = FPCEXcode.ST.FunctionGroup | 0x20;	
	MyPort.WriteData(&FPCEXcode.ByteData[0], 8);
	MyPort.WriteData(&DUEdata.ByteData[0], 8);
	if (poolingcount > 5 && INTRRUPT.BYTES != 0)
		ReceivingDaTa();
}

Byte SendingArray()
{
Byte page = OUT_BYTE7;
poolingcount++;	//over 5 will request sent back
if (poolingcount > 5 && INTRRUPT.BYTES != 0)
	FPCEXcode.ST.FunctionGroup = FPCEXcode.ST.FunctionGroup | 0xc0;	//0x0xC0
else
	FPCEXcode.ST.FunctionGroup = FPCEXcode.ST.FunctionGroup | 0x40;	
MyPort.WriteData(&FPCEXcode.ByteData[0], 8);
Byte count = 0;
int readoffset = 0;
	if (page > 8) page = 0;	//max 8 page
	for (count = 0; count <page; count++)	
		{	
			MyPort.WriteData(&OUTarray[readoffset], 8);
			readoffset = readoffset + 8;
		}
	if (poolingcount > 5 && INTRRUPT.BYTES != 0)
		ReceivingDaTa();
	return count;
}


void ReceivingDueDaTa()
{
	int avaliable;
	do {
		avaliable = MyPort.ReadData(&DUEdata.ByteData[0], 8);
	} while (avaliable <= 0);
}

void ReceivingDaTaTimeout()
{
	int timeout = 100;
	int avaliable;
	do {Sleep(1);
		avaliable = MyPort.ReadData(&TPCEXcode.ByteData[0], 8);
		if (timeout-- == 0) break;
	} while (avaliable <= 0);
}

void ReceivingDaTa()
{
	poolingcount = 0;
	
	int avaliable;
	do {avaliable = MyPort.ReadData(&TPCEXcode.ByteData[0], 8);
	} while (avaliable <= 0);	
/*	if (IN_Intpt_Action>0)
	{		
		if ((IN_Intpt_Action & 1) == 1)
			interruptfunction();			
		if ((IN_Intpt_Action & 2) == 2)
			onRequestfunction();
		if ((IN_Intpt_Action & 4) == 4)
			onReceivefunction(IN_Intpt_Status);
		if ((IN_Intpt_Action & 8) == 8)
			SPI_Slave_interrupt();
		IN_Intpt_Action = 0;
	}
*/
}

Byte ReceivingArray()
{
	int page;
	int count=0;
	int avaliable;
	long timeout=5000;	
	int offset = 0;
	ReceivingDaTa();
	page = ((IN_BYTE4-1)/8)+1;	
	if (page > 0)
	{
		for (count = 0; count < page; count++)
		{
			{timeout = 10;
			do	{
				avaliable = MyPort.ReadData(&INarray[offset], 8);
				offset = offset + 8;
					if (timeout--==0)
					{
						printf("Serial ID ->Serial<- reserved for debugging \n\r");
						printf("Arduino board Communication no response \n\r");
						printf("Reset Arduino board \n\r");
						break;
					}
				} while (avaliable == 0);
			}
		}
	}
	return count;	//Single byte return value;
}

unsigned long ReceivingCountTime(unsigned long loop, unsigned long timeconstant)
{	
	unsigned long timecount;
	if (timeconstant == 0)
		{if(OUT_ULONG==1000)
			loop = 10000000;
		else
			{printf("Time setup not installed\n\r");
			loop = 460000;	//for read feedback
			}
		}
	else   loop = (loop * timeconstant) / 1000;
	for (timecount = 0; timecount < loop; timecount++)
	{
		if (MyPort.ReadData(&DUEdata.ByteData[0], 8) >= 8)
			break;
	}
	return timecount;
}
