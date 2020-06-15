/**
    SFML-Extension/SfmlCtrlData
    SfmlCtrlData.cpp
    Purpose: Header file for the SfmlCtrlData class used to pull data about
    an individual usb controller/joystick using the standard SFML library.
    @author Jeremiah Kellogg
    @version 1.0.0 2020-06-14
*/
#include "SfmlCtrlData.h"

SfmlCtrlData::SfmlCtrlData()
{
   joystickFound = false;

}
SfmlCtrlData::~SfmlCtrlData() { }

//Define the controller vector declared in the header file
std::vector<SfmlCtrl> SfmlCtrlData::controllers;

//Returns true and populates the controllers vector with data if controllers are found.
bool SfmlCtrlData::getControllers()
{
  controllers.clear();
  sf::Joystick::update();

	for(int i = 0; i < sf::Joystick::Count; ++i)
	{
		if(sf::Joystick::isConnected(i))
		{
			joystickFound = true;

			controller.index = i;
			controller.name = sf::Joystick::getIdentification(i).name;
			controller.productId = sf::Joystick::getIdentification(i).productId;
			controller.vendorId = sf::Joystick::getIdentification(i).vendorId;
			controller.vendorName = usbIdData.getVendorName(decToHexCalc.ConvertToHex(sf::Joystick::getIdentification(i).vendorId));
      controller.numberOfButtons = sf::Joystick::getButtonCount(i);
      controller.xAxisSupport = sf::Joystick::hasAxis(i, sf::Joystick::X);
      controller.yAxisSupport = sf::Joystick::hasAxis(i, sf::Joystick::Y);
      controller.zAxisSupport = sf::Joystick::hasAxis(i, sf::Joystick::Z);
      controller.uAxisSupport = sf::Joystick::hasAxis(i, sf::Joystick::U);
      controller.vAxisSupport = sf::Joystick::hasAxis(i, sf::Joystick::V);
      controller.povXAxisSupport = sf::Joystick::hasAxis(i, sf::Joystick::PovX);
      controller.povYAxisSupport = sf::Joystick::hasAxis(i, sf::Joystick::PovY);

			controllers.push_back(controller);
		}
	}
	return joystickFound;
}

