# Arduino LCD Calculator
A simple 4-function calculator built using an Arduino Uno, 16x2 LCD, and a 4x4 Keypad.

## Features
- Addition, Subtraction, Multiplication, and Division.
- Clear function using the `*` key.
- Results displayed on a 16x2 I2C/Standard LCD.

## Required Libraries
To run this code, you must install the following libraries in your Arduino IDE:
1. **Keypad** by Mark Stanley, Alexander Brevig
2. **LiquidCrystal** (Built-in)

## Wiring
- LCD RS -> Pin 8
- LCD EN -> Pin 9
- LCD D4-D7 -> Pins 10, 11, 12, 13
- Keypad Rows -> Pins 0, 1, 2, 3
- Keypad Cols -> Pins 4, 5, 6, 7
