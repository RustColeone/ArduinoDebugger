// ArduinoDebugLibrary.cpp : Defines the exported functions for the DLL application.
//
#include "stdafx.h"
#include "ArduinoDebugLibrary.h"
#include "PortChat.h"



namespace ADL
{
	Byte INTSERIAL::InitSerial(Byte ch)
	{
		return MyPort.initSerial(ch);
	}
}


