# Firmware Configuration & Setup

This guide documents the firmware architecture, parameter adjustments, and compilation instructions for running the Ender 3 as a dedicated syringe pump.

`[ADD LINK: Link to firmware repository, branch, or release binary]`

---

## 1. Firmware Architecture

- **Firmware Base**: `[SPECIFY: Marlin 2.x bugfix / Klipper / Custom C++ firmware]`
- **Build Environment**: `[SPECIFY: VS Code with PlatformIO / Arduino IDE]`
- **Target Environment / Board**: `[SPECIFY: e.g. STM32F103RET6_creality, STM32G0B1RE, etc.]`
- **Control Interface**: `[SPECIFY: G-code over USB Serial (115200 / 250000 baud), standalone LCD menu, or web interface]`

---

## 2. Key Configuration Settings

When configuring 3D printer firmware for a syringe pump, standard 3D printer assumptions (like requiring a hot hotend to extrude, or halting if thermistors are unplugged) must be modified.

### 2.1 Thermal Management & Error Bypass
Because heaters and thermistors are removed from the converted printer:

- **Thermal Runaway Protection**: Disabled or bypassed for hotend and heated bed since no heaters are connected.
- **Dummy Thermistors**:
  - `[SPECIFY: Set temp sensors to 998 / 999 (dummy fixed temperature) or disable thermal checks entirely]`
- **Prevent Cold Extrusion**: If the linear axis is mapped as an extruder (`E`), cold extrusion protection must be disabled (`#define PREVENT_COLD_EXTRUSION` commented out or `M302 S0` executed at startup).

`[INSERT CODE / CONFIG SNIPPET: Thermal configuration settings]`

---

### 2.2 Axis Kinematics & Steps per Millimeter

The linear motion of the plunger depends on the stepper motor's step angle, microstepping mode, and lead screw pitch.

- **Lead Screw**: `[SPECIFY: Stock Ender 3 T8x8 (8mm lead per revolution), T8x4, T8x2, etc.]`
- **Step Angle**: 1.8° (200 steps/revolution)
- **Microstepping**: `[SPECIFY: 1/16, 1/32, or interpolated]`
- **Default Steps per mm**:
  $$\text{Steps/mm} = \frac{\text{Steps per Revolution} \times \text{Microstepping}}{\text{Lead Screw Pitch (mm/rev)}}$$
  `[SPECIFY: Calculated steps/mm value, e.g. 400 for T8x8 at 1/16]`

`[INSERT CODE / CONFIG SNIPPET: Movement and steps/mm definition]`

---

### 2.3 Motion Limits & Feedrates

To prevent skipping steps under fluid resistance and ensure smooth dispensing:

- **Maximum Feedrate**: `[SPECIFY: Max linear speed in mm/s or mm/min]`
- **Maximum Acceleration**: `[SPECIFY: Acceleration limit in mm/s²]`
- **Homing Feedrate**: `[SPECIFY: Safe homing speed in mm/min]`
- **Invert Axis Direction**: `[SPECIFY: true / false depending on motor wiring and push direction]`

`[INSERT CODE / CONFIG SNIPPET: Acceleration, jerk, and feedrate limits]`

---

### 2.4 Endstops & Travel Limits

- **Homing Direction**: `[SPECIFY: -1 (homing to minimum) or +1 (homing to maximum)]`
- **Software Endstops**: `[SPECIFY: Enabled / Disabled]`
- **Travel Limits**:
  - `MIN_POS`: `0 mm`
  - `MAX_POS`: `[SPECIFY: Maximum usable plunger stroke in mm]`

---

## 3. Basic Operating G-Code Commands

The pump can be controlled via any standard G-code serial sender (e.g. Pronterface, Python `pyserial` script, OctoPrint):

| Command | Action | Description |
| :--- | :--- | :--- |
| `G28 [AXIS]` | Home Axis | Moves carriage to home switch to establish zero position |
| `G90` | Absolute Mode | Sets positioning to absolute coordinates |
| `G91` | Relative Mode | Sets positioning to incremental coordinates |
| `G1 [AXIS]... F...` | Controlled Move | Moves plunger at specified feedrate (F in mm/min) |
| `M114` | Get Position | Reports current position coordinates |
| `M119` | Endstop Status | Queries state of mechanical limit switches |
| `M84` | Disable Steppers | De-energizes stepper motors |

---

## 4. Compilation & Flashing Procedure

1. Clone or open the firmware project in `[SPECIFY: PlatformIO / IDE]`.
2. Select the target board environment: `[SPECIFY: Environment name]`.
3. Build the firmware binary.
4. Flash the board:
   - For 32-bit Creality boards: Copy the generated `firmware-[TIMESTAMP].bin` to a FAT32-formatted microSD card, insert it into the board, and power cycle.
   - For direct USB flashing: Connect via USB cable and initiate upload.
5. Connect over serial at `[SPECIFY: Baud rate]` and verify terminal startup output.

`[INSERT PHOTO: Successful firmware compilation or serial terminal output]`

