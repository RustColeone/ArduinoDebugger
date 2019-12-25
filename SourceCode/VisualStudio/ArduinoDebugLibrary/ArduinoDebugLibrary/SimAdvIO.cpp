#include "pch.h"
#include "stdafx.h"
#include <stdio.h>
#include "ArduinoDebugLibrary.h"

namespace ADL
{
/*
	AdvIO::AdvIO()
	{
	}


	AdvIO::~AdvIO()
	{
	}
*/

	void AdvIO::noTone(Byte pin)
	{
		functionGroup = AdvIO_begin;	//2
		functionNo = AnoTone;
		OUT_BYTE2 = pin;
		SendingData();
	}

	__int32 AdvIO::pulseIn(Byte pin, Byte HL, __int32 timeout)
	{
		functionGroup = AdvIO_begin;
		functionNo = ApulseIn;
		OUT_BYTE2 = pin;
		OUT_BYTE3 = HL;
		OUT_ULONG = timeout;
		SendingData();
		ReceivingDaTa();
		return IN_ULONG;
	}

	__int32 AdvIO::pulseInLong(Byte pin, Byte HL)
	{
		return pulseInLong(pin, HL, 1000000);
	}

	__int32 AdvIO::pulseInLong(Byte pin, Byte HL, __int32 timeout)
	{
		functionGroup = AdvIO_begin;
		functionNo = ApulseInLong;
		OUT_ULONG = timeout;
		OUT_BYTE2 = pin;
		OUT_BYTE3 = HL;
		SendingData();
		ReceivingDaTa();
		return IN_ULONG;
	}
	Byte AdvIO::shiftIn(Byte dataPin, Byte clockPin, Byte bitOrder)
	{
		functionGroup = AdvIO_begin;
		functionNo = AshiftIn;
		OUT_BYTE7 = bitOrder;
		OUT_BYTE6 = clockPin;
		OUT_BYTE2 = dataPin;
		SendingData();
		ReceivingDaTa();
		printf("Shift in =%d", IN_BYTE4);
		return IN_BYTE4;
	}
	void AdvIO::shiftOut(Byte dataPin, Byte clockPin, Byte bitOrder, Byte value)
	{
		functionGroup = AdvIO_begin;
		functionNo = AshiftOut;
		OUT_BYTE7 = bitOrder;
		OUT_BYTE6 = clockPin;
		OUT_BYTE2 = dataPin;
		OUT_BYTE3 = value;
		SendingData();
	}

	void AdvIO::tone(Byte pin, Uint16_t tone)
	{
		functionGroup = AdvIO_begin;
		functionNo = Atone;
		OUT_BYTE2 = pin;
		OUT_ULONG = tone;
		SendingData();
	}

	void AdvIO::tone(Byte pin, Uint16_t tone, Ulong MSduration)
	{
		functionGroup = AdvIO_begin;
		functionNo = Atone1;
		OUT_BYTE2 = pin;
		OUT_ULONG = MSduration;
		OUT_DUE_INT1 = tone;
		SendingDueData();
	}

	__int32 AdvIO::version(void)
	{
		functionGroup = AdvIO_begin;
		functionNo = Version;
		SendingDueData();
		ReceivingDaTa();
		return IN_ULONG;
	}

	void AdvIO::EEPROMWRITE(const __int16 Waddress, Byte value)
	{
		functionGroup = AdvIO_begin;
		functionNo = EEwrite;
		OUT_INT1 = Waddress;
		OUT_BYTE2 = value;
		SendingDueData();		
	}

	Byte AdvIO::EEPROMREAD(const __int16 Waddress)
	{
		functionGroup = AdvIO_begin;
		functionNo = EEread;
		OUT_INT1 = Waddress;
		SendingDueData();
		ReceivingDaTa();	
		return IN_BYTE2;
	}


	void AdvIO::REGISTERWRITE(const __int16 Waddress, Byte value)
	{
		functionGroup = AdvIO_begin;
		functionNo = REGwrite;
		OUT_INT1 = Waddress;	//Registor+data+4+1015
		OUT_BYTE2 = value;
		SendingDueData();	
	}
	
	Byte AdvIO::REGISTERREAD(const __int16 Waddress)
	{
		functionGroup = AdvIO_begin;
		functionNo = REGread;
		OUT_INT1 = Waddress;	//Registor+data+4+5
		SendingDueData();
		ReceivingDaTa();
		return IN_BYTE2;
	}
}
