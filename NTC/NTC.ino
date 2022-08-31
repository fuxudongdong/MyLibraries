#include "NTC.h"
#include <LED.h>

NTC ntc(5, 3950, 30);
LED led(2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  led.mode(2);
  ntc.getTemper(101);
}
