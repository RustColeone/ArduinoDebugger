#include "pch.h"
#include "ArduinoTraceDebug.h"
#include "Interrupt.h"
//#include "SimEeprom.h"
//#include <iostream>


SIM8266 ESP;
char outbuffer[40] = { 10,11,12,13,14,15,16,17,19,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42 };
char intbuffer[40];
Byte Rxdata[20];
//
void function1()
{
	printf("interrupt test");
}



void Diagnostic(Byte item)
{	//GPIO test
	if (item == 0)
	{//hardware pin 11 to 12
		int a;		
		EEPROM[10] = 10;
		pinMode(13, OUTPUT);	//LED
		pinMode(12, INPUT);
		pinMode(11, OUTPUT);
		for (int c = 0; c < 50; c++)
		{
			digitalWrite(11,LOW);	//external link between 11-12
			a = digitalRead(12);	//Software link between 12-13
			digitalWrite(13, a);
			delay(200);
			digitalWrite(11, HIGH);
			a = digitalRead(12);
			digitalWrite(13, a);
			delay(200);
		}
	}
	//interrupt test
	if (item == 1)
	{//hardware pin 10 to 3
		pinMode(13, OUTPUT);
		digitalWrite(13, HIGH);
		pinMode(3, INPUT_PULLUP);
		digitalRead(10);
		//noInterrupts();
		//attachInterrupt(digitalPinToInterrupt(3), function1, FALLING);	//could be set any function entry point
		//interrupts();		
		for (int c = 0; c < 10; c++)
		{
			digitalWrite(13, LOW);
			digitalWrite(13, HIGH);
			digitalWrite(13, LOW);
			digitalWrite(13, HIGH);
			digitalWrite(13, LOW);
			digitalWrite(13, HIGH);
			digitalWrite(13, LOW);
			digitalWrite(13, HIGH);			
		} 
//	noInterrupts();
	}
	if (item == 2)	//test time
	{	//hard ware not required		
		Ulong	TimesFROM;
		Ulong	Timeend;
		Ulong   Timelaps;		
		for (int g = 0; g < 1000; g++)
		{
			digitalWrite(10, HIGH);
		}		
		delay(100);
		delayMicroseconds(10000);
		for (int g = 0; g < 10; g++)
		{	TimesFROM = micros();	//break point and watch Timelaps
			delay(100);
			Timeend = micros();
			Timelaps = Timeend - TimesFROM;
			TimesFROM = millis();  //break point and watch Timelaps
			delay(1000);
			Timeend = millis();
			Timelaps = Timeend - TimesFROM;
		} while (1);
	}
	if (item == 3)	//test Serial 2
	{//Hareware putty required connected to serial point set baud rate 115200
	//check device to get your com port address
		int bytecount;
		int readdata;
		for (int g = 0; g < 10; g++)
		{	Serial1.begin(38400);
			readdata = Serial1.write('c');	//look for putty
			readdata = Serial1.write('b');
			Serial1.write("123%345\r\n");	//with new line
//			Serial1.print("123.4512, 2");		//with 2 decimal point
			Serial1.print(123.4512, 2);		//with 2 decimal point
			Serial1.print(123.4512, 3);		//with 3 decimal point
			Serial1.print(78);
			Serial1.print(213);
			Serial1.print(21222);
			Serial1.print(2111143);
			Serial1.print(243, HEX);
			Serial1.print(21143, HEX);
			Serial1.print(2111143, HEX);
			Serial1.println(243);
			Serial1.println((Uint32_t)213);
			Serial1.println((Uint32_t)21222);
			Serial1.println((Uint32_t)2111143);
			Serial1.println((Uint32_t)243, HEX);
			Serial1.println((Uint32_t)21143, HEX);
			Serial1.println((Uint32_t)2111143, HEX);
			Serial1.println("1234567");
		}
		//loop back test link up TX and RX during test			
		char outbuffer[] = { "abcdef123456789" };
		unsigned char inbuffer[130];
		Serial1.flush();
		for (int g = 0; g < 10; g++)
		{
			Serial1.begin(115200);
			do {readdata = Serial1.read();
			bytecount = Serial1.available();
			}while (bytecount);

			bytecount= Serial1.peek();			
			bytecount = Serial1.available();
			bytecount = Serial1.peek();
			Serial1.write(outbuffer);
			if (bytecount = Serial1.available())
			{
				readdata = Serial1.readBytes(inbuffer, bytecount);//watch inbuffer
			}
			bytecount = Serial1.write(outbuffer);
			bytecount = Serial1.available();
			Serial1.end();
			//bytecount = Serial1.available();
			//bytecount = Serial1.write(outbuffer);
		}
	}
	if (item == 4)	//test I2C (master)
	{//Hardware SDA ->SDA  SLC ->SCL 
	// two cards required during test
		int x=0;
		Wire.begin();
		do {
			//Wire.requestFrom(9, 6);    // request 6 bytes from slave device #8
			Wire.beginTransmission(9); // transmit to device #9
			Wire.write(x);
			Wire.endTransmission();    // stop transmitting
			x++; // Increment x
			if (x > 5) x = 0; // `reset x once it gets 6
		} while (1);
	}
	
	if (item == 5)	//test I2C (slave)
	{//Hardware SDA ->SDA  SLC ->SCL 
	// two cards required during testl
		EEPROM[10] = 10;
		int yy = EEPROM[10];
		Wire.begin(9);		
//		Wire.onReceive(receiveEvent);
		do {
			pinMode(10, INPUT);
			digitalRead(10);
		} while (1);
	}
	if (item == 6)	//test SPI
	{//This test required two Arduino cards		
		//master	MOSI 16		MISO 14     SCK 15    SS 17
		// slave    MOSI 16		MISO 14     SCK 15    SS 17
		//connect in parallel		
		do {
			pinMode(5, OUTPUT);
			//pinMode(16, OUTPUT);
			//pinMode(15, OUTPUT);			
			//pinMode(14, INPUT);
			SPI.beginTransaction(SPISettings(4000000, MSBFIRST, SPI_MODE0));
			SPI.begin();
			//SPI.setClockDivider(SPI_CLOCK_DIV2);
			//for esp8266			
			for (int k = 0; k < 1000; k++)
			{
				digitalWrite(5, LOW);
				SPI.transfer(0x01);
				SPI.transfer(0x5);
				SPI.transfer(0x5);
				SPI.transfer(0x5);
				SPI.transfer(0x5);				
				digitalWrite(5, HIGH);
				///////////////////////
				digitalWrite(5, LOW);
				SPI.transfer(0x04);
				intbuffer[0] = SPI.transfer(0);
				intbuffer[1] = SPI.transfer(0);
				intbuffer[2] = SPI.transfer(0);
				intbuffer[3] = SPI.transfer(0);
				digitalWrite(5, HIGH);
			}
			for (int kk = 0; kk < 1000; kk++)
			{
				digitalWrite(5, LOW);
				SPI.transfer(0x02);
				SPI.transfer(0x00);
				for (int g = 0; g < 32; g++)
				{
					SPI.transfer(outbuffer[g]);
				}
				digitalWrite(5, HIGH);
				///////////////////////
				digitalWrite(5, LOW);
				SPI.transfer(0x03);
				SPI.transfer(0x00);
				for (int gg = 0; gg < 32; gg++)
				{
					intbuffer[gg] = SPI.transfer(0);
				}
				digitalWrite(5, HIGH);
			}
			//SPI.setBitOrder(MSBFIRST);
			//SPI.setDataMode(SPI_MODE0);
			//SPI.setClockDivider(SPI_CLOCK_DIV4);
			//SPI.endTransaction();
			//SPI.end();
		} while (1);
	}
	if (item == 7)		//math test
	{
		double c = sin(30);
		c = sqrt(30);
		c = sin(30);
		c = tan(30);
		c = cos(30);
		c = isAscii(0x29);
		c = radians(180);
	}			
	double Dresult = sq(100);
	if (item == 8)	//advance io
	{//pulseInLong	
		Byte a;
		pinMode(5, OUTPUT);
		pinMode(9, OUTPUT);
		pinMode(10, OUTPUT);
		AVIO.shiftOut(10,9,0,0x55);
		do {
			AVIO.shiftOut(10,9,LSBFIRST,0x55);
			digitalWrite(5, LOW);
			digitalWrite(5, HIGH);
		} while (1);
		a = AVIO.shiftIn(5, 6, 0);
	}
	if (item == 9)
	{
		ESP.BEGIN8266(5);
		for (int k = 0; k < 1000; k++)
		{
			FPCEXcode.ST.COMB.BYTE[0] = 0;
			FPCEXcode.ST.COMB.BYTE[1] = 1;
			FPCEXcode.ST.COMB.BYTE[2] = 2;
			FPCEXcode.ST.COMB.BYTE[3] = 3;
			ESP.TX8266byte();
			ESP.RX8266byte();
			FPCEXcode.ST.COMB.BYTE[0] = 0x10;
			FPCEXcode.ST.COMB.BYTE[1] = 0x20;
			FPCEXcode.ST.COMB.BYTE[2] = 0x30;
			FPCEXcode.ST.COMB.BYTE[3] = 0x40;
			ESP.TX8266byte();
			ESP.RX8266byte();
		}
		for (int lk = 0; lk < 1000; lk++)
		{
			for(int p = 0;p<32;p++)
				OUTarray[p] = outbuffer[p];
			ESP.TX8266byte32();//OUTarray
			ESP.RX8266byte32();//INarray
			for (int p = 0; p < 32; p++)
				OUTarray[p+1] = outbuffer[p];
			ESP.TX8266byte32();
			ESP.RX8266byte32();
		}
	}
}

