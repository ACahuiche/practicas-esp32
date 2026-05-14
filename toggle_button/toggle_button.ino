#include <Bounce2.h>

#define LED 4
#define BOTON_FISICO 15

Bounce2::Button botonDigital = Bounce2::Button();

bool estaEncendido = false;

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  botonDigital.attach(BOTON_FISICO, INPUT_PULLUP);
  botonDigital.interval(10);
  botonDigital.setPressedState(LOW); 
}

void loop() {
  botonDigital.update();

  if(botonDigital.pressed()){ 
    estaEncendido = !estaEncendido;
  }

  digitalWrite(LED, estaEncendido);
  estaEncendido ? Serial.println("Variable encendida") : Serial.println("Variable apagada"); 
}
