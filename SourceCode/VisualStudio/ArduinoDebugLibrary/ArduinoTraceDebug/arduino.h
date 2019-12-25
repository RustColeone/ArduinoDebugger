#pragma once


#include <math.h>		//ne
#include <ctype.h>

/*
#include "PortChat.h"
extern InternalSerial MyPort;
*/
#define high4Bit(b) ((byte) ((b) >> 4))
#define low4Bit(b) ((byte) ((b) & 0xf))
//#include <windows.h>
//#include <stdio.h>
//#include <stdlib.h>
/*
#define		pin	 FPCEXcode.ST.data5
#define		mode FPCEXcode.ST.data6
#define		result TPCEXcode.ST.byte1
*/
#define functionGroup   FPCEXcode.ST.FunctionGroup
#define functionNo		FPCEXcode.ST.FunctionNo
#define OUT_BYTE2		FPCEXcode.ST.data2
#define OUT_BYTE3		FPCEXcode.ST.data3

#define OUT_INT2		FPCEXcode.ST.COMB.INT16[1]
#define OUT_INT1		FPCEXcode.ST.COMB.INT16[0]
#define OUT_ULONG		FPCEXcode.ST.COMB.UINT32
#define OUT_FLOAT		FPCEXcode.ST.COMB.FLOAT

#define OUT_DUE_LONG1	DUEdata.ST.COMB[0].UINT32
#define OUT_DUE_LONG2	DUEdata.ST.COMB[1].UINT32

#define OUT_DUE_INT1	DUEdata.ST.COMB[0].INT16[0]
#define OUT_DUE_INT2	DUEdata.ST.COMB[0].INT16[1]

#define	OUT_BYTE7		FPCEXcode.ST.COMB.BYTE[3]
#define	OUT_BYTE6		FPCEXcode.ST.COMB.BYTE[2]
#define	OUT_BYTE5		FPCEXcode.ST.COMB.BYTE[1]
#define	OUT_BYTE4 		FPCEXcode.ST.COMB.BYTE[0]

#define IN_Intpt_Status		TPCEXcode.ST.FunctionGroup
#define IN_Intpt_Action		TPCEXcode.ST.FunctionNo
#define IN_BYTE2		TPCEXcode.ST.data2
#define IN_BYTE4		TPCEXcode.ST.COMB.BYTE[0]
//#define IN_INT16_2		TPCEXcode.ST.COMB.INT16[1]
#define IN_INT16_1		TPCEXcode.ST.COMB.INT16[0]
#define IN_ULONG		TPCEXcode.ST.COMB.UINT32

//#define StartPage		0xF5		//0xA0		//0xa0--0xaf 16 pages
//#define EndPage			0xFA

#define DUE				1

#define Gpio			0
#define Time_begin		1
#define	AdvIO_begin		2
#define SERIAL1			3
#define SPIport			4
#define	WWire1			5
//#define	WWire2			6
#define	ESP8266			6
////////////////////////////////////////
#define CH_Array		0b0001
#define CH_RX			0b0010
#define CH_DUE			0b0100
////////////////////////////////////////
#define Byte		unsigned char 
#define Uint8_t		unsigned char 
#define Ulong		unsigned __int32 
#define	Uint32_t	unsigned __int32 
#define Uint16_t	unsigned __int16 


union interrupststus {
	struct {
		Byte notuse : 5;
		Byte interruptststus : 1;
		Byte Requestststus : 1;
		Byte Requiredststus : 1;
	}Bits;
	Byte BYTES;
};


union Typecombine {
	Uint16_t	INT16[2];
	Uint32_t	UINT32;
	Uint32_t	ULONG;
	float		FLOAT;
	Uint8_t		BYTE[4];	//check of double	
};


union EXdata {
	struct StructDint {
		Byte FunctionGroup;
		Byte FunctionNo;
		Byte data2;
		Byte data3;
		Typecombine COMB;
	}ST;
	char ByteData[8];
};

union EXDuedata {
	struct StructDint {
		Typecombine COMB[2];
	}ST;
	char ByteData[8];
};

//typedef void(*bytep)(Byte);
typedef void(*voidv)(void);		//onRequest

typedef void(*bytei)(int);	//onReceive

extern voidv interruptfunction, SPI_Slave_interrupt;
extern voidv onRequestfunction;
extern bytei onReceivefunction;


#define NOT_AN_INTERRUPT -1
#define digitalPinToInterrupt(p) ((p) == 0 ? 2 : ((p) == 1 ? 3 : ((p) == 2 ? 1 : ((p) == 3 ? 0 : ((p) == 7 ? 4 : NOT_AN_INTERRUPT)))))

