#include <Servo.h>

//declarando variables de servos
Servo servomotor1;
Servo servomotor2;

void setup() {
  Serial.begin(9600);

//Renato

void loop() {
  if (Serial.available() > 0) {
    // Leer datos del puerto serie
    int ang1Recibido = Serial.parseInt(); // Lee el primer número
    int ang2Recibido = Serial.parseInt(); // Lee el segundo número

//Renato

