#include "LED.h"
#include <ritos.h>
LED led(2);
LED led0(0);
Ritos tarefa1;
void therad()
{
    led0.mode(2);
}
void setup()
{
    // put your setup code here, to run once:
    Serial.begin(115200);
    tarefa1.task(therad);
}

void loop()
{
    led.mode(2);
}
