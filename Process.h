// Process.h
#include "HardwareResources.h"
#include "InputParses.h"
#ifndef _PROCESS_h
#define _PROCESS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif


#ifdef __cplusplus
extern "C" {
#endif
	int getSavedByte();
	int getActiveCommand();
	char* getModeString(int modeInt);

	void setupProcess();
	char* applyCommand();

	boolean doAction(int lastActive);
	boolean checkAndSaveInput(int newByte);
#ifdef __cplusplus
}
#endif


