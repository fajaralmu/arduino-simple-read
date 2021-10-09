// InputParses.h

#ifndef _INPUTPARSES_h
#define _INPUTPARSES_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif


#ifdef __cplusplus
extern "C" {
#endif

	boolean match(int value, int * comparators, int size);

#ifdef __cplusplus
}
#endif

