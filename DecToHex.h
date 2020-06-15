/**
    Math/DecToHex
    DecToHex.h
    Purpose: Header file for a class that converts decimal integers to a Hexidecimal string.
    @author Jeremiah Kellogg
    @version 1.0.0 2020-06-14
*/
#pragma once
#include <string>  //Dynamically linked from Standard Library
#include <vector>  //Dynamically linked from Standard Library
#include <iostream>  //Dynamically linked from Standard Library

class DecToHex
{
public:
  DecToHex();
  ~DecToHex();

  /**
    Returns a Hexidecimal string when passed an integer.
    @param dec A decimal that needs to be converted to hexidecimal
  */
  std::string ConvertToHex(int dec);

private:
  int divisor;
	int dividend;
	int quotient;
	int remainder;
	std::vector<char> hexDigits; //Container for storing individual digits of the hex value
	std::string value; //The hex value to be returned.
  char hexTable[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
											'9', 'a', 'b', 'c', 'd', 'e', 'f'};
};
