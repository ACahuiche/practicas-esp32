# OLED + DHT11: Termómetro Ambiental

## Descripción
Termómetro ambiental que muestra temperatura, humedad y 
estado en pantalla OLED SSD1306. Incluye pantalla de 
bienvenida y lecturas no bloqueantes con millis().

## Componentes
- 1 x Sensor DHT11
- 1 x Pantalla OLED SSD1306 128x64

## Pines
| Componente  | GPIO |
|-------------|------|
| DHT11       | 4    |
| OLED SDA    | 21   |
| OLED SCL    | 22   |

## Lógica
| Temperatura      | Estado  |
|------------------|---------|
| <= 10°C          | Frío    |
| > 10°C y < 30°C  | Normal  |
| >= 30°C          | Calor   |

## Conceptos
- Combinación de DHT11 y OLED en mismo circuito
- millis() para lecturas no bloqueantes
- Pantalla de bienvenida en setup()
- Manejo de errores del sensor en pantalla

## Librerías
- DHT sensor library by Adafruit
- Adafruit Unified Sensor
- Adafruit SSD1306
- Adafruit GFX Library
- Wire (incluida en ESP32)

## Notas
Probado en ESP32 WROOM 32 físico ✅