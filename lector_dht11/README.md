# Sensor DHT11 con LEDs de Temperatura

## Descripción
Lectura de temperatura con el sensor DHT11 y visualización
del estado mediante 3 LEDs indicadores de frío, normal y calor.

## Componentes
- 1 x Sensor DHT11
- 3 x LEDs (frío, normal, calor)
- 3 x Resistencia 100Ω

## Pines
| Componente   | GPIO |
|--------------|------|
| DHT11        | 4    |
| LED Frío     | 17   |
| LED Normal   | 5    |
| LED Calor    | 16   |

## Lógica
| Temperatura      | LED activo |
|------------------|------------|
| <= 10°C          | Frío 🔵    |
| > 10°C y < 30°C  | Normal 🟢  |
| >= 30°C          | Calor 🔴   |

## Conceptos
- Lectura de sensor digital DHT11
- Lógica condicional con if/else if
- millis() para lecturas no bloqueantes

## Librerías
- DHT sensor library by Adafruit
- Adafruit Unified Sensor

## Notas
Probado en ESP32 WROOM 32 físico ✅
Temperatura ambiente durante prueba: ~30°C