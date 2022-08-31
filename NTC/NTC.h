#ifndef _NTC__
#define _NTC__

#include "Arduino.h"

class NTC {
  private:
    double r25;  //ntc25度阻值
    double b;    //B值
    double r;    //分压电阻阻值
    double v = 3.3;  //ntc电源电压
  public:
    NTC( double r25, double b, double r); //25度阻值，B值，分压电阻阻值
    ~NTC();
    double getTemper(double adc);
    void setV(double v);
};
#endif
