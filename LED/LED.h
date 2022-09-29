#ifndef _LED_
#define _LED_

#include "Arduino.h"
#include <ritos.h>

class LED
{
private:
    int pin = 2;
    int range = 1000;
    int rangeStep = 1;
    int mstep = 1;
    int _range = range * 2;
    int ms = millis();
    int mode = 0;
    void setRange(int range);
    void setMStep(int _mstep);
    void setRangeStep(int _rangeStep);
    void pwmTherad();
    void twinkleTherad();
    // static void staticLEDTherad();

public:
    LED(int pin);
    ~LED();
    void setMode(int i);
    void pilotLED();
};

#endif
