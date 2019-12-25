#pragma once

//TIME//
#include "arduino.h"
// MathFuncsLib.h
//8266//
#define BEGIN_8266		0
#define WRITE_4BYTE		1
#define READ_4BYTE		2
#define WRITE_32BYTE	3
#define READ3_2BYTE		4
//#include "SimInterrupt.h"
#define Delay10ms			0
#define Micros				1
#define Millis				2
#define GETID				3
//SPI//
extern char OUTarray[128];
extern char INarray[128];
extern EXdata	FPCEXcode;
extern EXdata	TPCEXcode;
extern EXDuedata	DUEdata;
extern int BoardType;
#define SPI_CLOCK_DIV4 0x00
#define SPI_CLOCK_DIV16 0x01
#define SPI_CLOCK_DIV64 0x02
#define SPI_CLOCK_DIV128 0x03
#define SPI_CLOCK_DIV2 0x04
#define SPI_CLOCK_DIV8 0x05
#define SPI_CLOCK_DIV32 0x06

#define SPI_MODE0 0x00
#define SPI_MODE1 0x04
#define SPI_MODE2 0x08
#define SPI_MODE3 0x0C

#define SPI_MODE_MASK 0x0C  // CPOL = bit 3, CPHA = bit 2 on SPCR
#define SPI_CLOCK_MASK 0x03  // SPR1 = bit 1, SPR0 = bit 0 on SPCR
#define SPI_2XCLOCK_MASK 0x01  // SPI2X = bit 0 on SPSR


#define SPIbegin			0
#define SPIbeginTransaction	1
#define SPItransfer			2
#define SPItransferbuf		3
#define SPIendTransaction	4
#define SPIend				5
#define SPIsetBitOrder		6
#define SPIsetDataMode		7
#define SPIsetClockDivider	8
#define SPI_SlaveInit		9
#define SPI_SlaveTransfer	10
//WIRE//
#define WWbegin					0
#define WWend					1
#define WWsetClock				2
#define WWbeginTransmission		3
#define WWendTransmission		4
#define WWrequestFrom			5
#define WWrequestFrom1			6
#define Wwrite					7
#define Wavailable				8
#define Wread					9
#define Wpeek					10
#define Wflush					11
#define WWinstaller 			12

void defaultReceivefunction(int a);
void defaultRequestfunction(void);

//GPIO//
#define	PinMode			0
#define IORead			1
#define IOWrite			2
#define AnalogRead		3
#define AnalogWrite		4
#define random			5
#define interruptOff	6
#define interruptOn		7
#define interruptAct	8
//SimAdvIO//
#define AnoTone			0x00
#define ApulseIn		0x01
#define ApulseInLong	0x02
#define AshiftIn		0x03
#define AshiftOut		0x04
#define Atone			0x05
#define Atone1			0x06
#define Version			0x07
#define EEwrite			0x08
#define EEread			0x09
#define REGwrite		0x0a
#define REGread			0x0b
//Serial//
#define AVAILABLE			0
#define AVAILABLEFORWRITE	1
#define BEGIN				2
#define END					3
#define FLUSH				4
#define PEEK				5
#define READ				6
#define READBYTES			7
#define WRITE				8
#define PRINT				9
#define PRINTLN				10
#define IF					11

#define BIN		2
#define OCT		8
#define DEC		10
#define HEX		16

Byte If(char *);

namespace ADL
{	
	class INTSERIAL
	{
	public:		
		static Byte InitSerial(Byte ch);
	};

	class SIM8266
	{
	public:
		SIM8266() {};
		~SIM8266() {};
		void BEGIN8266(char pin);
		void TX8266byte();
		void RX8266byte();
		void TX8266byte32();
		void RX8266byte32();
	};

	class GPIO
	{
	public:
		//GPIO();
		//~GPIO();
		static void pinMode(Byte pin, Byte mode);
		static void digitalWrite(Byte pin, Byte data);
		static Byte digitalRead(Byte pin);
		static Byte analogRead(Byte analogPin);
		static void analogWrite(Byte analogPin, Byte value);
		static Ulong Random(Ulong min, Ulong max);
		static Ulong Random(Ulong max);
		static long  map(long x, long in_min, long in_max, long out_min, long out_max);
	};

