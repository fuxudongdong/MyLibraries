#include "NTC.h"
#include "Arduino.h"

NTC::NTC(double r250, double b0, double r0): r25(r250), b(b0), r(r0) {

}

NTC::~NTC() {

}

double NTC::getTemper(double adc) {
  double x, rNTC, e, temper;
  e = 2.718281828459;
  Serial.println("ADC：" + (String)adc);
  x = adc / (double)1024;
  rNTC = r * x / (v - x);
  Serial.println("NTC阻值：" + (String)rNTC) + "K";
  temper = 1 / (1 / 298.15 - (log(r25) - log(rNTC)) / log(e) / b) - 273.15;
  Serial.println("温度：" + (String)temper + "℃");
  return temper;
}

void NTC::setV(double v0) {
  v = v0;
}
