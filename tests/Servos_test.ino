#include <Servo.h>
#include <math.h>

Servo pan;
Servo tilt;

int centroPAN = 90;
int centroTILT = 90;

int radio = 20;  // cuánto se aleja del centro

void setup() {
  pan.attach(9);
  tilt.attach(10);
}

void loop() {

  for (float angulo = 0; angulo < 2 * PI; angulo += 0.05) {

    int posPAN = centroPAN + radio * cos(angulo);
    int posTILT = centroTILT + radio * sin(angulo);

    pan.write(posPAN);
    tilt.write(posTILT);

    delay(20);  // velocidad
  }
}
