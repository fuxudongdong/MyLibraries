#include "ritos.h" //RITOS: Real Internet Time Operation Sansystem

unsigned long a = 0;
unsigned long b = 0;
Ritos tarefa1;
void thread1()
{
    a++;
    if (a <= 30000)
    {
        // return 0;
    }
    Serial.println("线程一");
}

int ms = millis();
int _range = 1000 * 2;
int rangeStep = 1;
int msStep = 1;
void ledTherad()
{
    if (millis() - ms >= msStep)
    {
        if (_range <= 0)
        {
            _range = 1000 * 2;
        }
        else if (_range > 1000)
        {
            analogWrite(2, _range - 1000);
        }
        else
        {
            analogWrite(2, 1000 - _range);
        }
        _range = _range - rangeStep;
        ms = millis();
    }
}

void setup()
{
    Serial.begin(115200);
    pinMode(2, OUTPUT);
    analogWriteRange(1000); //占空比
    analogWriteFreq(1000);  //频率
    // Criar threads concorrentes
    tarefa1.task(ledTherad);
    // tarefa2.task(thread2);
}

void loop()
{

    delay(5000);
}
