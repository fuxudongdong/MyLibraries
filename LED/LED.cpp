#include "LED.h"
#include "Arduino.h"

LED::LED(int p) : pin(p)
{
    pinMode(pin, OUTPUT);
    analogWriteRange(range); //占空比
    analogWriteFreq(1000);   //频率
}

LED::~LED()
{
}

void LED::pilotLED()
{
    // Serial.println(mode);
    switch (mode)
    {
    case 0:
        digitalWrite(pin, 1); //关
        break;
    case 1:
        digitalWrite(pin, 0); //开
        break;
    case 2:
        digitalWrite(pin, !digitalRead(pin)); //切换
        break;
    case 3:
        setMStep(3); // 3秒循环
        setRangeStep(1);
        pwmTherad();
        break;
    case 4:
        setMStep(1); // 0.5秒循环
        setRangeStep(2);
        pwmTherad();
        break;
    case 5:
        setMStep(50); // 50ms切换一次
        twinkleTherad();
        break;
    case 6:
        setMStep(1000); // 1秒切换一次
        twinkleTherad();
        break;
    default:
        break;
    }
}
void LED::pwmTherad()
{
    if (millis() - ms >= mstep)
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

void LED::twinkleTherad()
{
    if (millis() - ms >= mstep)
    {
        digitalWrite(pin, !digitalRead(pin));
        ms = millis();
    }
}

void LED::setMode(int i)
{
    mode = i;
}

void LED::setRange(int myRange)
{
    range = myRange;
    analogWriteRange(range); //占空比
}

void LED::setMStep(int _mstep)
{
    mstep = _mstep;
}

void LED::setRangeStep(int _rangeStep)
{
    rangeStep = _rangeStep;
}
