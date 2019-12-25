
#include "stdafx.h"
#include "FuncsLib.h"
#include "PortChat.h"

//InternalSerial SER;
/*
namespace AFuncs
{
	byte SERIAL::InitSerial(byte ch)
	{
		//return SER.initSerial(ch);
		return ch+2;
	}
}
*/

#include "stdafx.h"
#include "FuncsLib.h"

#include <stdexcept>

using namespace std;

namespace MathFuncs
{
	double MyMathFuncs::Add(double a, double b)
	{
		return a + b;
	}

	double MyMathFuncs::Subtract(double a, double b)
	{
		return a - b;
	}

	double MyMathFuncs::Multiply(double a, double b)
	{
		return a * b;
	}

	double MyMathFuncs::Divide(double a, double b)
	{
		return a / b;
	}
}
