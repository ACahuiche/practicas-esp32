#define POT 34
#define LED1 4
#define LED2 5

int brilloLed1 = 0;
int brilloLed2 = 0;
int valorPot = 0;
int valorPotLed2 = 0;
int valorMinADC = 0;
int valorMedioADC = 2047;
int ValorMaxADC = 4095;

void setup()
{
  Serial.begin(115200);
  Serial.println("Practica de control analogo");
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop()
{
  valorPot = analogRead(POT);

  if(valorPot <= valorMedioADC ) {
    brilloLed1 = map(valorPot, 0, valorMedioADC,0,255);
    analogWrite(LED1,brilloLed1);
    analogWrite(LED2, 0);
  }
  else {

    brilloLed1 = 255;
    analogWrite(LED1, brilloLed1);

    valorPotLed2 = valorPot - valorMedioADC;
    brilloLed2 = map(valorPotLed2, 0, (ValorMaxADC - valorMedioADC), 0, 255);
    brilloLed2 = constrain(brilloLed2, 0, 255);
    analogWrite(LED2,brilloLed2);
    
  }

  Serial.print("Potenciómetro: ");
  Serial.println(valorPot);
  Serial.print("Brillo LED 1: ");
  Serial.println(brilloLed1);
  Serial.print("Brillo LED 2: ");
  Serial.println(brilloLed2);

  delay(10);
}