#define yes				1
#define no				0

#define HIGH 0x1
#define LOW  0x0

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105
#define EULER 2.718281828459045235360287471352

#define SERIALCOM  0x0
#define DISPLAY 0x1

#define LSBFIRST 0
#define MSBFIRST 1

#define	SPI_MODE0 0x00
#define	SPI_MODE1 0x04
#define	SPI_MODE2 0x08
#define	SPI_MODE3 0x0C

#define CHANGE 1
#define FALLING 2
#define RISING 3

#define boolean bool

inline boolean isAlphaNumeric(int c)
{
	return (isalnum(c) == 0 ? false : true);
}


// Checks for an alphabetic character. 
// It is equivalent to (isupper(c) || islower(c)).
inline boolean isAlpha(int c)
{
	return (isalpha(c) == 0 ? false : true);
}


// Checks whether c is a 7-bit unsigned char value 
// that fits into the ASCII character set.
inline boolean isAscii(int c)
{
	return (isascii(c) == 0 ? false : true);
}


// Checks for a blank character, that is, a space or a tab.
inline boolean isWhitespace(int c)
{
	return (isblank(c) == 0 ? false : true);
}


// Checks for a control character.
inline boolean isControl(int c)
{
	return (iscntrl(c) == 0 ? false : true);
}


// Checks for a digit (0 through 9).
inline boolean isDigit(int c)
{
	return (isdigit(c) == 0 ? false : true);
}


// Checks for any printable character except space.
inline boolean isGraph(int c)
{
	return (isgraph(c) == 0 ? false : true);
}


// Checks for a lower-case character.
inline boolean isLowerCase(int c)
{
	return (islower(c) == 0 ? false : true);
}


// Checks for any printable character including space.
inline boolean isPrintable(int c)
{
	return (isprint(c) == 0 ? false : true);
}


// Checks for any printable character which is not a space 
// or an alphanumeric character.
inline boolean isPunct(int c)
{
	return (ispunct(c) == 0 ? false : true);
}


// Checks for white-space characters. For the avr-libc library, 
// these are: space, formfeed ('\f'), newline ('\n'), carriage 
// return ('\r'), horizontal tab ('\t'), and vertical tab ('\v').
inline boolean isSpace(int c)
{
	return (isspace(c) == 0 ? false : true);
}


// Checks for an uppercase letter.
inline boolean isUpperCase(int c)
{
	return (isupper(c) == 0 ? false : true);
}


// Checks for a hexadecimal digits, i.e. one of 0 1 2 3 4 5 6 7 
// 8 9 a b c d e f A B C D E F.
inline boolean isHexadecimalDigit(int c)
{
	return (isxdigit(c) == 0 ? false : true);
}


// Converts c to a 7-bit unsigned char value that fits into the 
// ASCII character set, by clearing the high-order bits.
inline int toAscii(int c)
{
	return toascii(c);
}


// Warning:
// Many people will be unhappy if you use this function. 
// This function will convert accented letters into random 
// characters.

// Converts the letter c to lower case, if possible.
inline int toLowerCase(int c)
{
	return tolower(c);
}


// Converts the letter c to upper case, if possible.
inline int toUpperCase(int c)
{
	return toupper(c);
}
void SendingData8266(char *buffer, unsigned int nbChar);
void ReceivingDaTa8266(char *buffer, unsigned int nbChar);
void SendingData();
void ReceivingDaTa();
Byte ReceivingArray();
void ReceivingDueDaTa();
void SendingDueData();
Byte SendingArray();
unsigned long ReceivingCountTime(unsigned long loop = 0, unsigned long timeconstant = 0);
bool TestComport();
//#define DEG_TO_RAD 3.1415926/180

#define abs(x) ((x)>0?(x):-(x))
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define radians(deg) ((deg)*DEG_TO_RAD)
#define degrees(rad) ((rad)*RAD_TO_DEG)
#define sq(x) ((x)*(x))
/*
#define abs(x) ((x)>0?(x):-(x))
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
*/
#define lowByte(w) ((Byte) ((w) & 0xff))
#define highByte(w) ((Byte) ((w) >> 8))

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))

#define bit(b) (1UL << (b))

extern char OUTarray[128];
extern char INarray[128];
extern EXdata	FPCEXcode;
extern EXdata	TPCEXcode;
extern EXDuedata	DUEdata;
