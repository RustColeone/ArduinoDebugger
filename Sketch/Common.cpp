
#include "Common.h"

uint8_t OUTdataArray[128];
uint8_t INdataArray[128];
EXdata		TPCEXcode;
EXdata		FPCEXcode;
EXDuedata	DUEdata;
Typecombine ESPTYPE;

void SendingData()
{//OUT_INTPT_Status=InterruptStatus;
Serial.write(&TPCEXcode.ByteData[0],8);
OUT_INTPT_Status=0;
//OUT_INTPT_Status	clear flat after interrupt
}
/*
byte SendingData(byte page)
{int count;
int loop;
int readoffset=0;
SendingData();
if(page>1)
	{TPCEXcode.ST.FunctionGroup = TPCEXcode.ST.FunctionGroup | page<<4;
	for(count=1;count<page;count++)
		{
			Serial.write(&INdataArray[readoffset],8);
			readoffset=readoffset+8;
		}
	}
	return 0;
}
*/
byte SendingArray(byte page)
{int count;
	int loop;
	int readoffset=0;	
	if(page>0)
	{
		for(count=0;count<page;count++)
		{
			Serial.write(&OUTdataArray[readoffset],8);
			readoffset=readoffset+8;
		}
	}
	return 0;
}



byte ReceivingData(void)
{
	int readoffset=0;
	int loop=0;
	int page;
	byte ca=Serial.available();
	int recode=ca;
	if(ca>0)
	{Serial.readBytes(FPCEXcode.ByteData,8);	//must do it
		loop = FPCEXcode.ST.FunctionGroup>>4;
		loop = loop & 0x7;
		if(loop==2)
		{do	{ca=Serial.available();
			if(ca>0)
			{recode=recode+ca;
				Serial.readBytes(DUEdata.ByteData,8);
				break;
			}
		}while(ca<=0);
	}
	if(loop>=4)
	{page=IN_UBYTE7;
		do	{ca=Serial.available();
			if(page==0) break;
		}while(ca<=0);
		if(ca>0)
		{recode=recode+ca;
			for(int count=0;count<page;count++)
			{Serial.readBytes(&INdataArray[readoffset],8);
				readoffset=readoffset+8;
			}
		}
	}
	if((FPCEXcode.ST.FunctionGroup & 0x80)!=0)
	SendingData();
}
return recode;
}
