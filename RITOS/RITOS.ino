#include "ritos.h" //RITOS: Real Internet Time Operation Sansystem

unsigned long a = 0;
unsigned long b = 0;
Ritos tarefa1;
void thread1() {
  a++;
  if (a <= 30000) {
    return 0;
  }
  Serial.println("线程一");
}


Ritos tarefa2;
void thread2() {
  b++;
  if ( b <= 10000) {
    return 0;
  }
  Serial.println("线程二");
}

void setup() {
  Serial.begin(115200);

  // Criar threads concorrentes
  tarefa1.task(thread1);
  tarefa2.task(thread2);

}

void loop() {}
