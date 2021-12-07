#include "Functions.h"
#define JSH_P A0    //joystick scissor
#define JSG_P A1    //joystick gripper
#define POWSW_P PB_2  //power button
#define HVRSW_P D9  //hover button
#define EMRSW_P D2  //emergency button
#define SEN_P D3    //scissor enable
#define GEN_P D4    //gripper enable
#define SPWM_P D5   //scissor pwm
#define GPWM_P D6   //gripper pwm
#define UST_P D7    //ultrasonic trigger
#define USE_P D8    //ultrasonic echo
#define LCD_RS_P D10//LCD RS
#define LCD_E_P D11 //LCD E
#define LCD_D1_P D12//LCD data 1
#define LCD_D2_P D13//LCD data 2
#define LCD_D3_P D14//LCD data 3
#define LCD_D4_P D15//LCD data 4
#define MS_GO_P PB_13 //microswitch gripper open
#define MS_GC_P PB_14 //microswitch gripper closed
#define MS_SH_P PB_15 //microswitch scissor high
#define MS_SL_P PB_1  //microswitch scissor low

int main(){
    //while(1){
    BTS7960 motors(SEN_P, GEN_P, SPWM_P, GPWM_P);
    TextLCD lcd(LCD_RS_P, LCD_E_P, LCD_D1_P, LCD_D2_P, LCD_D3_P, LCD_D4_P, TextLCD::LCD16x4);
    string message = "";

    bool SW_POW = 0;
    bool SW_HVR = 0;
    bool TG_HVR = 0; //toggle var for hover switch
    bool SW_EMR = 0;
    bool TG_EMR = 0; //toggle var for emergency switch
    bool MS_GO = 0;
    bool MS_GC = 0;
    bool MS_SH = 0;
    bool MS_SL = 0;

    float distance = 0.0f;

    float JS_Height = 0;
    float JS_Gripper = 0;

    message = "Standby...";
    
    while(1){
        distance = JSN_SR04T(UST_P, USE_P);
        JS_Height = KY023JM(JSH_P);
        printf("%f cm\n", distance);
        printf("%f %%\n", JS_Height);
        thread_sleep_for(100);
    }
    
    /*LCD164(distance, SW_POW, SW_HVR, SW_EMR, lcd, message);

    while(!SW_POW){ //standby mode, wait until power switch is turned on
        SW_POW = SW_NC(POWSW_P);
        thread_sleep_for(100);
    }

    int init_s = init(motors, lcd, UST_P, USE_P, MS_SH_P, MS_GO_P);
    switch(init_s){
        case 0:
            message = "System ready";
            break;
        case 1:
            message = "ERR: USCONNECT";
            SW_POW = 0;
            break;
        case 2:
            message = "ERR: LCDCONNECT";
            SW_POW = 0;
            break;
        default:
            message = "ERR: UNKNOWN";
            SW_POW = 0;
            break;
    }
    LCD164(distance, SW_POW, SW_HVR, SW_EMR, lcd, message);

    

    while(SW_POW){
        

        LCD164(distance, SW_POW, SW_HVR, SW_EMR, lcd, message);
        thread_sleep_for(100);
    }
    //}*/
    return 0;
}
