#pragma once
#include "ArduinoDebugLibrary.h"
#include "SimEeprom.h"
#include "SimAsm.h"
void setup(void);
void loop(void);
using namespace ADL;

extern GPIO gpio1;
extern Time TIME;
extern WWire Wire;
extern MySerial Serial1;
extern SPIClass SPI;
extern AdvIO AVIO;


#define pinMode gpio1.pinMode
#define analogRead	gpio1.analogRead
#define analogWrite gpio1.analogWrite
#define digitalWrite gpio1.digitalWrite
#define digitalRead gpio1.digitalRead

#define delay	TIME.delay
#define delayMicroseconds TIME.delayMicroseconds
#define micros TIME.micros
#define millis TIME.millis

