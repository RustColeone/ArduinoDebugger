#pragma once
#include "arduino.h"
#include "ArduinoDebugLibrary.h"
void defaultpt(void);
void defaultSpi(void);
void noInterrupts(void);
void interrupts(void);
void attachInterrupt(Byte, voidv= defaultpt, Byte WaveFormCHANGE=FALLING);
