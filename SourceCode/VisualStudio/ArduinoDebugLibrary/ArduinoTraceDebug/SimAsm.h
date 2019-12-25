#pragma once
#include "arduino.h"
#define EE2END  (0x40ff)
/* Registers and associated bit numbers */
#define PINB REG[0x1003]
#define DDRB REG[0x1004]
#define PORTB REG[0x1005]
#define PINC REG[0x1006]
#define DDRC REG[0x1007]
#define PORTC REG[0x1008]
#define PIND REG[0x1009]
#define DDRD REG[0x100A]
#define PORTD REG[0x100B]
#define PINE REG[0x100C]
#define DDRE REG[0x100D]
#define PORTE REG[0x100E]
#define PINF REG[0x100F]
#define DDRF REG[0x1010]
#define PORTF REG[0x1011]
#define TIFR0 REG[0x1015]
#define TIFR1 REG[0x1016]
#define TIFR3 REG[0x1018]
#define TIFR4 REG[0x1019]
#define TIFR5 REG[0x101A]
#define PCIFR REG[0x101B]
#define EIFR REG[0x101C]
#define EIMSK REG[0x101D]
#define GPIOR0 REG[0x101E]
#define EECR REG[0x101F]
#define EEDR REG[0x1020]
#define EEAR REG[0x2021]
#define EEARL REG[0x1021]
#define EEARH REG[0x1022]
#define GTCCR REG[0x1023]
#define TCCR0A REG[0x1024]
#define TCCR0B REG[0x1025]
#define TCNT0 REG[0x1026]
#define OCR0A REG[0x1027]
#define OCR0B REG[0x1028]
#define PLLCSR REG[0x1029]
#define GPIOR1 REG[0x102A]
#define GPIOR2 REG[0x102B]
#define SPCR REG[0x102C]
#define SPSR REG[0x102D]
#define SPDR REG[0x102E]
#define ACSR REG[0x1030]
#define OCDR REG[0x1031]
#define PLLFRQ REG[0x1032]
#define SMCR REG[0x1033]
#define MCUSR REG[0x1034]
#define MCUCR REG[0x1035]
#define SPMCSR REG[0x1037]
#define RAMPZ REG[0x103B]
#define EIND REG[0x103C]
#define WDTCSR REG[0x3060]
#define CLKPR REG[0x3061]
/* Reserved [0x62..0x63] */
#define PRR0 REG[0x3064]
#define PRR1 REG[0x3065]
#define OSCCAL REG[0x3066]
#define RCCTRL REG[0x3067]
#define PCICR REG[0x3068]
#define EICRA REG[0x3069]
#define EICRB REG[0x306A]
#define PCMSK0 REG[0x306B]
/* Reserved [0x6C..0x6D] */
#define TIMSK0 REG[0x306E]
#define TIMSK1 REG[0x306F]
/* Reserved [0x70] */
#define TIMSK3 REG[0x3071]
#define TIMSK4 REG[0x3072]
/* Reserved [0x73..0x77] */
#ifndef __ASSEMBLER__
#define ADC REG[0x4078]
#endif
#define ADCW REG[0x4078]
#define ADCL REG[0x3078]
#define ADCH REG[0x3079]
#define ADCSRA REG[0x307A]
#define ADCSRB REG[0x307B]
#define ADMUX REG[0x307C]
#define DIDR2 REG[0x307D]
#define DIDR0 REG[0x307E]
#define DIDR1 REG[0x307F]
#define TCCR1A REG[0x3080]
#define TCCR1B REG[0x3081]
#define TCCR1C REG[0x3082]
/* Reserved [0x83] */
#define TCNT1 REG[0x4084]
#define TCNT1L REG[0x3084]
#define TCNT1H REG[0x3085]
#define ICR1 REG[0x4086]
#define ICR1L REG[0x3086]
#define ICR1H REG[0x3087]
#define OCR1A REG[0x4088]
#define OCR1AL REG[0x3088]
#define OCR1AH REG[0x3089]
#define OCR1B REG[0x408A]
#define OCR1BL REG[0x308A]
#define OCR1BH REG[0x308B]
#define OCR1C REG[0x408C]
#define OCR1CL REG[0x308C]
#define OCR1CH REG[0x308D]
/* Reserved [0x8E..0x8F] */
#define TCCR3A REG[0x3090]
#define TCCR3B REG[0x3091]
#define TCCR3C REG[0x3092]
/* Reserved [0x93] */
#define TCNT3 REG[0x4094]
#define TCNT3L REG[0x3094]
#define TCNT3H REG[0x3095]
#define ICR3 REG[0x4096]
#define ICR3L REG[0x3096]
#define ICR3H REG[0x3097]
#define OCR3A REG[0x4098]
#define OCR3AL REG[0x3098]
#define OCR3AH REG[0x3099]
#define OCR3B REG[0x409A]
#define OCR3BL REG[0x309A]
#define OCR3BH REG[0x309B]
#define OCR3C REG[0x409C]
#define OCR3CL REG[0x309C]
#define OCR3CH REG[0x309D]
/* Reserved [0x9E..0xB7] */
#define TWBR REG[0x30B8]
#define TWSR REG[0x30B9]
#define TWAR REG[0x30BA]
#define TWDR REG[0x30BB]
#define TWCR REG[0x30BC]
#define TWAMR REG[0x30BD]
#define TCNT4 REG[0x40BE]
#define TCNT4L REG[0x30BE]
#define TCNT4H REG[0x30BF]  /* Alias for naming consistency. */
#define TC4H REG[0x30BF]    /* Per XML device file. */
#define TCCR4A REG[0x30C0]
#define TCCR4B REG[0x30C1]
#define TCCR4C REG[0x30C2]
#define TCCR4D REG[0x30C3]
#define TCCR4E REG[0x30C4]
#define CLKSEL0 REG[0x30C5]
#define CLKSEL1 REG[0x30C6]
#define CLKSTA REG[0x30C7]
#define UCSR1A REG[0x30C8]
#define UCSR1B REG[0x30C9]
#define UCSR1C REG[0x30CA]
#define UCSR1D REG[0x30CB]
#define UBRR1 REG[0x40CC]
#define UBRR1L REG[0x30CC]
#define UBRR1H REG[0x30CD]
#define UDR1 REG[0x30CE]
#define OCR4A REG[0x30CF]
#define OCR4B REG[0x30D0]
#define OCR4C REG[0x30D1]
#define OCR4D REG[0x30D2]
/* Reserved [0xD3] */
#define DT4 REG[0x30D4]
/* Reserved [0xD5..0xD6] */
#define UHWCON  REG[0x30D7]
#define USBCON  REG[0x30D8]
#define USBSTA  REG[0x30D9]
#define USBINT  REG[0x30DA]
/* Reserved [0xDB..0xDF] */
#define UDCON REG[0x30E0]
#define UDINT REG[0x30E1]
#define UDIEN REG[0x30E2]
#define UDADDR REG[0x30E3]
#define UDFNUM REG[0x40E4]
#define UDFNUML REG[0x30E4]
#define UDFNUMH REG[0x30E5]
#define UDMFN REG[0x30E6]
/* Reserved [0xE7] */
#define UEINTX REG[0x30E8]
#define UENUM REG[0x30E9]
#define UERST REG[0x30EA]
#define UECONX REG[0x30EB]
#define UECFG0X REG[0x30EC]
#define UECFG1X REG[0x30ED]
#define UESTA0X REG[0x30EE]
#define UESTA1X REG[0x30EF]
#define UEIENX REG[0x30F0]
#define UEDATX REG[0x30F1]
#define UEBCX REG[0x40F2]
#define UEBCLX REG[0x30F2]
#define UEBCHX REG[0x30F3]
#define UEINT REG[0x30F4]


