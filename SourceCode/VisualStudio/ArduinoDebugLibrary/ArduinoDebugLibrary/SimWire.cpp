#include "pch.h"
#include "stdafx.h"
#include "ArduinoDebugLibrary.h"

extern voidv onRequestfunction;
extern bytei onReceivefunction;


void defaultReceivefunction(int a)
{
	printf("default Receive function\n\r");
}

void defaultRequestfunction(void)
{
	printf("default Request function\n\r");
}


namespace ADL {
	WWire::WWire()
	{
		onRequestfunction = defaultRequestfunction;
		onReceivefunction = defaultReceivefunction;
	}
/*
	WWire::~WWire()
	{
	}
*/
	void WWire::begin()
	{
		OUT_BYTE3 = 0;
		_BEGIN();
	}
	void WWire::begin(Uint8_t address)	//set slave address
	{
		OUT_BYTE4 = address;
		OUT_BYTE3 = 1;
		_BEGIN();
	}
	void WWire::begin(int address) //set slave address
	{
		OUT_INT1 = address;
		OUT_BYTE3 = 2;
		_BEGIN();
	}

	void WWire::_BEGIN(void)
	{
		functionGroup = WWire1;
		functionNo = WWbegin;
		SendingData();
	}


	void WWire::end() {
		functionGroup = WWire1;
		functionNo = WWend;
		SendingData();
	}

	void WWire::setClock(Uint32_t long1) {
		functionGroup = WWire1;
		functionNo = WWsetClock;
		OUT_ULONG = long1;
		SendingData();
	}

	void WWire::beginTransmission(Uint8_t data8) {
		functionGroup = WWire1;
		functionNo = WWbeginTransmission;
		OUT_BYTE4 = data8;
		OUT_BYTE3 = 0;
		SendingData();
	}
	void WWire::beginTransmission(int data16) {
		functionGroup = WWire1;
		functionNo = WWbeginTransmission;
		OUT_INT1 = data16;
		OUT_BYTE3 = 1;
		SendingData();
	}
	Uint8_t WWire::endTransmission(Uint8_t data8) {
		functionGroup = WWire1;
		functionNo = WWendTransmission;
		OUT_BYTE3 = 0;
		SendingData();
		return IN_BYTE4;
	}
	Uint8_t WWire::endTransmission(void) {
		functionGroup = WWire1;
		functionNo = WWendTransmission;
		OUT_BYTE3 = 1;
		SendingData();
		return IN_BYTE4;
	}
	Uint8_t WWire::requestFrom(Uint8_t data1, Uint8_t data2) {
		functionGroup = WWire1;
		functionNo = WWrequestFrom;
		OUT_BYTE4 = data1;
		OUT_BYTE5 = data2;
		OUT_BYTE3 = 0;
		SendingData();
		return IN_BYTE4;
	}
	Uint8_t WWire::requestFrom(Uint8_t data1, Uint8_t data2, Uint8_t data3) {
		functionGroup = WWire1;
		functionNo = WWrequestFrom;
		OUT_BYTE4 = data1;
		OUT_BYTE5 = data2;
		OUT_BYTE6 = data3;
		OUT_BYTE3 = 1;
		SendingData();
		return IN_BYTE4;
	}

	Uint8_t WWire::requestFrom(int int1, int int2) {
		functionGroup = WWire1;
		functionNo = WWrequestFrom;
		OUT_BYTE3 = 2;
		OUT_INT2 = int2;
		OUT_INT1 = int1;
		SendingData();
		return IN_BYTE4;
	}

	Uint8_t WWire::requestFrom(Uint8_t add, int int1, int int2) {
		functionGroup = WWire1;
		functionNo = WWrequestFrom;
		OUT_INT2 = int2;
		OUT_INT1 = int1;
		OUT_BYTE2 = add;
		OUT_BYTE3 = 3;
		SendingData();
		return IN_BYTE4;
	}

	Uint8_t WWire::requestFrom1(Uint8_t data1, Uint8_t data2, Uint32_t int1, Uint8_t data3, Uint8_t data4) {
		functionGroup = WWire1;
		functionNo = WWrequestFrom1;
		OUT_BYTE4 = data1;
		OUT_BYTE5 = data2;
		OUT_BYTE6 = data3;
		OUT_BYTE7 = data4;
		OUT_DUE_LONG1 = int1;
		SendingDueData();
		return IN_BYTE4;
	}

	Uint32_t WWire::write(Uint8_t data) {
		functionGroup = WWire1;
		functionNo = Wwrite;
		OUT_ULONG = data;
		OUT_BYTE3 = 0;
		SendingData();
		return IN_ULONG;
	}

	Uint32_t WWire::write(const Uint8_t *st) {
		functionGroup = WWire1;
		functionNo = Wwrite;
		OUT_BYTE3 = 1;
		byte n = sizeof(st);
		if (n > 100) n = 100;
		for (Uint32_t count = 0; count < n; count++)
			OUTarray[count] = st[count];
		SendingArray();
		return IN_ULONG;
	}


	Uint32_t WWire::write(const Uint8_t *st, Uint32_t n) {
		functionGroup = WWire1;
		functionNo = Wwrite;
		OUT_BYTE3 = 2;
		OUT_ULONG = n;
		if (n > 100) n = 100;
		for (Uint32_t count = 0; count < n; count++)
			OUTarray[count] = st[count];
		SendingArray();
		return IN_ULONG;
	}

	int WWire::available(void) {
		functionGroup = WWire1;		//get status
		functionNo = Wavailable;
		SendingData();		//updata status
		ReceivingDaTa();	//get status
		return IN_BYTE4;
	}
	int WWire::read(void) {
		functionGroup = WWire1;
		functionNo = Wread;
		SendingData();
		ReceivingDaTa();	//get status
		return IN_BYTE4;
	}
	int WWire::peek(void) {
		functionGroup = WWire1;
		functionNo = Wpeek;
		SendingData();
		return IN_BYTE4;
	}
	void WWire::flush(void) {
		functionGroup = WWire1;
		functionNo = Wflush;
		SendingData();
	}

	void WWire::Installer(void) {
		functionGroup = WWire1;
		functionNo = WWinstaller;
		SendingData();
	}

	//just put the function enter point for taking action
	void WWire::onReceive(bytei Receivefunction) {
		onReceivefunction = Receivefunction;
	}

	void WWire::onRequest(voidv Requestfunction) {
		onRequestfunction = Requestfunction;
	}
}
