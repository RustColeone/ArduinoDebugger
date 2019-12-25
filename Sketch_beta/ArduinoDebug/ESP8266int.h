#ifndef ESP8266INT_H_
#define ESP8266INT_H_

#include "Common.h"
#include "Define.h"
//#include "SPI.h"

void Begin8266(void);
void Write4byte(void);
void Read4byte(void);
void Write32byte(void);
void Read32byte(void);

class ESPCOM
{
public:
ESPCOM();
~ESPCOM(){};
void BEGIN8266();
void WRITE4BYTE();	
void READ4BYTE();
void WRITE32BYTE();
void READ32BYTE();
private:
byte pin; 
};




#endif /* ESP8266INT_H_ */
