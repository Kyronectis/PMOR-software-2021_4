#include "Functions.h"
#define TO_PWM 2.5f; //conversion value volt to PWM

float JSN_SR04T(PinName trig, PinName echo){
    DigitalOut UStrig(trig);  //Ultrasonic trigger pin
    DigitalIn USecho(echo);   //Ultrasonic echo pin

    int correction = 0;
    Timer sonar;
    float sonar_distance = 0; //Variable for distance from ultrasonic sensor
 
    sonar.reset();
    // measure actual software polling timer delays
    // delay used later in time correction
    sonar.start(); // start timer
    while (USecho==2) {}; // min software polling delay to read USecho pin
    sonar.stop(); // stop timer
    correction = sonar.elapsed_time().count(); // read timer
    //printf("Approximate software overhead timer delay is %d uS\n\r",correction);
 
    // UStrig sonar to send a ping
    UStrig = 1;
    sonar.reset();
    wait_us(20.0);
    UStrig = 0;
    while (USecho==0) {}; //wait for echo high
    sonar.start(); //echo high, so start timer
    while (USecho==1) {}; //wait for echo low
    sonar.stop(); //stop timer and read value
    float sonar_corrected = (sonar.elapsed_time().count()-correction); //subtract software overhead timer delay and scale to cm
    sonar_distance = sonar_corrected * 0.0343 / 2; //speed of sound in water is 1482 m/s, currently set at sos in air for testing
    //printf(" %d cm \n\r", sonar_distance);
    //wait so that any echo(s) return before sending another ping
    ThisThread::sleep_for(40ms);
    
    return sonar_distance;
}

float KY023JM(PinName joystick){
    AnalogIn JSpos(joystick);     //Joystick position pin
    float position;
    float volt = JSpos - 2.5; //Voltage output of joystick, shifted down by 2.5 volts
    position = volt / TO_PWM; //Convert voltage to percentage
    return position;
}

void LCD164(
    float distance, 
    bool power, 
    bool hover, 
    bool control,  
    TextLCD lcd,
    string message
){
    lcd.locate(0, 0);
    lcd.printf("PWR %s", power ? "ON " : "OFF");
    lcd.locate(0, 1);
    lcd.printf("HVR %s", hover ? "ON " : "OFF");
    lcd.locate(0, 2);
    lcd.printf("CTL %s", control ? "ON " : "OFF");
    char msg_c[16];
    strcpy(msg_c, message.c_str());
    lcd.locate(0, 3);
    lcd.printf("%s", msg_c);
    lcd.locate(10, 0);
    lcd.printf("%.2f", distance);
}

bool SW_NC(PinName port, bool type){ //Type 0 for regular switch, Type 1 for Microswitch
    DigitalIn SW(port);
    bool state = SW;
    if(type){
        return !state; //Microswitches are normally closed and therefore inverted
    }
    else{
        return state;
    }
}

int init(BTS7960 hbridge, TextLCD lcd, PinName T, PinName E, PinName SH, PinName GO){
    
    return 0;
}
