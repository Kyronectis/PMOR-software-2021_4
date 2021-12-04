#include <mbed.h>

class BTS7960
{
  public:
    BTS7960(PinName L_EN, PinName R_EN, PinName L_PWM, PinName R_PWM);
    void Enable();
    void Disable();

	void Left(float period, float c_w);
	void Right(float period, float c_w);
	void Stop();
    void Resume();

  private:
    PinName PWML_PIN;
    PinName PWMR_PIN;
    PinName ENL_PIN;
    PinName ENR_PIN;
};