#define uint8_t unsigned char
#define uint16_t unsigned short 
extern uint8_t REGvalue;
uint8_t Register_read_byte(const uint16_t Waddress);
void Register_write_byte(const uint16_t Waddress, uint8_t value);


struct ASMRef {
	uint16_t myindex;
	ASMRef(const int index)
		: index(index) {
		myindex = index;
	}

	//Access/read members.
	uint8_t operator*() const { return Register_read_byte(myindex); }
	operator const uint8_t() const { return **this; }

	//Assignment/write members.
	ASMRef &operator=(const ASMRef &ref) { return *this = *ref; }
	ASMRef &operator=(uint8_t in) { return Register_write_byte(myindex, in), *this; }
	ASMRef &operator +=(uint8_t in) { return *this = REGvalue + in; }
	ASMRef &operator -=(uint8_t in) { return *this = REGvalue - in; }
	ASMRef &operator *=(uint8_t in) { return *this = REGvalue * in; }
	ASMRef &operator /=(uint8_t in) { return *this = REGvalue / in; }
	ASMRef &operator ^=(uint8_t in) { return *this = REGvalue ^ in; }
	ASMRef &operator %=(uint8_t in) { return *this = REGvalue % in; }
	ASMRef &operator &=(uint8_t in) { return *this = REGvalue & in; }
	ASMRef &operator |=(uint8_t in) { return *this = REGvalue | in; }
	ASMRef &operator <<=(uint8_t in) { return *this = REGvalue << in; }
	ASMRef &operator >>=(uint8_t in) { return *this = REGvalue >> in; }

