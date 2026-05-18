#define PIR 27
#define LEDMOV 26
#define LEDCARGANDO 4

int contadorMovimientos = 0;
bool estadoAnterior = LOW;

void setup() {
  Serial.begin(115200);
  pinMode(PIR, INPUT);
  pinMode(LEDMOV, OUTPUT);
  pinMode(LEDCARGANDO, OUTPUT);
  digitalWrite(LEDMOV, LOW);
  digitalWrite(LEDCARGANDO, HIGH);

  Serial.println("Inicializando, cargando sensor...");
  delay(30000);
  digitalWrite(LEDCARGANDO, LOW);
  Serial.println("Sensor cargado correctamente, programa iniciado");
}

void loop() {
  int movimiento = digitalRead(PIR);

  if(movimiento != estadoAnterior){
    if(movimiento == HIGH){
      digitalWrite(LEDMOV, HIGH);
      contadorMovimientos++;
      Serial.println("Movimiento detectado! (Total: " + String(contadorMovimientos) + ")");
    } else {
      digitalWrite(LEDMOV, LOW);
      Serial.println("Sin movimiento");
    }
    estadoAnterior = movimiento;
  }

  delay(500);
}
