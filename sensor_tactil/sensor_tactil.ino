#define TACTIL 27
#define LED 26

bool estadoAnterior = LOW;
int modo = 0;
int brillo = 0;

void setup() {
  Serial.begin(115200);
  pinMode(TACTIL, INPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  Serial.println("Sistema listo, toca el sensor...");
}

void loop() {
  bool estadoActual = digitalRead(TACTIL);

  if(estadoActual != estadoAnterior){
    if(estadoActual == HIGH){
      modo = (modo + 1) % 5;

      switch(modo){
        case 0:
          analogWrite(LED, 0);
          Serial.println("Modo 0: Apagado");
          break;

        case 1:
          analogWrite(LED, 64);
          Serial.println("Modo 1: 25%");
          break;

        case 2:
          analogWrite(LED, 127);
          Serial.println("Modo 2: 50%");
          break;
        
        case 3:
          analogWrite(LED, 191);
          Serial.println("Modo 3: 75%");
          break;
        
        case 4:
          analogWrite(LED, 255);
          Serial.println("Modo 4: 100%");
          break;
      }
    }

    estadoAnterior = estadoActual;
  }

  
}