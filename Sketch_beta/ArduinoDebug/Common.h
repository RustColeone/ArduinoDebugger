#pragma once
//#define BAUD 115200
#include "Arduino.h"
#include "Gpio.h"
#include "Time.h"
#include "AdvIO.h"
#include "WWire.h"
#include "Serial.h"
#include "SSip.h"
#include "Interrupt.h"
#include "ESP8266int.h"
#define high4Bit(b) ((uint8_t) ((b) >> 4))
#define low4Bit(b) ((uint8_t) ((b) & 0xf))

const uint32_t VersionNo =12345;

//define marco
//for GPIO
union SimStatus{
struct
	{byte    Receive:4;
	byte	Request:4; 	
	}BIT;
byte	BYTE;
};


union Typecombine{	
	int				INT16[2];	
	uint8_t			BYTE[4];	
	unsigned long	ULONG;	
	uint32_t		UU32;
	float			FLOAT;	
};

union EXDuedata{
	struct StrucDint{
	Typecombine COMB[2];
	}ST;
	byte ByteData[8];
};
//Serial.write(&TPCEXcode.ByteData[0],8);
//#define  OUT_UBYTE4    TPCEXcode.ST.COMB.BYTE[0]
union EXdata {	
	struct StructLong {
		byte FunctionGroup;
		byte FunctionNo;
		byte data2;
		byte data3;	
		Typecombine COMB;
	}ST;
	byte ByteData[8];
};


typedef void(*pointer_to_function)(void);

union intb {
	unsigned short Int2Byte;
	byte Byte2Int[2];
};

byte ReceivingData(void);
byte SendingArray(byte);
void SendingData(void);
