# embedded-learning

A hands-on C++ learning repository for embedded development, built around the
[Wokwi](https://wokwi.com) simulator. Every lesson is a small, self-contained
project: write C++, build it, watch it run in a simulated circuit, then break it on
purpose and figure out why.

No physical hardware required.

## Stack

| Tool | Role |
| --- | --- |
| **VS Code** | Editor and workspace |
| **PlatformIO** | Build system, toolchain, dependency management |
| **Wokwi** | Circuit simulator for ESP32 |
| **C++17** | The language being learned |

Target board: **ESP32 DevKit v4** (`esp32dev` in PlatformIO,
`board-esp32-devkit-c-v4` in Wokwi), built with the Arduino framework.

## Prerequisites

Install in VS Code (`.vscode/extensions.json` recommends all three):

1. **PlatformIO IDE** — `platformio.platformio-ide`
2. **Wokwi Simulator** — `wokwi.wokwi-vscode`
3. **C/C++** — `ms-vscode.cpptools`

Then activate a Wokwi license:

1. `F1` → **Wokwi: Request a new License**
2. Confirm the browser prompt, then click **GET YOUR LICENSE**
3. Sign in to your free Wokwi account if asked
4. You should see *"License activated for …"*

> **Note:** the Wokwi VS Code extension is a commercial product. It works free of
> charge during a trial period, then requires a paid license. The free
> [wokwi.com](https://wokwi.com) simulator covers the browser-based lessons in this
> repo without one.

## Lessons

| # | Lesson | Teaches |
| --- | --- | --- |
| [00](lessons/00-template) | Template | How to start a new lesson |
| [01](lessons/01-blink) | Blink | `setup()`/`loop()`, `pinMode()`, `digitalWrite()`, `delay()` |
| [02](lessons/02-button-input) | Button Input | `digitalRead()`, `INPUT_PULLUP`, debouncing, `millis()` |

Each lesson is an independent PlatformIO project — no shared code, no build-order
dependencies. Delete one, reorder them, or copy one without affecting the others.

## How to run a lesson

Every lesson is its own VS Code workspace, because Wokwi resolves `wokwi.toml`
relative to the workspace root.

```bash
cd lessons/01-blink
```

1. **Open the lesson folder** in VS Code — `File → Open Folder`, pick
   `lessons/01-blink`. Opening the repository root will not work.
2. **Build** — click the PlatformIO toolbar button, or run:

   ```bash
   pio run
   ```

3. **Simulate** — `F1` → **Wokwi: Start Simulator**

Wokwi does not compile your code, so build first. Once the simulator is running, it
reloads your firmware automatically every time you rebuild.

### Serial output

`platformio.ini` sets `monitor_speed = 115200`. Once you add `Serial` calls, open
the PlatformIO Serial Monitor, or forward the simulated port from `wokwi.toml`:

```toml
[wokwi]
rfc2217ServerPort = 4000
```

Then connect with `rfc2217://localhost:4000`.

## Repository layout

```
embedded-learning/
├── README.md               # this file
├── .gitignore              # PlatformIO, VS Code and Wokwi build artifacts
├── .vscode/
│   └── extensions.json     # recommended extensions
└── lessons/
    ├── 00-template/        # copy this to start a new lesson
    ├── 01-blink/
    └── 02-button-input/
```

Every lesson folder contains the same six entries:

| File | Purpose |
| --- | --- |
| `README.md` | The lesson: goal, concepts, wiring, exercises |
| `platformio.ini` | Board, framework, compiler flags |
| `src/main.cpp` | `setup()` and `loop()` |
| `include/` | Lesson-local headers, when needed |
| `diagram.json` | Wokwi circuit description |
| `wokwi.toml` | Points Wokwi at the compiled firmware |

## Adding a new lesson

```bash
cp -r lessons/00-template lessons/03-my-topic
```

Then write the code, describe the circuit, and rewrite the README. The template's
README documents the whole process. Conventions:

- Directory names are `NN-kebab-case-topic` with a two-digit prefix so lessons sort
  in learning order.
- Teach one idea per lesson, and put the explanation in the lesson `README.md`
  rather than in code comments.
- End every lesson README with exercises, including at least one that requires
  changing the code.

## Conventions

- `constexpr` constants for pins and timings, declared in an anonymous `namespace`
  in `main.cpp`.
- C++17, `-Wall -Wextra`, no warnings tolerated.
- Forward slashes in `wokwi.toml` paths so the repo works on Windows, macOS and
  Linux.
- Comments in code are avoided on purpose — the lesson README is where the
  reasoning lives.

## Troubleshooting

**`firmware binary .pio/build/esp32dev/firmware.bin not found in workspace`**
Build the project first (`pio run`), and check that `esp32dev` in `wokwi.toml`
matches the `[env:…]` name in `platformio.ini`.

**Nothing happens in the simulator**
Check the simulator tab is visible — VS Code may pause simulation for a background
tab. Confirm the build produced no errors.

**Wokwi can't find `diagram.json`**
Both `diagram.json` and `wokwi.toml` must sit in the workspace root, next to
`platformio.ini`. If you prefer, run `F1 → Wokwi: Diagram Editor` and build the
circuit visually.

**PlatformIO builds the wrong project**
PlatformIO picks the nearest `platformio.ini` upward from the open folder. Open the
lesson folder itself, not the repository root.