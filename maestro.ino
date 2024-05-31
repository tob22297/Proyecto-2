//MAESTRO
#include <LiquidCrystal_I2C.h>

//Codigo para LCD donde se menciona dirección y tamaño
LiquidCrystal_I2C lcd (0x27, 16, 2);

//definición de estados de LCD
typedef enum estados {e0, e1, e2} estados;
estados estadoActual = e0;
estados estadoFuturo = e0;

//pines de switch
const uint8_t boton1 = 12;
const uint8_t boton2 = 13;

//Renato

void setup() {
  //Lcd se prende
  lcd.init();
  lcd.backlight();

  Serial.begin(9600);
  
  //entradas
  pinMode(boton1, INPUT_PULLUP);
  pinMode(boton2, INPUT_PULLUP);
}

//Renato

//salidas en cada estado
  switch(estadoActual){
    case e0:
      lcd.setCursor(0,0);
      lcd.clear();
      break;
    case e1:
      lcd.setCursor(0,0);
      lcd.print(aviso1);
      break;
    case e2:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(aviso2);
      break;
  }

//Renato

//Mapear potenciómetros
  int ang1 = map(poten1, 0, 1023, 0, 179);
  int ang2 = map(poten2, 0, 1023, 0, 179);

//Renato

   // actualización de estado
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    estadoActual = estadoFuturo;
    previousMillis = currentMillis;
  }

  delay(100);
}