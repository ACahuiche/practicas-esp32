# Sensor PIR SR501: Detector de Movimiento

## Descripción
Detector de movimiento con sensor PIR SR501. Incluye LED 
indicador de carga durante la calibración del sensor y 
contador de movimientos detectados.

## Componentes
- 1 x Sensor PIR SR501
- 2 x LEDs (movimiento y carga)
- 2 x Resistencias 100Ω

## Pines
| Componente     | GPIO |
|----------------|------|
| PIR OUT        | 27   |
| LED Movimiento | 26   |
| LED Cargando   | 4    |

## Lógica
| Estado                | LED Cargando | LED Movimiento |
|-----------------------|--------------|----------------|
| Calibrando (30s)      | Encendido 🔴 | Apagado ⚫     |
| Listo, sin movimiento | Apagado ⚫   | Apagado ⚫     |
| Movimiento detectado  | Apagado ⚫   | Encendido 🟢   |

## Conceptos
- Sensor PIR pasivo infrarrojo
- Tiempo de calibración del sensor (30s)
- Detección de cambio de estado
- Contador de eventos con ++
- Validación de voltaje de salida con multímetro

## Validación de hardware
Señal OUT del PIR medida con multímetro antes de conectar
al ESP32: 3.3V ✅ No requiere divisor de voltaje.

## Notas
Probado en ESP32 WROOM 32 físico ✅