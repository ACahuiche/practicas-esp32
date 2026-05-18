#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define DHTPIN 4
#define DHTTYPE DHT11
#define ANCHO 128
#define ALTO  64
#define RESET -1
#define DIRECCION 0x3C

String estado = "";
String errorDisplay = "Error leyendo el DHT22";
unsigned long ultimaLectura = 0;
const unsigned long intervalo = 2000;

DHT dht(DHTPIN, DHTTYPE);
Adafruit_SSD1306 pantalla(ANCHO, ALTO, &Wire, RESET);

void setup() {
  Serial.begin(115200);

  dht.begin();

  if(!pantalla.begin(SSD1306_SWITCHCAPVCC, DIRECCION)){
    Serial.println("Error iniciando OLED");
    while(true);
  }

  pantalla.clearDisplay();


  pantalla.setTextSize(1);
  pantalla.setTextColor(SSD1306_WHITE);
  pantalla.setCursor(0,0);
  pantalla.println("Cargando..");
  pantalla.setCursor(0,10);
  pantalla.println("CahuiTemp");
  pantalla.setCursor(0,20);
  pantalla.println("Termometro Ambiental");

  pantalla.display();
}

void loop() {

  if(millis() - ultimaLectura >= intervalo){
    ultimaLectura = millis();
    pantalla.clearDisplay();

    float temperatura = dht.readTemperature();
    float humedad     = dht.readHumidity();

    if(isnan(temperatura) || isnan(humedad)){
      pantalla.setCursor(0,0);
      pantalla.println(errorDisplay);
      Serial.println(errorDisplay);
      return;
    }

    if(temperatura >= 30.00){
      estado = "Calor";
    }
    else if(temperatura <= 10.00){
      estado = "Frio";
    }
    else {
      estado = "Normal";
    }

    pantalla.setCursor(0,0);
    pantalla.print("Temp: ");
    pantalla.print(temperatura);
    pantalla.println(" C");
    pantalla.setCursor(0,10);
    pantalla.print("Hum: ");
    pantalla.print(humedad);
    pantalla.println(" %");
    pantalla.setCursor(0,20);
    pantalla.print("Estado: ");
    pantalla.println(estado);

    pantalla.display();

  }

}