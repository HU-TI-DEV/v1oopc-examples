#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES += inputController.cpp joystick.cpp motorController.cpp PCA9685.cpp
SOURCES += Transmit433mhzController.cpp

# header files in this project
HEADERS += inputController.hpp joystick.hpp motorController.hpp PCA9685.hpp
HEADERS += Transmit433mhzController.cpp

# other places to look for files for this project
SEARCH  += inc lib

PROJECT := mainCar

# set RELATIVE to the next higher directory 
# and defer to the appropriate Makefile.* there
RELATIVE := ..
include $(RELATIVE)/Makefile.due