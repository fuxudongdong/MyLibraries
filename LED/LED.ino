#include "LED.h"
#include <ritos.h>

LED led(2);
Ritos ledTarefa;
void setup()
{
    // put your setup code here, to run once:
    Serial.begin(115200);
    ledmode(2);
}
void ledmode(int i)
{
    ledTarefa.detach();
    led.msStep = 5;
    ledTarefa.task(ledTherad);
}
void ledTherad()
{
    led.ledTherad();
}
void loop()
{
}
