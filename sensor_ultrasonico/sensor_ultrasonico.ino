#define TRIG 5
#define ECHO 18
#define LED_VERDE    25
#define LED_AMARILLO 26
#define LED_ROJO     27

long duracion;
float distancia;

void setup() {
  Serial.begin(115200);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LED_VERDE,    OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_ROJO,     OUTPUT);
}

long medirDistancia(){
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duracion = pulseIn(ECHO, HIGH);

  return duracion * 0.034 / 2;
}

void loop() {
  distancia = medirDistancia();

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  if(distancia > 30){
    digitalWrite(LED_VERDE,    HIGH);
    digitalWrite(LED_AMARILLO, LOW);
    digitalWrite(LED_ROJO,     LOW);
  }
  else if(distancia > 10 && distancia <= 30){
    digitalWrite(LED_VERDE,    LOW);
    digitalWrite(LED_AMARILLO, HIGH);
    digitalWrite(LED_ROJO,     LOW);
  }
  else {
    digitalWrite(LED_VERDE,    LOW);
    digitalWrite(LED_AMARILLO, LOW);
    digitalWrite(LED_ROJO,     HIGH);
  }

  delay(200);
}