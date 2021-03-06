// ArduinoTraceDebug.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "ArduinoDebugLibrary.h"
#include "ArduinoTraceDebug.h"

GPIO gpio1;
Time TIME;
WWire Wire;
MySerial Serial1;
SPIClass SPI;
AdvIO AVIO;

int main()
{
	INTSERIAL INserial;

	int a;
	a = INserial.InitSerial(0);
	if (a == 0xf5)	return 0;	//unable to connect Serial port
	TIME.TimeSetup();
	setup();
	do {
		loop();
		//timer to do interrup polling//
	} while (1);
	return 0;
}

