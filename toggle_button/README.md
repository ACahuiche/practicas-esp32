# Toggle Button con Bounce2

## Descripción
Control de LED con botón tipo toggle usando la librería Bounce2 
para manejo de debounce.

## Componentes
- ESP32 WROOM 32
- 1 x LED
- 1 x Resistencia 100Ω
- 1 x Push button

## Pines
| Componente | Pin ESP32 |
|------------|-----------|
| LED        | GPIO 4    |
| Botón      | GPIO 15   |

## Funcionamiento
- Primera presión → LED enciende
- Segunda presión → LED apaga

## Librerías
- Bounce2 by Thomas Fredericks