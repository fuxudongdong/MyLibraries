#include "LED.h"

LED led(2);
void setup()
{
    // put your setup code here, to run once:
    Serial.begin(115200);
    led.mode(2);
}

void loop()
{
}
