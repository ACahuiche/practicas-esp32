#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define ANCHO 128
#define ALTO  64
#define RESET -1
#define DIRECCION 0x3C

Adafruit_SSD1306 pantalla(ANCHO, ALTO, &Wire, RESET);

void setup() {
  Serial.begin(115200);

  if(!pantalla.begin(SSD1306_SWITCHCAPVCC, DIRECCION)){
    Serial.println("Error iniciando OLED");
    while(true); 
  }

  pantalla.clearDisplay();

  pantalla.setTextSize(2);
  pantalla.setTextColor(SSD1306_WHITE);
  pantalla.setCursor(10, 20);
  pantalla.println("Hola!");

  pantalla.display(); 
  delay(2000);
}

void loop() {

  for(int i = 0; i <= 100; i++){
    pantalla.clearDisplay();

    pantalla.setTextSize(1);
    pantalla.setTextColor(SSD1306_WHITE);
    pantalla.setCursor(0, 0);
    pantalla.println("Contador:");

    pantalla.setTextSize(3);
    pantalla.setCursor(30, 20);
    pantalla.println(i);

    pantalla.display();
    delay(100);
  }
}