//Allows for the mapping of controller buttons to the button index recognized by SFML.
//Users will also be given the option of saving those mappings and axes data to a txt document.
void SfmlCtrlData::getButtonIndicies(int l_ctrlIndex)
{
	sf::Joystick::update();
  int numberOfButtons = controllers[l_ctrlIndex].numberOfButtons;
	std::cout << "*********" << controllers[l_ctrlIndex].name << " has " << numberOfButtons << " SFML supported buttons.*********" << std::endl;
  std::cout << "\n*********Here is a list of supported axes for this controller*********" << std::endl;
  if(controllers[l_ctrlIndex].xAxisSupport)
	{
		std::cout << "\tX axis support: Yes" << std::endl;
	}
	else
	{
		std::cout << "\tX axis support: No" << std::endl;
	}
	if(controllers[l_ctrlIndex].yAxisSupport)
	{
		std::cout << "\tY axis support: Yes" << std::endl;
	}
	else
	{
		std::cout << "\tY axis support: No" << std::endl;
	}
	if(controllers[l_ctrlIndex].zAxisSupport)
	{
		std::cout << "\tZ axis support: Yes" << std::endl;
	}
	else
	{
		std::cout << "\tZ axis support: No" << std::endl;
	}
	if(controllers[l_ctrlIndex].uAxisSupport)
	{
		std::cout << "\tU axis: Yes" << std::endl;
	}
	else
	{
		std::cout << "\tU axis support: No" << std::endl;
	}
	if(controllers[l_ctrlIndex].vAxisSupport)
	{
		std::cout << "\tV axis support: Yes" << std::endl;
	}
	else
	{
		std::cout << "\tV axis support: No" << std::endl;
	}
	if(controllers[l_ctrlIndex].povXAxisSupport)
	{
		std::cout << "\tPovX axis: Yes" << std::endl;
	}
	else
	{
		std::cout << "\tPovX axis: No" << std::endl;
	}
	if(controllers[l_ctrlIndex].povYAxisSupport)
	{
		std::cout << "\tPovY axis support: Yes" << std::endl;
	}
	else
	{
		std::cout << "\tPovY axis: No" << std::endl;
	}

  //Local variable array for mapping a button index number to a button label inputed by the user
	std::string buttonArray[numberOfButtons];
  bool findButtons = true;
	std::cout << "\n*********Push a button on the " << controllers[l_ctrlIndex].name << " controller to get its index.  " <<
							"Press esacpe button (Esc) at any time to quit.\nWhen all buttons have been indexed press left ctrl+s buttons*********"  << std::endl;
	while(findButtons)
	{
		sf::Joystick::update();
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			findButtons = false;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			int columnSpacing = 14;
			std::cout << "Here are your button indicies:\n" << std::endl;
			std::cout << std::left << UNDERLINE << "Index" << CLOSEUNDERLINE << std::setw(columnSpacing) << UNDERLINE << "Button Label" << CLOSEUNDERLINE << std::endl;
			for(int i = 0; i < numberOfButtons; ++i)
			{
				std::cout << std::left << std::setw(columnSpacing) << i << std::setw(columnSpacing) << buttonArray[i] << std::endl;
			}
			char input;
			bool inputValidation = true;

			while(inputValidation)
			{
				std::cout << "\nWould you like to save this mapping and associated controller info as a text file to the current directory:\n" << std::filesystem::current_path() << " \nY or N: ";
				std::cin >> input;

				if(input == 'Y' || input == 'y')
				{
					std::string ctrlName = controllers[l_ctrlIndex].name;
					std::string formattedFileName = formatFileName(ctrlName);
					std::ofstream ctrlMapping(formattedFileName + "Button-Mappings.txt", std::ofstream::trunc);
					ctrlMapping << "**********Button Indicies for the " << controllers[l_ctrlIndex].name << " controller*********\n" << std::endl;
					ctrlMapping << std::left << std::setw(columnSpacing) << "Index" << std::setw(columnSpacing) << "Button Label" << std::endl;
					ctrlMapping << std::left << std::setw(columnSpacing) << "-----" << std::setw(columnSpacing) << "------------" << std::endl;

					for(int i = 0; i < numberOfButtons; ++i)
					{
						ctrlMapping << std::left << std::setw(columnSpacing) << i << std::setw(columnSpacing) << buttonArray[i] << std::endl;
					}
          ctrlMapping << "\n\n*********List of supported axes for this controller*********" << std::endl;
          if(controllers[l_ctrlIndex].xAxisSupport)
        	{
        		ctrlMapping << "\tX axis support: Yes" << std::endl;
        	}
        	else
        	{
        		ctrlMapping << "\tX axis support: No" << std::endl;
        	}
        	if(controllers[l_ctrlIndex].yAxisSupport)
        	{
        		ctrlMapping << "\tY axis support: Yes" << std::endl;
        	}
        	else
        	{
        		ctrlMapping << "\tY axis support: No" << std::endl;
        	}
        	if(controllers[l_ctrlIndex].zAxisSupport)
        	{
        		ctrlMapping << "\tZ axis support: Yes" << std::endl;
        	}
        	else
        	{
        		ctrlMapping << "\tZ axis support: No" << std::endl;
        	}
        	if(controllers[l_ctrlIndex].uAxisSupport)
        	{
        		ctrlMapping << "\tU axis: Yes" << std::endl;
        	}
        	else
        	{
        		ctrlMapping << "\tU axis support: No" << std::endl;
        	}
        	if(controllers[l_ctrlIndex].vAxisSupport)
        	{
        		ctrlMapping << "\tV axis support: Yes" << std::endl;
        	}
        	else
        	{
        		ctrlMapping << "\tV axis support: No" << std::endl;
        	}
        	if(controllers[l_ctrlIndex].povXAxisSupport)
        	{
        		ctrlMapping << "\tPovX axis: Yes" << std::endl;
        	}
        	else
        	{
        		ctrlMapping << "\tPovX axis: No" << std::endl;
        	}
        	if(controllers[l_ctrlIndex].povYAxisSupport)
        	{
        		ctrlMapping << "\tPovY axis support: Yes" << std::endl;
        	}
        	else
        	{
        		ctrlMapping << "\tPovY axis: No" << std::endl;
        	}

					std::cout << "Saved to directory, exiting program." << std::endl;
					ctrlMapping.close();
					inputValidation = false;
					findButtons = false;

				}
				else if (input == 'N' || input == 'n')
				{
					std::cout << "Okay, exiting program" << std::endl;
					inputValidation = false;
					findButtons = false;
				}
				else
				{
					std::cout << input << " is invalid input, try again.\n"  << std::endl;
				}
			}
		}
		else
		{
			std::string l_buttonLabel;
			for(int i = 0; i < 31; ++i)
			{
				if(sf::Joystick::isButtonPressed(l_ctrlIndex, i))
				{
					std::cout << "Button currently pressed has index of: " << i << std::endl;
					std::cout << "How would you like to label this button (A, B, X, Y, Start, Etc...): ";

					std::cin >> l_buttonLabel;

					buttonArray[i] = l_buttonLabel;
					std::cout << buttonArray[i] << " button has an index of " << i << std::endl;
				}
			}
		}
	}
}

//A function for replacing spaces with a dash for a string to format a filename
std::string SfmlCtrlData::formatFileName(std::string str)
{
	std::string formattedString = str;
	replace(formattedString.begin(), formattedString.end(), ' ', '-');

	return formattedString;
}
