#include "LED.h"
LED led(2);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  led.mode(2);
}
