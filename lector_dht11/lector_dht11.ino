#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11
#define LEDCALOR 16
#define LEDFRIO 17
#define LEDNORMAL 5

DHT dht(DHTPIN, DHTTYPE);


void setup() {
  Serial.begin(115200);
  Serial.println("Practica con DHT11 y DHT22");
  dht.begin();
  pinMode(LEDCALOR, OUTPUT);
  pinMode(LEDFRIO, OUTPUT);
  pinMode(LEDNORMAL, OUTPUT);
}

void loop() {
  delay(2000);

  float temperatura = dht.readTemperature();
  float humedad     = dht.readHumidity();

  if(isnan(temperatura) || isnan(humedad)){
    Serial.println("Error leyendo el DHT11");
    return;
  }

  if(temperatura >= 30.00){
  digitalWrite(LEDCALOR, HIGH);
  digitalWrite(LEDNORMAL, LOW);
  digitalWrite(LEDFRIO,   LOW);
}
else if(temperatura <= 10.00){
  digitalWrite(LEDFRIO,   HIGH);
  digitalWrite(LEDNORMAL, LOW);
  digitalWrite(LEDCALOR,  LOW);
}
else {
  digitalWrite(LEDNORMAL, HIGH);
  digitalWrite(LEDCALOR,  LOW);
  digitalWrite(LEDFRIO,   LOW);
}

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");

  Serial.print("Humedad: ");
  Serial.print(humedad);
  Serial.println(" %");

  Serial.println("─────────────────");
}
