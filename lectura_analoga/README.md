# Control de Brillo con Potenciómetro

## Descripción
Control de brillo de un LED usando un potenciómetro. 
Convierte los valores del ADC del ESP32 (0-4095) a valores 
PWM (0-255) usando la función map().

## Componentes
- 1 x LED
- 1 x Resistencia 100Ω
- 1 x Potenciómetro 10kΩ

## Pines
| Componente    | GPIO |
|---------------|------|
| LED           | 4    |
| Potenciómetro | 34   |

## Conceptos
- ADC (Analog to Digital Converter) 12 bits (0-4095)
- PWM 8 bits (0-255)
- Función map() para conversión de rangos

## Notas
Probado en ESP32 WROOM 32 físico ✅