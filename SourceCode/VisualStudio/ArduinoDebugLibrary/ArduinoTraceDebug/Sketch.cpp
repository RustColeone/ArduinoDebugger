#include "pch.h"
#include <iostream>
#include "ArduinoDebugLibrary.h"
#include "ArduinoTraceDebug.h"
void Diagnostic(Byte item);
//sketch.cpp
void setup(void)
{
	//INTRRUPT.BYTES = 0;
	Serial1.begin(115200);
	pinMode(13, OUTPUT);
}

void loop(void)
{
	char a,b;
	Diagnostic(1);
	Serial1.begin(115200);
	Serial1.println(123);
	do {
		Serial1.write('g');
		while (Serial1.available() == 0);
		a=Serial1.read();
		digitalWrite(13, HIGH);
	} while (1);
	
}