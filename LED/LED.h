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
    int msStep = 1;
    int _range = range * 2;
    int ms = millis();
    // static void staticLEDTherad();

public:
    LED(int pin);
    ~LED();
    void mode(int i);
    void setRange(int range);
    void ledTherad();
};

#endif
