#include <mbed.h>
#include <string>
#include <TextLCD.h>
#include <BTS7960.h>

float JSN_SR04T(PinName trig, PinName echo);
float KY023JM(PinName joystick);
void LCD164(
    float distance, 
    bool power, 
    bool hover, 
    bool control, 
    PinName RS, 
    PinName E, 
    PinName DATA1, 
    PinName DATA2, 
    PinName DATA3, 
    PinName DATA4,
    string message = "" 
);
bool SW_NC(PinName port, bool type = 0);