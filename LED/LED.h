#ifndef _LED__
#define _LED__

#include "Arduino.h"

class LED
{
private:
    int pin = 2;
    int range = 1000;

public:
    LED(int pin);
    ~LED();
    void mode(int i);
    void setRange(int range);
};
#endif
