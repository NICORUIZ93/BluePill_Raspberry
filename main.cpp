#include "HCSR04.h"
#include "mbed.h"

Serial pc(PA_9, PA_10);
DigitalOut led(PC_13);
AnalogIn potenciometro(PB_1);
HCSR04 sensor(PB_11, PB_10);
float range;
// main() runs in its own thread in the OS
int main() {
  while (true) {
    pc.printf("%3.3f,%3.3f\n", sensor.getCm(), (potenciometro.read() * 3.3));
    led = !led;
    ThisThread::sleep_for(200);
  }
}
