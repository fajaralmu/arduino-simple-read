// HardwareResources.h

#ifndef _HARDWARERESOURCES_h
#define _HARDWARERESOURCES_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#endif

#ifdef __cplusplus
extern "C" {
#endif
	void setLedPin(int pin);
	int getLedPin();
#ifdef __cplusplus
}
#endif

