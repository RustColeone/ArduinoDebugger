#include "pch.h"
#include "stdafx.h"
#include "ArduinoDebugLibrary.h"

extern char OUTarray[128];
extern char INarray[128];
extern EXdata	FPCEXcode;
extern EXdata	TPCEXcode;
extern EXDuedata	DUEdata;

namespace ADL
{
	void SIM8266::BEGIN8266(char pin)
	{
		//beginTransaction(SPISettings(4000000, MSBFIRST, SPI_MODE0));
		//begin();
		functionGroup = ESP8266;
		functionNo = BEGIN_8266;
		OUT_BYTE4 = pin;
		SendingData();
	}


	void SIM8266::TX8266byte()
	{
		functionGroup = ESP8266;
		functionNo = WRITE_4BYTE;
		SendingData();
	}

	void SIM8266::RX8266byte()
	{
		functionGroup = ESP8266;
		functionNo = READ_4BYTE;
		SendingData();
		ReceivingDaTa();
	}

	void SIM8266::TX8266byte32()
	{
		functionGroup = ESP8266;
		functionNo = WRITE_32BYTE;
		SendingData();
		SendingData8266(OUTarray, 32);
	}

	void SIM8266::RX8266byte32()
	{
		functionGroup = ESP8266;
		functionNo = READ3_2BYTE;
		SendingData();
		ReceivingDaTa8266(INarray, 32);
	}
}
