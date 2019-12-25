#include "pch.h"
#include "stdafx.h"
#include "arduino.h"
#include "ArduinoDebugLibrary.h"



bool Serial=false;

Byte If(char * Se) {
	return 1;
}

namespace ADL{


	MySerial::MySerial()
	{
		//Serial = TestComport();
	}

/*
	MySerial::~MySerial()
	{
	}
*/

	Byte MySerial::available()
	{
		functionGroup = SERIAL1;
		functionNo = AVAILABLE;
		SendingData();
		ReceivingDaTa();	
		return IN_BYTE4;
	}

	Byte MySerial::availableForWrite()
	{
		functionGroup = SERIAL1;
		functionNo = AVAILABLEFORWRITE;
		SendingData();
		ReceivingDaTa();
		return IN_BYTE4;
	}
	void MySerial::begin(long speed, Byte config)
	{
		functionGroup = SERIAL1;
		functionNo = BEGIN;
		OUT_ULONG = speed;
		OUT_BYTE4 = config;
		OUT_BYTE3 = 0;
		SendingData();
	}

	void MySerial::begin(long speed)
	{
		functionGroup = SERIAL1;
		functionNo = BEGIN;
		OUT_ULONG = speed;
		OUT_BYTE3 = 1;
		if (BoardType == 123)
		{
			if (OUT_ULONG > 57600) OUT_ULONG = 57600;
			printf("The software Serial set at pin 2 RX and 3 TX\n\r");
			printf("The maximum Serial port is 57600 for UNO");
			printf("Serial port Set at %u\n\r", OUT_ULONG);
		}
else
		printf("Serial port Set at %u\n\r", OUT_ULONG);
		SendingData();
	}

	void MySerial::end()
	{
		functionGroup = SERIAL1;
		functionNo = END;
		printf("Serial port closed \n\r");
		SendingData();
	}


	void MySerial::flush()
	{
		functionGroup = SERIAL1;
		functionNo = FLUSH;
		SendingData();
	}

	//The first byte of incoming serial data available (or -1 if no data is available) - int
	Byte MySerial::peek()
	{
		functionGroup = SERIAL1;
		functionNo = PEEK;
		SendingData();
		ReceivingDaTa();
		return IN_BYTE4;
	}

	__int16 MySerial::read(void)
	{
		functionGroup = SERIAL1;
		functionNo = READ;
		SendingData();
		ReceivingDaTa();
		return IN_INT16_1;
	}
	Byte MySerial::readBytes(Byte *st, Byte N)
	{
		functionGroup = SERIAL1;
		functionNo = READBYTES;
		OUT_INT1 = N;
		SendingData();
		ReceivingArray();
		if (IN_BYTE4 > N) IN_BYTE4 = N;
		for (int count = 0; count < IN_BYTE4; count++)
			st[count] = INarray[count];
		return IN_BYTE4;
	}


	//Serial.write(str)

	Byte  MySerial::write(const char st[])
	{
		Byte page = 0;
		Byte count;
		for (count = 0; count < 100; count++)
		{
			if (st[count] == 0)
			{
				page = (count / 8) + 1;
				break;
			}
		}
		if (count > 128) count = 128;
		return _WRITE(st, count);
	}

	Byte  MySerial::write(const char *st, Uint8_t n)
	{
		return _WRITE(st, n);
	}
	/////////////////////////////////////////////////////

	/////////////////////////////////////////////////////

	Byte MySerial::print(int X, Byte mode)
	{
		mode = mode | 0x20;
		return _PRINT((Uint32_t)X, mode);
	}

	Byte MySerial::print(const char cc)	//may the same as write
	{
		return _PRINT((Uint32_t)cc, 0x4a);
	}

	Byte MySerial::println(int X, Byte mode)
	{
		mode = mode | 0x60;
		return _PRINT((Uint32_t)X, mode);
	}

	Byte MySerial::print(float X, Byte mode)
	{
		mode = mode | 0x80;
		return _PRINT(X, mode);
	}

	Byte MySerial::print(double X, Byte mode)
	{
		mode = mode | 0x80;
		return _PRINT((float)X, mode);
	}

	//Serial.write(val)
	Byte MySerial::write(Byte X)
	{
		return _PRINT((Uint32_t)X, 0xca);
	}

	Byte  MySerial::_PRINT(float X, Byte mode)
	{
		functionGroup = SERIAL1;
		functionNo = PRINT;
		OUT_FLOAT = X;
		OUT_BYTE3 = mode;
		SendingData();
		ReceivingDaTa();
		return IN_BYTE4;
	}

	Byte  MySerial::_PRINT(Uint32_t X, Byte mode)
	{
		functionGroup = SERIAL1;
		functionNo = PRINT;
		OUT_ULONG = X;
		OUT_BYTE3 = mode;
		SendingData();
		ReceivingDaTa();
		return IN_BYTE4;
	}


	Byte  MySerial::println(const char st[])
	{
		int count;
		functionGroup = SERIAL1;
		functionNo = WRITE;
		functionGroup = functionGroup | 0x40;
		for (count = 0; count < 128; count++)
		{
			if (st[count] < 0x20)
			{
				OUTarray[count] = '\r';
				OUTarray[count+1] = '\n';
				break;
			}
			OUTarray[count] = st[count];
		}
		OUT_INT1=OUT_BYTE2 = count+2;	//count
		OUT_BYTE7 = ((count+1) / 8) + 1; //page
		SendingArray();
		ReceivingDaTa();
		return IN_BYTE4;
	}

	Byte  MySerial::_WRITE(const char *st, Uint8_t n)
	{
		Byte count;
		if (n > 128)	n = 128;
		Byte page = ((n - 1) / 8) + 1;
		functionGroup = SERIAL1;
		functionNo = WRITE;	
		OUT_BYTE2 = n;
		OUT_BYTE7 = page;
		OUT_INT1 = n;
		functionGroup = functionGroup | 0x40;
		for (count = 0; count < n; count++)
			OUTarray[count] = st[count];
		if (n >= 127) n = 127;
		OUTarray[n] = 0;
		SendingArray();
		ReceivingDaTa();
		return IN_BYTE4;
	}

}