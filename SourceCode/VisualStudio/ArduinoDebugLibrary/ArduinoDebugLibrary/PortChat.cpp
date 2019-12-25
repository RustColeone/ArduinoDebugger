#include "pch.h"
#include "stdafx.h"
#include "PortChat.h"

#include "ArduinoDebugLibrary.h"
#include "ArduinoTraceDebug.h"


byte InternalSerial::initSerial(byte ch)
{
	byte re;
	char portname[10] = "\\\\.\\COM";
	if (ch != 0)
	{	//manual select		
		if (ch < 10)
			portname[7] = ch + 0x30;
		else
		{
			portname[7] = (ch / 10) % 10 + 0x30;
			portname[8] = (ch % 10) + 0x30;
		}
		re=initComPort(portname);
	}
	else
	{	//auto select
		for (ch = 3; ch < 30; ch++)
		{
			if (ch < 10)
			portname[7] = ch + 0x30;
			else
			{
				portname[7] = (ch / 10) % 10 + 0x30;
				portname[8] = (ch % 10) + 0x30;
			}
			re = initComPort(portname);
			if(re)			break;
		}
		if (ch >= 29)
		{
			printf("Unable fo fine Arduino board\n\r");	
			re = 0xf5;
		}
	}
	return re;
}


bool InternalSerial::initComPort(const char *portName)
{
	bool reflat = true;
	//We're not yet connected
	this->connected = false;
	//Try to connect to the given port throuh CreateFile
	this->hSerial = CreateFileA(portName,	//CreateFileA  CreateFileW CreateFile
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	//Check if the connection was successfull
	if (this->hSerial == INVALID_HANDLE_VALUE)
	{
		//If not success full display an Error
		if (GetLastError() == ERROR_FILE_NOT_FOUND) {

			//Print Error if neccessary
			printf(".");// , & portName[3]);
		}
		else
		{
			printf("jump Over used port %s", &portName[3]);
		}
		reflat = false;
	}
	else
	{
		//If connected we try to set the comm parameters
		DCB dcbSerialParams = { 0 };

		//Try to get the current
		if (!GetCommState(this->hSerial, &dcbSerialParams))
		{
			//If impossible, show an error
			printf("failed to get current serial parameters!");
		}
		else
		{
			char ch = ' ';
			//Define serial connection parameters for the arduino board
			dcbSerialParams.BaudRate = CBR_115200;
			dcbSerialParams.ByteSize = 8;
			dcbSerialParams.StopBits = ONESTOPBIT;
			dcbSerialParams.Parity = NOPARITY;
			//Setting the DTR to Control_Enable ensures that the Arduino is properly
			//reset upon establishing a connection
			dcbSerialParams.fDtrControl = DTR_CONTROL_ENABLE;

			//Set the parameters and check for their proper application
			if (!SetCommState(hSerial, &dcbSerialParams))
			{
				printf("\n\rALERT: Could not set Serial Port parameters");
				reflat = false;
			}
			else
/*////////////////////////////////////////////////////////////////////////
			{
				printf("\nSerial port: %s available \n ", &portName[3]);
				printf("Y for accept N serach next   ");
				do { ch = getchar(); } while (ch != 'N' && ch != 'n' && ch != 'Y' && ch != 'y');
				if (ch == 'N' || ch == 'n')
				{
					reflat = false;
					printf("\n\r");
				}
				else
				{
					//If everything went fine we're connected
					this->connected = true;
					//Flush any remaining characters in the buffers
					PurgeComm(this->hSerial, PURGE_RXCLEAR | PURGE_TXCLEAR);
					//We wait 2s as the arduino board will be reseting
					Sleep(ARDUINO_WAIT_TIME);
				}
			}
*/////////////////////////////////////////////////////////////////////////////
			{
				//test debug boards
				if (ch < 36)
				{
					Sleep(ARDUINO_WAIT_TIME);
					functionGroup = Time_begin;
					functionNo = GETID;
					SendingDataTimeout();
					ReceivingDaTaTimeout();
					int tt = IN_ULONG;
					if (IN_ULONG == 123 || IN_ULONG == 456 || IN_ULONG == 789 || IN_ULONG == 345)
					{
						if (IN_ULONG == 123)
							printf("Arduino UNO found\n\r");
						if (IN_ULONG == 456)
							printf("Arduino Leonardo found\n\r");
						if (IN_ULONG == 789)
							printf("ESP8266 E12 found\n\r");
						if (IN_ULONG == 345)
							printf("Arduino M0 SAMD21 found\n\r");
						//If everything went fine we're connected
						this->connected = true;
						//Flush any remaining characters in the buffers 
						PurgeComm(this->hSerial, PURGE_RXCLEAR | PURGE_TXCLEAR);
						//We wait 2s as the arduino board will be reseting
						Sleep(ARDUINO_WAIT_TIME);
					}
					else
					{
						reflat = false;
						printf("\n\r");
					}
				}
				else
				{
					reflat = false;
					printf("\n\r");				
				}

			}
//////////////////////////////////////////////////////////////////////////////
		}
	}
	return reflat;
}

InternalSerial::~InternalSerial()
{
	//Check if we are connected before trying to disconnect
	if (this->connected)
	{
		//We're no longer connected
		this->connected = false;
		//Close the serial handler
		CloseHandle(this->hSerial);
	}
}

int InternalSerial::ReadData(char *buffer, unsigned int nbChar)	//int
{
	//Number of bytes we'll have read
	DWORD bytesRead;
	//Number of bytes we'll really ask to read
	unsigned int toRead;

	//Use the ClearCommError function to get status info on the Serial port
	ClearCommError(this->hSerial, &this->errors, &this->status);

	//Check if there is something to read
	if (this->status.cbInQue > 0)
	{
		//If there is we check if there is enough data to read the required number
		//of characters, if not we'll read only the available characters to prevent
		//locking of the application.
		if (this->status.cbInQue > nbChar)
		{
			toRead = nbChar;
		}
		else
		{
			toRead = this->status.cbInQue;
		}

		//Try to read the require number of chars, and return the number of read bytes on success
		if (ReadFile(this->hSerial, buffer, toRead, &bytesRead, NULL))
		{
			return bytesRead;
		}

	}

	//If nothing has been read, or that an error was detected return 0
	return 0;

}


//bool Serial::WriteData(const char *buffer, unsigned int nbChar)
bool InternalSerial::WriteData(char *buffer, unsigned int nbChar)
{
	DWORD bytesSend;

	//Try to write the buffer on the Serial port
	if (!WriteFile(this->hSerial, (void *)buffer, nbChar, &bytesSend, 0))
	{
		//In case it don't work get comm error and return false
		ClearCommError(this->hSerial, &this->errors, &this->status);

		return false;
	}
	else
		return true;
}

bool InternalSerial::IsConnected()
{
	//Simply return the connection status
	return this->connected;
}
