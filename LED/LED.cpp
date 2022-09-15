#include "LED.h"
#include "Arduino.h"

LED::LED(int p): pin(p) {
  pinMode(pin, OUTPUT);
  analogWriteRange(range);//占空比
  analogWriteFreq(1000);//频率
}

LED::~LED() {

}

void LED::mode(int i) {
  switch (i) {
    case 0:
      digitalWrite(pin, 1);
      break;
    case 1:
      digitalWrite(pin, 0);
      break;
    case 2:
      for (int i = 1000; i > 0; i--) {
        analogWrite(pin, i);
        delay(1);
      }
      delay(100);
      for (int i = 0; i < 1000; i++) {
        analogWrite(pin, i);
        delay(1);
      }
      break;
    case 3:
      digitalWrite(pin, !digitalRead(pin));
      delay(500);
      break;
    case 4:
      for (int i = 750; i < 1000; i++) {
        analogWrite(pin, i);
        delay(1);
      }
      for (int i = 1000; i > 750; i--) {
        analogWrite(pin, i);
        delay(1);
      }
      break;
    case 5:
      digitalWrite(pin, !digitalRead(pin));
      break;
  }
}

void LED::setRange(int myRange) {
  range = myRange;
}
