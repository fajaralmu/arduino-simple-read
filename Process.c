// 
// 
// 

#include "Process.h"

int SAVED_COMMANDS[3] = { 0 };
unsigned long tick;
boolean blinkTurnOn = 1;

#define KEY_1       49
#define KEY_0       48
#define KEY_2       50

#define MODE_HI     1
#define MODE_LOW    0
#define MODE_BLNK   3

unsigned int ACTIVE;
int savedByte; // for incoming serial data

int getSavedByte() { return savedByte; }

void setupProcess() {
    savedByte   = KEY_0;
    ACTIVE      = MODE_LOW;

    SAVED_COMMANDS[0] = KEY_0;
    SAVED_COMMANDS[1] = KEY_1;
    SAVED_COMMANDS[2] = KEY_2;
}

boolean matchCommand(int input) {
    return match(input, SAVED_COMMANDS, 3);
}

boolean checkAndSaveInput(int newByte)
{
    boolean matchResult = matchCommand(newByte);
    if (matchResult == 1)
    {
        savedByte = newByte;
        return 1;
    }
    return matchResult;
}

void doBlink() {
    long lastTime = millis();
    if (lastTime - tick < 500)
        return;

    blinkTurnOn = !blinkTurnOn;
    tick = lastTime;
    digitalWrite(getLedPin(), blinkTurnOn ? LOW : HIGH);

}

boolean doAction(int lastActive) {
    boolean activeChanged = lastActive != ACTIVE;
    
    lastActive = ACTIVE;
    if (ACTIVE == MODE_HI)
        if (activeChanged) digitalWrite(getLedPin(), HIGH);
    if (ACTIVE == MODE_LOW)
        if (activeChanged) digitalWrite(getLedPin(), LOW);
    if (ACTIVE == MODE_BLNK)
        doBlink();

    return ACTIVE;
}

int getActiveCommand()
{
    return ACTIVE;
}

char * applyCommand() {
    unsigned char* modeInString;
    
    if (savedByte == KEY_1) {
        modeInString = "MODE HI";
        ACTIVE = MODE_HI;
    }
    else if (savedByte == KEY_0) {
        modeInString = "MODE LOW";
        ACTIVE = MODE_LOW;
    }
    else if (savedByte == KEY_2) {
        modeInString = "MODE BLINK";
        ACTIVE = MODE_BLNK;
    }
    else {
        return "INVALID MODE";
    }
    return modeInString;
}