	class AdvIO
	{
	public:
		//AdvIO();
		//~AdvIO();
		static void noTone(Byte pin);
		static __int32 pulseIn(Byte pin, Byte HL, __int32 timeout = 1000000);
		static __int32 pulseInLong(Byte pin, Byte HL);
		static __int32 pulseInLong(Byte pin, Byte HL, __int32 timeout);
		static Byte shiftIn(Byte dataPin, Byte clockPin, Byte bitOrder);
		static void shiftOut(Byte dataPin, Byte clockPin, Byte bitOrder, Byte value);
		static void tone(Byte pin, Uint16_t tone);
		static void tone(Byte pin, Uint16_t tone, Ulong duration);		
		static __int32 version(void);
		static void EEPROMWRITE(const __int16 Waddress, Byte value);
		static Byte EEPROMREAD(const __int16 Waddress);
		static void REGISTERWRITE(const __int16 Waddress, Byte value);
		static Byte REGISTERREAD(const __int16 Waddress);
	};

	class MySerial
	{
	public:
		MySerial();
		//~MySerial();
		static Byte available();
		static Byte availableForWrite();
		static void begin(long speed, Byte config);
		static void begin(long speed);
		static void end();
		static void flush();
		static Byte peek();

		static __int16 read(void);
		static Byte readBytes(Byte *st, Byte N);

		static Byte write(Byte X);
		static Byte println(const char st[]);//
		static Byte write(const char st[]);
		static Byte write(const char *st, Uint8_t n);

		static Byte print(int X, Byte mode = DEC);
		static Byte print(double X, Byte mode = DEC);
		static Byte print(float X, Byte mode = DEC);
		static Byte println(int X, Byte mode = DEC);
		static Byte print(const char cc);
	private:
		static Byte _PRINT(float X, Byte mode);
		static Byte _PRINT(Uint32_t X, Byte mode = DEC);		
		static Byte _WRITE(const char *st, Uint8_t n);
	};

	class WWire
	{
	public:
		WWire();
		//~WWire();
		static void begin();
		static void begin(Uint8_t);
		static void begin(int);
		static void end();
		static void setClock(Uint32_t);
		static void beginTransmission(Uint8_t);
		static void beginTransmission(int);

		static Uint8_t endTransmission(Uint8_t);
		static Uint8_t endTransmission(void);
		static Uint8_t requestFrom(Uint8_t, Uint8_t);
		static Uint8_t requestFrom(Uint8_t, Uint8_t, Uint8_t);
		static Uint8_t requestFrom(int, int);

		static Uint8_t requestFrom1(Uint8_t, Uint8_t, Uint32_t, Uint8_t, Uint8_t);
		static Uint8_t requestFrom(Uint8_t, int, int);

		static Uint32_t write(Uint8_t);
		static Uint32_t write(const Uint8_t *st);
		static Uint32_t write(const Uint8_t *, Uint32_t);

		static int available(void);
		static int read(void);
		static int peek(void);
		static void flush(void);
		static void onReceive(bytei Receivefunction = defaultReceivefunction);
		static void onRequest(voidv Requestfunction = defaultRequestfunction);
		static void Installer(void);
	private:
		static void _BEGIN(void);
		//void requestEvent(void);
		//void receiveEvent(int howMany);
	};

	class SPISettings {
	public:
		SPISettings(Uint32_t clock, Uint8_t bitOrder, Uint8_t dataMode) {
			OUT_ULONG = clock;
			OUT_BYTE2 = bitOrder;
			OUT_BYTE3 = dataMode;
		}
	};

	class SPIClass {
	public:
		//SPIClass() {}
		//~SPIClass() {}
		static void begin();
		static void beginTransaction(SPISettings settings);
		static Uint8_t transfer(Uint8_t data);
		static void transfer(char * st, Ulong count);
		static void endTransaction(void);
		static void end();
		static void setBitOrder(Uint8_t bitOrder);
		static void setDataMode(Uint8_t dataMode);
		static void setClockDivider(Uint8_t clockDiv);
		static void SPISlaveInit(void);
		static Byte SPISlaveTransfer(Byte Data);
	};

	class Time
	{
	public:
		//Time();
		//~Time();
		static void delay(__int16 ms);
		static void delayMicroseconds(Ulong us);
		static Ulong micros(void);
		static Ulong millis(void);
		static Ulong getID(void);
		static void TimeSetup(void);
	private:
		static long delay100ms;
		static void idelay(__int16 X);
		static unsigned long delay1000ms;
		static unsigned long delay1ms;
	};
}
