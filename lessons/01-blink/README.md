# 01 — Blink

## Goal

Learn the two functions every embedded program has — `setup()` and `loop()` — and
turn a GPIO pin into an output.

## Concepts

**`setup()` and `loop()`**

The ESP32 firmware calls `setup()` exactly once when the chip resets, then calls
`loop()` over and over forever. There is no `return` from `loop()`; the program
never ends.

**Pin modes**

`pinMode(pin, OUTPUT)` configures a pin's hardware before you use it. On ESP32 a
pin must be declared as an output before `digitalWrite()` does anything
predictable. `pinMode(pin, INPUT)` and `pinMode(pin, INPUT_PULLUP)` are the input
equivalents — you will need them in lesson 02.

**Digital levels**

`HIGH` and `LOW` are the two logic levels. The ESP32's GPIO operates at 3.3 V, so
`HIGH` means ~3.3 V and `LOW` means ~0 V. Writing `HIGH` sources current through
the pin; the LED path must return to ground for the circuit to complete.

**`delay()` and why it is a problem here**

`delay(ms)` halts the CPU for a fixed number of milliseconds. It is the simplest
possible way to pace a blink, and it is also blocking: nothing else in the program
can run during those 500 ms. That is fine for a single blinking LED and wrong for
anything that must keep reading inputs. Lesson 02 replaces `delay()` with
`millis()` timing for exactly this reason.

**`constexpr` constants in an anonymous namespace**

`kLedPin` and `kBlinkIntervalMs` are compile-time constants scoped to this
translation unit. Using them instead of bare `2` and `500` means a rename is a
single edit, and the compiler can catch type mistakes.

## Circuit

| From | To | Part |
| --- | --- | --- |
| `GPIO2` | `led1:A` | LED anode (long leg) |
| `led1:C` | `r1:1` | 220 Ω resistor |
| `r1:2` | `GND` | Ground |

The resistor limits current through the LED. Removing it will let the pin drive far
too much current — on real hardware that damages the LED or the pin.

## How to run

1. Open `lessons/01-blink` as the VS Code workspace folder.
2. Build with the PlatformIO toolbar button, or `pio run` in the terminal.
3. Press `F1 → Wokwi: Start Simulator`.

## Expected result

The LED toggles every 500 ms. The simulator auto-reloads when you rebuild.

## Exercises

1. Change `kBlinkIntervalMs` to `100`. Does it look different, or does it look like
   the LED is just "on"? Understand why — this is the limit of what the eye can
   resolve, and the same reason real status LEDs need patterns rather than speed.
2. Remove `digitalWrite(kLedPin, LOW)` from `setup()`. Predict the LED's state on
   reset before you run it.
3. Replace `delay()` with a `millis()`-based scheduler so the loop stays
   non-blocking. (Lesson 02 shows the pattern.)
4. Add a second LED on `GPIO4` blinking in antiphase.