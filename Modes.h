// Modes.h

#ifndef _MODES_h
#define _MODES_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

extern enum Modes
{
	MODE_LOW = 0, MODE_HIGH = 1, MODE_BLINK = 2
};

