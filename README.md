This is a class designed to facilitate grabbing and storing data using the SFML Joystick class. It will run on Debian
based systems and stores information on usb controllers/joysticks.  It focuses partiularly on index to button label
mapping as well what axes are supported for a usb controller/joystick.  This class depends on a number of things and
must be compiled using the C++17 Standard Library (anything below that won't work).  Other important dependencies:
Dynamicall Linked SFML Library for Linux: https://www.sfml-dev.org/
DecToHex Class: https://github.com/grimquarry/DecToHexConverter
SfmlCtrl Datatype: https://github.com/grimquarry/SfmlCtrl
UsbIdData Class: https://github.com/grimquarry/UsbIdData
This repo includes all dependencies that aren't dynamicall linked.  People can clone it and grab all the .h and .cpp
files to add to their own projects.  A driver propgram is included in the repo for testing and to provide and example
of how to use this class.  To compile the driver program a Makefile is included.  Simply run the "make" command from
the terminal while in the directory you're cloned this repo to.  Once compiled you can type ./runDriver on the command
line to run the test program.  

