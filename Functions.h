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
    TextLCD lcd,
    string message = "" 
);
bool SW_NC(PinName port, bool type = 0);

int init(BTS7960 hbridge, TextLCD lcd, PinName T, PinName E, PinName SH, PinName GO);
