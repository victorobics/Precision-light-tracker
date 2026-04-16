#include <Servo.h>

Servo pan;
Servo tilt;

void setup() {
  pan.attach(9);
  tilt.attach(10);

  pan.write(90);
  tilt.write(90);
}

void loop() {
}
