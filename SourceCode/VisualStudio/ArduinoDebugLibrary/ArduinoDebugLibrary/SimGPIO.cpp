#include "pch.h"
#include "stdafx.h"
#include "ArduinoDebugLibrary.h"
#include <stdio.h>



namespace ADL {
/*
	GPIO::GPIO()
	{
	}


	GPIO::~GPIO()
	{
	}
*/


	void GPIO::pinMode(Byte pin, Byte mode)
	{
		functionGroup = Gpio;
		functionNo = PinMode;
		OUT_BYTE2 = pin;
		OUT_BYTE3 = mode;
		SendingData();
	}
	void GPIO::digitalWrite(Byte pin, Byte data)
	{
		functionGroup = Gpio;
		functionNo = IOWrite;
		OUT_BYTE4 = pin;
		OUT_BYTE5 = data;
		SendingData();
	}
	Byte GPIO::digitalRead(Byte pin)
	{
		functionGroup = Gpio;
		functionNo = IORead;
		OUT_BYTE2 = pin;
		SendingData();
		ReceivingDaTa();
		printf("Read Value = %d\n\r", IN_BYTE2);
		return IN_BYTE2;
	}

	Byte GPIO::analogRead(Byte analogPin)
	{
		functionGroup = Gpio;
		functionNo = AnalogRead;
		OUT_BYTE2 = analogPin;
		SendingData();
		ReceivingDaTa();
		printf("AnalogRead = %d\n\r", IN_BYTE2);
		return IN_BYTE2;
	}

	void GPIO::analogWrite(Byte analogPin, Byte value)
	{
		functionGroup = Gpio;
		functionNo = AnalogWrite;
		OUT_BYTE2 = analogPin;
		OUT_BYTE3 = value;
		SendingData();
	}




	Ulong GPIO::Random(Ulong min, Ulong max)
	{
		functionGroup = Gpio;
		functionNo = random;
		OUT_DUE_LONG1 = max;
		OUT_DUE_LONG2 = min;
		SendingDueData();
		ReceivingDueDaTa();
		return OUT_DUE_LONG1;
	}

	Ulong GPIO::Random(Ulong max)
	{
		return Random(0, max);
	}

	long  GPIO::map(long x, long in_min, long in_max, long out_min, long out_max)
	{
		return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
	}

}
