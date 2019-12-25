#include "pch.h"
#include "stdafx.h"
#include "ArduinoDebugLibrary.h"
#include "arduino.h"
#include <stdio.h>



namespace ADL {
//	Time::Time(){}
//	Time::~Time(){}

	long Time::delay100ms;
	unsigned long Time::delay1000ms;
	unsigned long Time::delay1ms;

	void Time::TimeSetup()
	{		
		functionGroup = Time_begin;
		functionNo = Delay10ms;
		OUT_ULONG = 1000;	//count for 100 ms		
		SendingData();
		delay1000ms = ReceivingCountTime();
		delay1ms = delay1000ms / 1000;
		if(delay1000ms<1000)
			printf("Setup failure\n\r");
		else
		{
			printf("Delay constant installed %d\n\r", delay1000ms);
			functionGroup = Time_begin;
			functionNo = GETID;
			SendingData();
			ReceivingDaTa();
			if (IN_ULONG == 123)
				printf("Arduino UNO connected\n\r");
			if (IN_ULONG == 456)
				printf("Arduino Leonardo connected\n\r");
			if (IN_ULONG == 789)
				printf("ESP8266 E12 connected\n\r");
			if (IN_ULONG == 345)
				printf("Arduino M) SAMD12 connected\n\r");
		}
	}

	void Time::delay(__int16 ms)
	{
		functionGroup = Time_begin;
		functionNo = Delay10ms;
		OUT_ULONG = ms;	//count for 100 ms		
		SendingData();
		ReceivingDaTa();		
	}

	void Time::idelay(__int16 ms)
	{
		//__int16 msdelay = delay100ms / 100;
		ReceivingCountTime(ms, delay1000ms);
	}

	//delayMicroseconds() 
	void Time::delayMicroseconds(Ulong us)
	{
		if ((us*delay1ms) < 2000)
		{
			for (unsigned long lcount = 0; lcount < us * 310; lcount++)
				lcount = lcount;
		}
		else
			ReceivingCountTime(us, delay1ms);
	}

	Ulong Time::micros(void)
	{//Returns the number of microseconds since the Arduino board began running the current program
		functionGroup = Time_begin;
		functionNo = Micros;
		SendingData();
		ReceivingDaTa();
		return IN_ULONG;
	}

	Ulong Time::millis(void)
	{
		functionGroup = Time_begin;
		functionNo = Millis;
		SendingData();
		ReceivingDaTa();
		return IN_ULONG;
	}

	Ulong Time::getID(void)
	{
		functionGroup = Time_begin;
		functionNo = GETID;
		SendingData();
		ReceivingDaTa();
		return IN_ULONG;
	}
}
