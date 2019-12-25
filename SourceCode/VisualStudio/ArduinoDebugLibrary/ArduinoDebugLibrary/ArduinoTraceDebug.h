#pragma once
//#include "Test.h"
#include "arduino.h"
#include <stdio.h>
//#include "SimGPIO.h"
//#include "SimAdvIO.h"
#include "math.h"
//#include "SimSerial.h"
//#include "SimTime.h"
//#include "SimSPI.h"
//#include "SimWire.h"
#include "SimInterrupt.h"
#include <stdio.h>

//extern MySerial	Serial;	//initial communication
//extern MySerial	Serial1;
//extern GPIO		MyGPIO;
//extern AdvIO	MyAdvIO;
//extern Time		MyTime;
//extern SPIClass	SPI;
//extern WWire	Wire;

//GPIO
#define pinMode				MyGPIO.pinMode
#define digitalWrite		MyGPIO.digitalWrite
#define digitalRead			MyGPIO.digitalRead
#define analogRead			MyGPIO.analogRead
#define analogWrite			MyGPIO.analogWrite
#define Random				MyGPIO.Random
#define map					MyGPIO.map
//Time
#define delay				MyTime.delay
#define delayMicroseconds	MyTime.delayMicroseconds
#define micros				MyTime.micros
#define millis				MyTime.millis
#define	TimeSetup			MyTime.TimeSetup
//Advance
#define noTone				MyAdvIO.noTone
#define pulseIn				MyAdvIO.pulseIn
#define pulseInLong			MyAdvIO.pulseInLong
#define shiftIn				MyAdvIO.shiftIn
#define shiftOut			MyAdvIO.shiftOut
#define tone				MyAdvIO.tone
#define VersionCheck		MyAdvIO.version