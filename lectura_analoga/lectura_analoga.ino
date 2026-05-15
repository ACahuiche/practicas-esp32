#define POT 34
#define LED 4

void setup() {
  Serial.begin(115200);
  Serial.println("Practica de control analogo");
  pinMode(LED, OUTPUT);
}

void loop() {
  int valorPot = analogRead(POT);
  int brillo = map(valorPot, 0, 4095, 0, 255);

  analogWrite(LED, brillo);

  Serial.print("Potenciómetro: ");
  Serial.print(valorPot);
  Serial.print(" → Brillo: ");
  Serial.println(brillo);

  delay(10);
}
