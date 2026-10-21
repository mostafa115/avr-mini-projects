# AVR Mini Projects (ATmega128)

[![CI](https://github.com/mostafa115/avr-mini-projects/actions/workflows/ci.yml/badge.svg)](https://github.com/mostafa115/avr-mini-projects/actions/workflows/ci.yml)

Four small bare-metal C applications for an ATmega128 board with a 16x2 character LCD and a 4x4 keypad. Each one is built on register-level drivers (DIO, PORT, LCD, keypad, external interrupts, DC and stepper motors) written from scratch, with no Arduino or vendor libraries.

These were written in October and November 2023. The drivers grew into the layered set used in [Smart_Home_Project](https://github.com/mostafa115/Smart_Home_Project).

| Application | What it does |
|---|---|
| `calculator/` | Keypad calculator with multi-digit operands, `+ - * /` and negative results on the LCD |
| `countdown-timer/` | Enter hours, minutes and seconds on the keypad; the LCD counts down to zero and then shows an alert until a key is pressed |
| `ping-pong/` | Two-player game drawn on the LCD; each player hits the ball with a button on an external interrupt (INT0 and INT1), and the LCD announces the winner |
| `motor-dashboard/` | LCD menu that runs a DC motor clockwise, counter-clockwise or stop, or turns a stepper motor to an angle typed on the keypad |

Each folder is a complete project with its own copy of the drivers it needs, so it can be opened and flashed on its own.

## Build

The Docker image contains the AVR toolchain, so the build does not depend on the local machine.

```sh
docker build -t avr-mini-projects .
docker run --rm -v "$PWD:/src" avr-mini-projects make
```

This writes one `.hex` file per application to `build/` and prints the flash and RAM usage of each. With `avr-gcc`, `avr-libc` and `make` installed locally, `make` does the same. The CI workflow runs this build on every push and uploads the `.hex` files.

The default target is an ATmega128 at 16 MHz. Use `make MCU=... F_CPU=...` for another board.

## Credits

Source files keep their original author headers. The global-interrupt driver in `ping-pong/` (`GIE_*`) is by Omar Khaled.
