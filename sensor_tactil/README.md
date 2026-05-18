# Sensor Táctil TTP223B

## Descripción
Control de brillo de un LED mediante sensor táctil capacitivo
TTP223B. Cada toque cicla entre 5 niveles de brillo usando PWM.
No requiere presión física, solo contacto o proximidad del dedo.

## Componentes
- 1 x Sensor táctil TTP223B
- 1 x LED
- 1 x Resistencia 100Ω

## Pines
| Componente  | GPIO |
|-------------|------|
| TTP223B SIG | 27   |
| LED         | 26   |

## Lógica
| Toque | Modo | Brillo |
|-------|------|--------|
| 1     | 1    | 25%    |
| 2     | 2    | 50%    |
| 3     | 3    | 75%    |
| 4     | 4    | 100%   |
| 5     | 0    | Apagado|

## Conceptos
- Sensor capacitivo vs botón mecánico
- Detección de cambio de estado
- Ciclo de modos con operador módulo (modo + 1) % 5
- PWM para control de brillo (0-255)
- Switch para manejo de múltiples estados

## Notas
Probado en ESP32 WROOM 32 físico ✅