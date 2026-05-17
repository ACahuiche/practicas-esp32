# Sensor Ultrasónico HC-SR04

## Descripción
Medición de distancias con el sensor HC-SR04 y control de
3 LEDs indicadores según la proximidad, simulando un 
sensor de reversa de auto.

## Componentes
- 1 x Sensor HC-SR04
- 3 x LEDs (verde, amarillo, rojo)
- 3 x Resistencias 100Ω
- 2 x Resistencias para divisor de voltaje (1kΩ y 2kΩ)

## Pines
| Componente    | GPIO |
|---------------|------|
| HC-SR04 TRIG  | 5    |
| HC-SR04 ECHO  | 18   |
| LED Verde     | 25   |
| LED Amarillo  | 26   |
| LED Rojo      | 27   |

## Lógica
| Distancia        | LED activo    |
|------------------|---------------|
| Mayor a 30cm     | Verde ✅      |
| Entre 10 y 30cm  | Amarillo ⚠️   |
| Menor a 10cm     | Rojo 🚨       |

## Conceptos
- Señal TRIG para enviar pulso ultrasónico
- Señal ECHO para recibir el rebote
- pulseIn() para medir tiempo del pulso
- Cálculo de distancia con velocidad del sonido
- Divisor de voltaje en pin ECHO (5V → 3.3V)

## Protección ESP32
El pin ECHO del HC-SR04 alimentado con 5V devuelve 5V.
Se usa un divisor de voltaje para proteger el GPIO del ESP32:
- R1 = 1kΩ (entre ECHO y GPIO)
- R2 = 2kΩ (entre GPIO y GND)
- Voltaje resultante = 5V × 2kΩ / (1kΩ + 2kΩ) = 3.3V ✅

## Notas
Probado en ESP32 WROOM 32 físico ✅