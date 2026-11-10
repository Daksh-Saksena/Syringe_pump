# Ender 3 Syringe Pump Conversion

A DIY, open-source syringe pump built by repurposing a Creality Ender 3 3D printer. Developed as a hardware project for [Hack Club Forge](https://github.com/hackclub/forge).

`[INSERT PHOTO: Complete assembled syringe pump]`

---

## Motivation

Commercial syringe pumps for microfluidics, chemistry experiments, and biological dispensing routinely cost anywhere between \$500 and \$3,000+. At the same time, thousands of Ender 3 printers sit unused in closets, maker spaces, and bedrooms.

An Ender 3 already provides:
- A rigid aluminum extrusion frame (2020 and 2040 V-slot profiles).
- A high-torque NEMA 17 stepper motor paired with a T8 lead screw.
- A 32-bit microcontroller board capable of precise microstepping.
- An integrated 24V DC power supply and user display interface.
- A complete motion control system programmable via standard G-code.

By removing the hotend, extruder, and heated bed and mounting custom 3D-printed syringe fixtures to the linear axis, the printer becomes a rigid, highly controllable precision syringe pump at a fraction of commercial cost.

---

## How It Works

`[INSERT IMAGE: CAD assembly]`

1. **Linear Actuation**: The stock NEMA 17 stepper motor drives a T8 lead screw. A 3D-printed plunger pusher mounted to the carriage travels along the extrusion, exerting direct axial force against the syringe plunger.
2. **Stationary Retention**: The syringe barrel is locked into a stationary 3D-printed cradle bolted to the aluminum frame. The barrel flange is mechanically captured to prevent axial slipping under backpressure.
3. **Volumetric Dispensing**: Fluid volume is directly proportional to linear carriage travel:
   $$\Delta V = \pi \times \left(\frac{D}{2}\right)^2 \times \Delta L$$
   where $D$ is the inner diameter of the syringe and $\Delta L$ is linear travel.
4. **Flow Rate Control**: Linear feedrate ($F$ in mm/min) corresponds directly to volumetric flow rate ($Q$ in mL/min).
5. **Travel Limits**: A physical limit switch homes the plunger at startup and prevents the carriage from over-driving past the syringe's bottom limit.

---

## Project Status

This project is actively in development under Hack Club Forge:

- [x] Concept & kinematics design
- [ ] CAD design of custom syringe cradle and plunger pusher (`[SPECIFY: In progress / Ready for printing]`)
- [ ] 3D printing custom mechanical brackets
- [ ] Teardown of Ender 3 donor frame
- [ ] Mechanical test assembly
- [ ] Controller board wiring and endstop configuration
- [ ] Firmware configuration (thermal error bypass, steps/mm)
- [ ] Dry linear calibration with calipers
- [ ] Wet gravimetric calibration on digital scale
- [ ] Full fluid dispensing benchmarks

---

## Repository Structure

```text
/
├── README.md               # Main project overview, motivation, and guide
├── BOM.csv                 # Itemized Bill of Materials with parts and pricing
├── LICENSE                 # Open-source MIT License
├── CAD/                    # 3D models, STEP files, and custom bracket geometry
│   └── README.md
├── Electronics/            # Wiring diagrams, pinouts, and electrical layout
│   └── README.md
├── Firmware/               # Source code, config files, and flashing steps
│   └── README.md
├── Production/             # 3D print profiles, slicing settings, and 3MF files
│   └── README.md
└── docs/                   # Detailed technical documentation
    ├── assembly.md         # Teardown and mechanical assembly guide
    ├── electronics.md      # Wiring, stepper tuning, and power distribution
    ├── firmware.md         # Kinematics config and cold extrusion bypass
    ├── calibration.md      # Linear and gravimetric volume calibration
    ├── troubleshooting.md  # Diagnostic guide for hardware and motion faults
    └── safety.md           # Mechanical pinch hazards and electrical safety
```

---

## Hardware & Bill of Materials

The complete inventory of donor hardware, fasteners, and printed parts is documented in [`BOM.csv`](BOM.csv).

Key hardware elements include:
- Base Frame: Creality Ender 3 donor chassis
- Syringe: `[SPECIFY: Syringe model and volume, e.g. 10mL / 20mL / 50mL]`
- Custom 3D Printed Parts: Syringe cradle, plunger pusher, limit switch mount
- Fasteners: Assorted M3, M4, and M5 hardware with drop-in T-nuts
- Controller: `[SPECIFY: Controller board model]`
- Power: `[SPECIFY: Stock 24V PSU / External supply]`

---

## Getting Started

### 1. Mechanical Assembly
Detailed teardown of the Ender 3 and assembly instructions for the syringe brackets can be found in [docs/assembly.md](docs/assembly.md).

`[INSERT PHOTO: Mechanical subassembly in progress]`

### 2. Electronics & Wiring
Instructions for wiring the stepper motor, connecting limit switches, and isolating unused heater terminals are in [docs/electronics.md](docs/electronics.md).

`[INSERT DIAGRAM: Electronics wiring]`

### 3. Firmware Flashing
Configuration details, steps/mm calculations, and cold-extrusion safety overrides are documented in [docs/firmware.md](docs/firmware.md).

`[ADD LINK: Firmware source]`

---

## Operation & Control

The syringe pump accepts standard G-code over USB serial (via Pronterface, OctoPrint, or a custom Python script):

```gcode
; Example Dispense Routine
G28 [AXIS]          ; Home axis against limit switch
G90                 ; Set absolute coordinate mode
G1 [AXIS]10 F120    ; Fast approach / prime plunger
G91                 ; Switch to relative coordinate mode
G1 [AXIS]5.2 F30    ; Dispense 5.2 mm of plunger travel at 30 mm/min
G1 [AXIS]-0.2 F200  ; Quick retraction to prevent dripping
M84                 ; De-energize stepper motor
```

---

## Calibration & Testing

Accuracy is verified through two phases:
1. **Linear Dry Calibration**: Verifying carriage travel against digital calipers.
2. **Gravimetric Wet Calibration**: Dispensing water onto a precision digital balance ($1.000\text{ g} \approx 1\text{ mL}$) across multiple target volumes.

Detailed procedures, test logs, and calibration data tables are in [docs/calibration.md](docs/calibration.md).

`[ADD DATA: Calibration results]`

---

## Safety

Review [docs/safety.md](docs/safety.md) before powering the system. Key precautions:
- Keep hands clear of lead screw pinch points.
- Verify endstop triggers before running automated routines to prevent syringe rupture.
- Never use this DIY system for clinical or medical applications.

---

## Relevant Links

- **Hack Club Forge Project Journal**: `[ADD LINK: Hack Club Forge Project Journal]`
- **Official Hack Club Forge**: [hackclub/forge](https://github.com/hackclub/forge)
- **CAD Repository / Releases**: `[ADD LINK: CAD download / release link]`
- **Firmware Repository**: `[ADD LINK: Firmware source]`

