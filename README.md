# AVR Stepper Motor Control with Keypad & LCD

A simple Embedded C project for controlling a stepper motor using an AVR microcontroller.

The motor speed is controlled using a 4×4 keypad, and a 16×2 LCD displays the entered value.

The firmware was developed using **Atmel Studio**.

## How It Works

```text
[4×4 Keypad]
      │
      ▼
[AVR Microcontroller]
      │
      ├──────> [16×2 LCD]
      │
      ▼
[Stepper Motor]
```

1. The user enters a value using the keypad.
2. The AVR reads the input.
3. The entered value controls the stepper motor speed.
4. The LCD displays the entered value.

## Hardware

| Component           | Description                |
| ------------------- | -------------------------- |
| AVR Microcontroller | Main controller            |
| 4×4 Keypad          | User input                 |
| 16×2 LCD            | Displays the entered value |
| Stepper Motor       | Motor being controlled     |
