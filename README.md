#include <Wire.h>

const int potPin1 = A0; // Pin del primer potenciómetro
const int potPin2 = A1; // Pin del segundo potenciómetro

void setup() {
  Wire.begin(); // Iniciar I2C como maestro
}

void loop() {
  int potValue1 = analogRead(potPin1); // Leer el valor del primer potenciómetro
  int potValue2 = analogRead(potPin2); // Leer el valor del segundo potenciómetro

  Wire.beginTransmission(8); // Dirección del esclavo
  Wire.write(potValue1 / 4); // Enviar valor reducido a 8 bits
  Wire.write(potValue2 / 4); // Enviar valor reducido a 8 bits
  Wire.endTransmission();
  delay(100); // Pequeño retraso
}
