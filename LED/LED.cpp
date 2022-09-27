#include "LED.h"
#include "Arduino.h"
#include <ritos.h>

LED::LED(int p) : pin(p)
{
    pinMode(pin, OUTPUT);
    analogWriteRange(range); //占空比
    analogWriteFreq(1000);   //频率
}

LED::~LED()
{
}

int ms = millis();
int ledTime = 0;
void LED::mode(int i)
{
    switch (i)
    {
    case 0:
        digitalWrite(pin, 1);
        break;
    case 1:
        digitalWrite(pin, 0);
        break;
    case 2:
        if (ledTime < 1000)
        {
            if (millis() - ms >= 1)
            {
                analogWrite(pin, 1000 - i);
                ms = millis();
            }
        }
        else if (ledTime >= 1000)
        {
            if (millis() - ms >= 1)
            {
                analogWrite(pin, i - 1000);
                ms = millis();
            }
        }
        else if (ledTime == 2000)
        {
            ledTime = 0;
        }
        break;
    case 3:
        digitalWrite(pin, !digitalRead(pin));
        ms = millis();
        while (millis() - ms < 500)
        {
            /* code */
        }
        break;
    case 4:
        for (int i = 750; i < 1000; i++)
        {
            analogWrite(pin, i);
            ms = millis();
            while (millis() - ms < 1)
            {
                /* code */
            }
        }
        for (int i = 1000; i > 750; i--)
        {
            analogWrite(pin, i);
            ms = millis();
            while (millis() - ms < 1)
            {
                /* code */
            }
        }
        break;
    case 5:
        digitalWrite(pin, !digitalRead(pin));
        break;
    }
    ledTime++;
}

void LED::setRange(int myRange)
{
    range = myRange;
}
