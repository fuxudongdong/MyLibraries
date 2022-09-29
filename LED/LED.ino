#include "LED.h"
#include <ritos.h>

LED led(2);
Ritos ledTarefa;
void setup()
{
    // put your setup code here, to run once:
    Serial.begin(115200);
    ledTarefa.task(pilotLED);
}

void pilotLED()
{
    led.pilotLED();
}
int ms = millis();
void loop()
{
    // led.setMode(1);
    // delay(10000);
    // delay(10000);
    Serial.println("3");
    led.setMode(3);
    delay(20000);
    Serial.println("4");
    led.setMode(4);
    delay(20000);
    //     led.setMode(5);
    //     delay(10000);
    //     led.setMode(6);
    //     delay(10000);
}
