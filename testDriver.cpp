/**
    SFML-Extension/SfmlCtrlData
    testDriver.cpp
    Purpose: A test driver for the SfmlCtrlData class.
    @author Jeremiah Kellogg
    @version 1.0.0 2020-06-14
*/
#include <iostream>
#include "SfmlCtrlData.h"

int main()
{
  SfmlCtrlData sfmlCtrlData; //Instantiate a SfmlCtrlData ojbect

  if(sfmlCtrlData.getControllers()) // Test the getContollers method.
  {
    std::cout << "The following controllers were found with the getContollers method: " << std::endl;
    for(int i = 0; i < sfmlCtrlData.controllers.size(); ++i)
    {
      std::cout << "\t Index: " << sfmlCtrlData.controllers[i].index << std::endl;
      std::cout << "\t\tController Vendor: " << sfmlCtrlData.controllers[i].vendorName << std::endl;
      std::cout << "\t\tController Name: " << sfmlCtrlData.controllers[i].name << std::endl;
      std::cout << "\t\tController Product ID: " << sfmlCtrlData.controllers[i].productId << std::endl;
    }
    int selection;
    std::cout << "Test the getButtonIndicies method by entering any Index number from above now: ";
    std::cin >> selection;
    if (std::cin.fail())
    {
      std::cout << "That was an invalid seclection, exiting program" << std::endl;
      std::cin.clear();
      std::cin.ignore();
      sfmlCtrlData.controllers.clear();
    }
    else if(selection >= 0 && selection <= sfmlCtrlData.controllers.size() - 1)
    {
      std::cout << "Results for index " << selection << ":" << std::endl;
      sfmlCtrlData.getButtonIndicies(selection); //Test the getButtonIndicies method.
    }
    else
    {
      std::cout << selection << " isn't a valid index, exiting program" << std::endl;
      sfmlCtrlData.controllers.clear();
      std::cin.clear();
      std::cin.ignore();
    }

  }
  else
  {
    std::cout << "No controllers were found with the getContollers method, exiting program." << std::endl;
  }

  return 0;
}
