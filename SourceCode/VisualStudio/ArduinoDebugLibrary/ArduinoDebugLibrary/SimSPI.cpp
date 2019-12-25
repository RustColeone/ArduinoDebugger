#include "pch.h"
#include "stdafx.h"
#include "ArduinoDebugLibrary.h"

//SPIClass SPI;
namespace ADL {

	void SPIClass::begin()
	{
		functionGroup = SPIport;
		functionNo = SPIbegin;
		SendingData();
		ReceivingDaTa();
		if (IN_BYTE4 == 0xa5)
			printf("SIP begin\n\r");
	}

	void SPIClass::beginTransaction(SPISettings settings) {
		functionGroup = SPIport;
		functionNo = SPIbeginTransaction;
		//OUT_ULONG = clock;
		//OUT_data5 = bitOrder;
		//OUT_data6 = dataMode;
		SendingData();
	}


	Uint8_t SPIClass::transfer(Uint8_t data)
	{
		functionGroup = SPIport;
		functionNo = SPItransfer;
		OUT_BYTE4 = data;
		SendingData();
		ReceivingDaTa();
		return IN_BYTE4;
	}

	void SPIClass::transfer(char * st, Ulong count)
	{
		functionGroup = SPIport;
		functionNo = SPItransferbuf;
		OUT_ULONG = count;
		SendingData();	//add string inside
		SendingArray();
	}


	void SPIClass::endTransaction(void)
	{
		functionGroup = SPIport;
		functionNo = SPIendTransaction;
		SendingData();
	}


	void SPIClass::end() {
		functionGroup = SPIport;
		functionNo = SPIend;
		SendingData();
	}

	void SPIClass::setBitOrder(Uint8_t bitOrder)
	{
		functionGroup = SPIport;
		functionNo = SPIsetBitOrder;
		OUT_INT1 = bitOrder;
		SendingData();
	}

	void SPIClass::setDataMode(Uint8_t dataMode)
	{
		functionGroup = SPIport;
		functionNo = SPIsetDataMode;
		OUT_INT1 = dataMode;
		SendingData();
	}

	void SPIClass::setClockDivider(Uint8_t clockDiv)
	{
		functionGroup = SPIport;
		functionNo = SPIsetClockDivider;
		OUT_INT1 = clockDiv;
		SendingData();
	}


	void SPIClass::SPISlaveInit(void)
	{
		functionGroup = SPIport;
		functionNo = SPI_SlaveInit;
		SendingData();
	}

	Byte SPIClass::SPISlaveTransfer(Byte Data)
	{
		functionGroup = SPIport;
		functionNo = SPI_SlaveTransfer;
		OUT_BYTE3 = Data;
		SendingData();
		ReceivingDaTa();
		return IN_BYTE4;
	}
}

