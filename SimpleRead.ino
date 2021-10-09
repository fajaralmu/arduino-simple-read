
#include "Process.h"
#define KEY_ENTER 13

void setup() {
    setLedPin(13);
    setupProcess();
    // initialize digital pin 13 as an output.
    int led = getLedPin();
    pinMode(led, OUTPUT);
    Serial.begin(9600); // opens serial port, sets data rate to 9600 bps

    Serial.println("========== Welcome ==========");
    Serial.println("Press 1 to turn on LED, press 0 to turn off LED, press 2 to blink LED");
}


int readInput() {
    
    // send data only when you receive data:
    if (Serial.available() > 0) {
        // read the incoming byte:
        int newByte = Serial.read();
        char c = newByte;
        Serial.println("");
        const char * str = "Input Received:";
        Serial.print(str);
        Serial.println(newByte);
        return newByte;
    }
    return -1;
}


void checkInput(int input)
{
    boolean savedInput = checkAndSaveInput(input);
    if (savedInput)
    {
        Serial.println(">> Will save input. Press 'Enter' to apply");
    }
    else if (input != KEY_ENTER)
    {
        Serial.println("<!> Will not save input");
    }
}

void loop() {
    int lastActive = getActiveCommand();
    int input = readInput();
    if (input > 0) {

        checkInput(input);
        
        if (input == KEY_ENTER) {
            char* modeInString = applyCommand();
            Serial.print("Applying command:");
            Serial.println(modeInString);
        }
    }
    doAction(lastActive);
    delay(1);
}