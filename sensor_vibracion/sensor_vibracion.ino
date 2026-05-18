#define SENSOR 27
#define LED 26

bool estadoAnterior = HIGH;
int contadorVibraciones = 0;
unsigned long tiempoInicio = 0;

void setup() {
  Serial.begin(115200);
  pinMode(SENSOR, INPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  tiempoInicio = millis();
  Serial.println("Sistema listo, esperando vibraciones...");
}

void loop() {
  bool estadoActual = digitalRead(SENSOR);

  if(estadoActual != estadoAnterior){
    if(estadoActual == LOW){
      contadorVibraciones++;
      digitalWrite(LED, HIGH);

      unsigned long segundos = (millis() - tiempoInicio) / 1000;

      Serial.print("Vibración detectada! Total: ");
      Serial.print(contadorVibraciones);
      Serial.print(" | Tiempo: ");
      Serial.print(segundos);
      Serial.println("s");

    } 
    else {
      digitalWrite(LED, LOW);
    }
    estadoAnterior = estadoActual;
  }
}