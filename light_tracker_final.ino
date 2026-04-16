#include <Servo.h>

Servo pan;
Servo tilt;

// Pines sensores
const int pinAbajo = A0;
const int pinDerecha = A1;
const int pinIzquierda = A2;
const int pinArriba = A3;

// Pines servos
const int pinPan = 9;
const int pinTilt = 10;

// Centro mecánico
int centroPAN = 90;
int centroTILT = 90;

// Posiciones actuales
float posPAN = centroPAN;
float posTILT = centroTILT;

// Límites
int minPAN = 40;
int maxPAN = 140;

int minTILT = 75;   // baja menos
int maxTILT = 140;

// Filtro: equilibrio entre rapidez y estabilidad
float alpha = 0.32;

// Variables filtradas
float fIzq = 0;
float fDer = 0;
float fArr = 0;
float fAba = 0;

// Señal mínima total
int minTotal = 35;

// Zona muerta: pequeña pero útil
float deadX = 0.10;
float deadY = 0.10;

// Ganancias
float kPan = 20.0;
float kTiltUp = 18.0;
float kTiltDown = 8.0;

// Velocidad máxima por ciclo
float maxStepPAN = 4.0;
float maxStepTILTup = 3.5;
float maxStepTILTdown = 1.2;

int leerSensor(int pin) {
  int s = 0;
  s += analogRead(pin);
  s += analogRead(pin);
  s += analogRead(pin);
  return s / 3;
}

float limitar(float valor, float maxPaso) {
  if (valor > maxPaso) return maxPaso;
  if (valor < -maxPaso) return -maxPaso;
  return valor;
}

void setup() {
  pan.attach(pinPan);
  tilt.attach(pinTilt);

  pan.write(centroPAN);
  tilt.write(centroTILT);

  delay(1200);
}

void loop() {
  int abajoRaw = leerSensor(pinAbajo);
  int derechaRaw = leerSensor(pinDerecha);
  int izquierdaRaw = leerSensor(pinIzquierda);
  int arribaRaw = leerSensor(pinArriba);

  // Filtrado
  fAba = alpha * abajoRaw + (1.0 - alpha) * fAba;
  fDer = alpha * derechaRaw + (1.0 - alpha) * fDer;
  fIzq = alpha * izquierdaRaw + (1.0 - alpha) * fIzq;
  fArr = alpha * arribaRaw + (1.0 - alpha) * fArr;

  float total = fAba + fDer + fIzq + fArr;

  if (total > minTotal) {
    // Errores normalizados
    float errorX = (fDer - fIzq) / total;
    float errorY = (fArr - fAba) / total;

    // PAN
    if (abs(errorX) > deadX) {
      float pasoPAN = errorX * kPan;
      pasoPAN = limitar(pasoPAN, maxStepPAN);
      posPAN += pasoPAN;
    }

    // TILT
    if (errorY > deadY) {
      float pasoTILT = errorY * kTiltUp;
      pasoTILT = limitar(pasoTILT, maxStepTILTup);
      posTILT += pasoTILT;
    }
    else if (errorY < -deadY) {
      float pasoTILT = errorY * kTiltDown;
      pasoTILT = limitar(pasoTILT, maxStepTILTdown);
      posTILT += pasoTILT;
    }
  }

  // Límites
  if (posPAN < minPAN) posPAN = minPAN;
  if (posPAN > maxPAN) posPAN = maxPAN;

  if (posTILT < minTILT) posTILT = minTILT;
  if (posTILT > maxTILT) posTILT = maxTILT;

  pan.write((int)posPAN);
  tilt.write((int)posTILT);

  delay(10);
}
