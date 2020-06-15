/**
    SFML-Extension/SfmlCtrlData
    SfmlCtrlData.h
    Purpose: Header file for the SfmlCtrlData class used to pull data about
    an individual usb controller/joystick using the standard SFML library.
    @author Jeremiah Kellogg
    @version 1.0.0 2020-06-14
*/
#pragma once
#include <SFML/Window/Joystick.hpp> //Dynamically Linked (SFML Libraries must be discoverable in your $PATH)
#include <SFML/Graphics.hpp> //Dynamically Linked (SFML Libraries must be discoverable in your $PATH)
#include <vector> //Dynamically linked from Standard Library
#include <iomanip> //Dynamically linked from Standard Library
#include <filesystem> //Availble in c++17 and above.  Will not work without compiling with c++17 or above.
#include "DecToHex.h" //Must be included with its corresponding cpp file in the same directory as this header file.
#include "SfmlCtrl.h" //Must be included in the same directory as this header file (does not have a cpp file).
#include "UsbIdData.h" //Must be included with its corresponding cpp file in the same directory as this header file.

//Set underline ANSI underline values so shell can underline text
#define UNDERLINE "\033[4m"
#define CLOSEUNDERLINE "\033[0m"

class SfmlCtrlData
{
public:
  SfmlCtrlData();
  ~SfmlCtrlData();

  /**
    Returns true and populates the controllers vector
    with data if controllers are found.
  */
  bool getControllers();

  /**
    Allows for the mapping of controller buttons to the button index recognized by SFML.
    Users will also be given the option of saving those mappings and axes data to a txt document.
  	@param l_ctrlIndex The contorller index for the controller that is having its buttons mapped.
  */
  void getButtonIndicies(int l_ctrlIndex);

  //Vector to store multiple contollers if more than one controller is plugged into the computer
  static std::vector<SfmlCtrl> controllers;

private:
  /**
    A function for replacing spaces with a dash for a string to format
    a filename that button mapping and axes data is output to
  	@param str A file name that contains spaces that need to be removed.
  */
  std::string formatFileName(std::string str);

  SfmlCtrl controller; //Datatype for storing information for an individual controller
  DecToHex decToHexCalc; //A Decimal to Hexidecimal conversion calculator
  UsbIdData usbIdData; // An object for gathering information about usb devices that are currently plugged in
  bool joystickFound;  //Used to track whether a joystick or controller was found by SFML
};
