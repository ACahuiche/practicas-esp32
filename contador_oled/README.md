# Pantalla OLED SSD1306

## Descripción
Uso de pantalla OLED SSD1306 de 128x64 píxeles mediante
protocolo I2C. Muestra un mensaje de bienvenida y un 
contador del 0 al 100.

## Componentes
- 1 x Pantalla OLED SSD1306 128x64

## Pines
| Componente  | GPIO |
|-------------|------|
| OLED SDA    | 21   |
| OLED SCL    | 22   |

## Conceptos
- Protocolo I2C (SDA/SCL)
- Dirección I2C del dispositivo (0x3C)
- Flujo de la pantalla: clearDisplay() → dibujar → display()
- setTextSize() para tamaño de texto
- setCursor() para posicionamiento
- Parámetro &Wire para referencia al bus I2C
- RESET = -1 cuando no hay pin de reset físico

## Librerías
- Adafruit SSD1306
- Adafruit GFX Library
- Wire (incluida en ESP32)

## Notas
Probado en ESP32 WROOM 32 físico ✅