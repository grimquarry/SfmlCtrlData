/**
    Math/DecToHex
    DecToHex.cpp
    Purpose: Header file for a class that converts decimal integers to a Hexidecimal string.
    @author Jeremiah Kellogg
    @version 1.0.0 2020-06-14
*/
#include "DecToHex.h"

DecToHex::DecToHex()
{
  divisor = 16; //divisor set to 16 for hexidecimal values
	remainder = 0;
}

DecToHex::~DecToHex() { }

//Returns a Hexidecimal string when passed an integer.
std::string DecToHex::ConvertToHex(int dec)
{
  dividend = dec;
  while(quotient != 0)
	{
      quotient = dividend/divisor;
			remainder = dividend % divisor;
			hexDigits.insert(hexDigits.begin(), hexTable[remainder]);

			dividend = quotient;
	}

	while(hexDigits.size() < 4)
	{
		hexDigits.insert(hexDigits.begin(), '0');
	}

	for(int i = 0; i < hexDigits.size(); i++)
	{
		value.push_back(hexDigits[i]);
	}

	hexDigits.clear();

	return value;
}
