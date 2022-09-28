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

Ritos ledTarefa;
LED *led0;

void ledTh()
{
    led0->ledTherad();
}

void LED::ledTherad()
{
    if (millis() - ms >= msStep)
    {
        if (_range <= 0)
        {
            _range = range * 2;
        }
        else if (_range > range)
        {
            analogWrite(pin, _range - range);
        }
        else
        {
            analogWrite(pin, range - _range);
        }
        _range = _range - rangeStep;
        ms = millis();
    }
}

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
        msStep = 1;
        rangeStep = 1;
        ledTarefa.task(ledTh);
        delay(50000);
        ledTarefa.detach();
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
}

void LED::setRange(int myRange)
{
    range = myRange;
}
