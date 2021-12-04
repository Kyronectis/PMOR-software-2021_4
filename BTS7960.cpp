#include "BTS7960.h"

BTS7960::BTS7960(PinName L_EN, PinName R_EN, PinName L_PWM, PinName R_PWM){
    PWML_PIN = L_PWM;
    PWMR_PIN = R_PWM;
    ENL_PIN = L_EN;
    ENR_PIN = R_EN;
}

void BTS7960::Left(float period, float c_w){
    PwmOut PWML(PWML_PIN);
    PWML.period(period);
    PWML = c_w;
}

void BTS7960::Right(float period, float c_w){
    PwmOut PWMR(PWMR_PIN);
    PWMR.period(period);
    PWMR = c_w;
}

void BTS7960::Enable(){
    DigitalOut ENL(ENL_PIN);
    DigitalOut ENR(ENR_PIN);
	ENL = 1;
	ENR = 1;  
}

void BTS7960::Disable(){
    DigitalOut ENL(ENL_PIN);
    DigitalOut ENR(ENR_PIN);
	ENL = 0;
	ENR = 0;
}

void BTS7960::Stop(){
    PwmOut PWML(PWML_PIN);
    PwmOut PWMR(PWMR_PIN);
    PWML.suspend();
    PWMR.suspend();
}

void BTS7960::Resume(){
    PwmOut PWML(PWML_PIN);
    PwmOut PWMR(PWMR_PIN);
    PWML.resume();
    PWMR.resume();
}