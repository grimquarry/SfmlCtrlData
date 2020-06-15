/**
    SFML-Extension/SfmlCtrl
    SfmlCtrl.h
    Purpose: Header file for the SfmlCtrl datatype used to store information pulled
    for an individual usb controller/joystick using the SFML library.  No cpp file.
    @author Jeremiah Kellogg
    @version 1.0.0 2020-06-14
*/
#pragma once
#include <string>  //Dynamically linked from Standard Library

struct SfmlCtrl
{
  int index; //Index used by SFML to identify the currently plugged in controller
  std::string name; //Meant to store name using SFML function sf::Joystick::getIdentification(index).name
  int productId; //Meant to store usb product ID using SFML function sf::Joystick::getIdentification(index).productId
  int vendorId; //Meant to store usb vendor ID using SFML function sf::Joystick::getIdentification(index).vendorId
  std::string vendorName; //Meant to store vendor name from the usb.ids list, which can be done by using the getVendorName
                          //method from the UsbIdData class and passing it the vendorId (converted to hex) as a parameter
  unsigned int numberOfButtons; //Number of buttons recognized by SFML using the function sf::Joystick::getButtonCount(index)
  bool xAxisSupport; //Meant to store x axis support using SFML function sf::Joystick::hasAxis(index, sf::Joystick::X)
  bool yAxisSupport; //Meant to store y axis support using SFML function sf::Joystick::hasAxis(index, sf::Joystick::Y)
  bool zAxisSupport; //Meant to store z axis support using SFML function sf::Joystick::hasAxis(index, sf::Joystick::Z)
  bool uAxisSupport; //Meant to store u axis support using SFML function sf::Joystick::hasAxis(index, sf::Joystick::U)
  bool vAxisSupport; //Meant to store v axis support using SFML function sf::Joystick::hasAxis(index, sf::Joystick::V)
  bool povXAxisSupport; //Meant to store PovX axis support using SFML function sf::Joystick::hasAxis(index, sf::Joystick::PosX)
  bool povYAxisSupport; //Meant to store PovY axis support using SFML function sf::Joystick::hasAxis(index, sf::Joystick::PosY)
};
