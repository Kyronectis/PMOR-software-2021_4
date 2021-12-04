#include "Functions.h"

int main(){
    while(1){       
        float JS_Height = KY023JM(A0);
        float JS_Gripper = KY023JM(A1);

        bool SW_POW = SW_NC(D0);
        bool SW_HVR = SW_NC(D1);
        bool SW_EMR = SW_NC(D2);

        BTS7960 motors(D3, D4, D5, D6);

        float distance = JSN_SR04T(D7, D8); 

        PinName LCD_RS = D10;
        PinName LCD_E = D11;
        PinName LCD_D1 = D12;
        PinName LCD_D2 = D13;
        PinName LCD_D3 = D14;
        PinName LCD_D4 = D15;

        string message = "";

        LCD164(distance, SW_POW, SW_HVR, SW_EMR, LCD_RS, LCD_E, LCD_D1, LCD_D2, LCD_D3, LCD_D4, message);
        
        thread_sleep_for(1000);
    }
    return 0;
}
