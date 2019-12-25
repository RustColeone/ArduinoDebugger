#pragma once

////////////Change below for card select////////////////
#define leonardo
//#define UNO
////////////////////////////////////////////////////////

 #ifdef leonardo 
#define DebugSerial Serial1
#endif

#ifdef UNO
#define DebugSerial MySerial
//#define DebugSerial Serial1
#endif

//#define esp8266
//////////////////////////////////////////
#define functionGroup   FPCEXcode.ST.FunctionGroup
#define functionNo		FPCEXcode.ST.FunctionNo
#define IN_UBYTE2		FPCEXcode.ST.data2
#define IN_UBYTE3		FPCEXcode.ST.data3

#define IN_UINT2		FPCEXcode.ST.COMB.INT16[1]
#define IN_UINT1		FPCEXcode.ST.COMB.INT16[0]
#define IN_ULONG		FPCEXcode.ST.COMB.ULONG
#define IN_FLOAT		FPCEXcode.ST.COMB.FLOAT

#define	IN_UBYTE7		FPCEXcode.ST.COMB.BYTE[3]
#define	IN_UBYTE6		FPCEXcode.ST.COMB.BYTE[2]
#define	IN_UBYTE5		FPCEXcode.ST.COMB.BYTE[1]
#define	IN_UBYTE4 		FPCEXcode.ST.COMB.BYTE[0]

#define OUT_DUE_ULONG1	DUEdata.ST.COMB[0].ULONG
#define OUT_DUE_ULONG2	DUEdata.ST.COMB[1].ULONG

#define IN_DUE_INT1		DUEdata.ST.COMB[0].INT16[0]
#define IN_DUE_INT2		DUEdata.ST.COMB[0].INT16[1]

#define OUT_INTPT_Action	TPCEXcode.ST.FunctionGroup
#define	OUT_INTPT_Status	TPCEXcode.ST.FunctionNo
#define	OUT_UBYTE2 		TPCEXcode.ST.data2
#define	OUT_UBYTE3 		TPCEXcode.ST.data3
#define	OUT_UBYTE7 		TPCEXcode.ST.COMB.BYTE[3]
#define	OUT_UBYTE6 		TPCEXcode.ST.COMB.BYTE[2]
#define	OUT_UBYTE5 		TPCEXcode.ST.COMB.BYTE[1]
#define	OUT_UBYTE4 		TPCEXcode.ST.COMB.BYTE[0]
#define OUT_UINT16		TPCEXcode.ST.COMB.INT16[0]
#define OUT_ULONG		TPCEXcode.ST.COMB.ULONG
//#define OUT_FLOAT		TPCEXcode.ST.COMB.Float
///////////////////////////////////////////