	ASMRef &uupdate(uint8_t in) { return  in != *this ? *this = in : *this; }

	/** Prefix increment/decrement **/
	ASMRef& operator++() { return *this += 1; }
	ASMRef& operator--() { return *this -= 1; }

	/** Postfix increment/decrement **/
	uint8_t operator++ (int) {
		uint8_t ret = **this;
		return ++(*this), ret;
	}

	uint8_t operator-- (int) {
		uint8_t ret = **this;
		return --(*this), ret;
	}

	int index; //Index of current EEPROM cell.
};

/***
	ASMPtr class.

	This object is a bidirectional pointer to EEPROM cells represented by ASMRef objects.
	Just like a normal pointer type, this can be dereferenced and repositioned using
	increment/decrement operators.
***/

struct ASMPtr {

	ASMPtr(const int index)
		: index(index) {}

	operator const int() const { return index; }
	ASMPtr &operator=(int in) { return index = in, *this; }

	//Iterator functionality.
	bool operator!=(const ASMPtr &ptr) { return index != ptr.index; }
	ASMRef operator*() { return index; }

	/** Prefix & Postfix increment/decrement **/
	ASMPtr& operator++() { return ++index, *this; }
	ASMPtr& operator--() { return --index, *this; }
	ASMPtr operator++ (int) { return index++; }
	ASMPtr operator-- (int) { return index--; }

	int index; //Index of current EEPROM cell.
};

/***
	EEPROMClass class.

	This object represents the entire EEPROM space.
	It wraps the functionality of ASMPtr and ASMRef into a basic interface.
	This class is also 100% backwards compatible with earlier Arduino core releases.
***/

struct ASMClass {

	//Basic user access methods.
	ASMRef operator[](const int idx) { return idx; }
	uint8_t read(int idx) { return ASMRef(idx); }
	void write(int idx, uint8_t val) { (ASMRef(idx)) = val; }
	void update(int idx, uint8_t val) { ASMRef(idx).uupdate(val); }

	//STL and C++11 iteration capability.
	ASMPtr begin() { return 0x00; }
	ASMPtr end() { return length(); } //Standards requires this to be the item after the last valid entry. The returned pointer is invalid.
	uint16_t length() { return EE2END + 1; }

	//Functionality to 'get' and 'put' objects to and from EEPROM.
	template< typename T > T &get(int idx, T &t) {
		ASMPtr e = idx;
		uint8_t *ptr = (uint8_t*)&t;
		for (int count = sizeof(T); count; --count, ++e)  *ptr++ = *e;
		return t;
	}

	template< typename T > const T &put(int idx, const T &t) {
		ASMPtr e = idx;
		const uint8_t *ptr = (const uint8_t*)&t;
		for (int count = sizeof(T); count; --count, ++e)  (*e).uupdate(*ptr++);
		return t;
	}
};

static ASMClass REG;

