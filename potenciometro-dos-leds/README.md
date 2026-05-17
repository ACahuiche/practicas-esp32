# Práctica 3 — Control de Brillo con Potenciómetro y Dos LEDs

## Descripción
Control de brillo de dos LEDs usando un potenciómetro.
La mitad inferior del rango del potenciómetro controla el LED1
y la mitad superior controla el LED2.
Usa map() para conversión de rangos y constrain() para 
proteger contra valores negativos.

## Componentes
- 2 x LEDs
- 2 x Resistencia 100Ω
- 1 x Potenciómetro 10kΩ

## Pines
| Componente      | GPIO |
|-----------------|------|
| LED 1           | 4    |
| LED 2           | 5    |
| Potenciómetro   | 34   |

## Conceptos
- ADC 12 bits (0-4095)
- PWM 8 bits (0-255)
- map() para conversión de rangos
- constrain() para limitar valores negativos
- Variables para evitar números mágicos

## Notas
Probado en ESP32 WROOM 32 físico ✅
Probado en Arduino Uno físico ✅