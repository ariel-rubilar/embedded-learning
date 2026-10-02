# 00 — Lesson Template

Copy this folder to create a new lesson. It is a working, buildable project, so you
can verify your setup before changing anything.

## Steps to create a new lesson

1. Copy the folder: `cp -r lessons/00-template lessons/03-my-topic`
2. Rename `00-template` references and update the lesson `README.md`.
3. Write your code in `src/main.cpp`.
4. Describe the circuit in `diagram.json` (see `F1 → Wokwi: Diagram Editor` to
   build it visually instead of by hand).
5. Nothing else changes — `platformio.ini` and `wokwi.toml` are already correct for
   the ESP32.

## What each file does

| File | Purpose |
| --- | --- |
| `src/main.cpp` | `setup()` runs once at boot, `loop()` runs forever |
| `include/` | Headers for this lesson only (`.hpp` files) |
| `platformio.ini` | Build configuration: board, framework, flags |
| `diagram.json` | Wokwi circuit description |
| `wokwi.toml` | Points Wokwi at the compiled firmware |
| `README.md` | The lesson itself: goal, wiring, what to observe |

## Circuit

| From | To | Part |
| --- | --- | --- |
| `GPIO2` | `led1:A` | LED anode (long leg) |
| `led1:C` | `r1:1` | 220 Ω resistor |
| `r1:2` | `GND` | Ground |

## How to run

```bash
pio run
```

Then in VS Code press `F1 → Wokwi: Start Simulator`. The LED blinks every 500 ms.

## Naming

Use `NN-kebab-case-topic` with a two-digit prefix so lessons sort in the order you
should learn them: `01-blink`, `02-button-input`, `03-pwm-analog-output`.