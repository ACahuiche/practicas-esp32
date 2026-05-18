# Sensor de Vibración SW-420

## Descripción
Detección de vibraciones y golpes con el sensor SW-420.
Registra cada evento con timestamp desde el inicio del
programa y contador acumulado de vibraciones.

## Componentes
- 1 x Sensor de vibración SW-420
- 1 x LED
- 1 x Resistencia 100Ω

## Pines
| Componente  | GPIO |
|-------------|------|
| SW-420 DO   | 27   |
| LED         | 26   |

## Lógica
| Estado          | LED      | Serial                              |
|-----------------|----------|-------------------------------------|
| Sin vibración   | Apagado ⚫ | —                                  |
| Vibración detect| Encendido 🔴 | Total + timestamp en segundos    |

## Conceptos
- Lógica invertida (LOW = vibración detectada)
- Detección de cambio de estado
- Timestamp con millis()
- Contador de eventos con ++

## Notas
Probado en ESP32 WROOM 32 físico ✅