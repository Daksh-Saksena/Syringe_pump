# Electronics & Wiring Guide

This document details the electrical setup, wiring modifications, controller board pinout, and motor current configuration for the Ender 3 syringe pump conversion.

`[INSERT DIAGRAM: Comprehensive electronics wiring diagram]`

---

## 1. System Overview

The conversion repurposes the stock Ender 3 electronics architecture (or an upgraded drop-in 32-bit silent board) to drive a single high-precision linear lead screw axis.

| Subsystem | Component | Role | Status |
| :--- | :--- | :--- | :--- |
| **Mainboard** | `[SPECIFY: Creality 4.2.2 / 4.2.7 / SKR Mini E3 / etc.]` | Microcontroller and motor control | `[SPECIFY: Stock / Upgraded]` |
| **Power Supply** | `[SPECIFY: Stock Mean Well 24V PSU / External Supply]` | System DC power | `[SPECIFY: Planned / Installed]` |
| **Drive Motor** | NEMA 17 Stepper Motor (Stock Ender 3) | Linear plunger actuation | Installed |
| **Stepper Driver** | `[SPECIFY: Onboard TMC2208/TMC2209/A4988]` | Stepper driving & microstepping | Configured |
| **Endstop Switch** | Mechanical microswitch | Plunger limit detection & homing | Wired |
| **Display / UI** | `[SPECIFY: Stock Ender 3 LCD, OLED, or USB control]` | User status & manual control | `[SPECIFY: Planned / Installed]` |

---

## 2. Wiring Connections & Pinouts

### 2.1 Mainboard Interconnects

`[INSERT PHOTO: Controller board wiring terminals and connectors]`

- **DC Power Input**: Connect the 24V DC leads from the power supply to the main `VIN` / `GND` screw terminals on the board. Double-check polarity with a multimeter before powering on.
- **Actuator Stepper Port**: Connect the stepper motor cable to the designated axis port `[SPECIFY: Z-motor header or E-motor header]`.
- **Limit Switch Port**: Connect the homing limit switch to the corresponding endstop connector `[SPECIFY: Z-MIN or custom endstop pin]`. Ensure signal (SIG) and ground (GND) lines match the board pinout.
- **Thermal Sensor / Heater Terminals**: 
  - Unused heated bed and hotend terminals should remain empty with screw terminals tightened down.
  - In firmware, dummy thermistor values or software heater disables must be applied so the board does not halt on thermal runaway / sensor errors.

`[INSERT TABLE: Board pinout and wiring connections]`

---

## 3. Stepper Motor Current & Driver Tuning

A syringe pump requires substantial linear force to overcome plunger friction and viscous fluid resistance, but running excessive current will overheat the motor and driver.

- **Motor Model**: `[SPECIFY: Motor part number and rated current, e.g. Creality 42-34 / 42-40]`
- **Driver Type**: `[SPECIFY: Standalone potentiometer adjustment or software UART control]`
- **Target Vref / RMS Current**:
  - `[SPECIFY: Reference voltage (Vref) in Volts or current in mA]`
  - Calculation formula used: `[INSERT FORMULA: Vref calculation based on Rsense and rated motor current]`

`[INSERT PHOTO: Multimeter probe placement on driver test point for Vref measurement]`

---

## 4. Endstop Wiring & Logic

Using a physical endstop switch is essential to prevent over-driving the syringe plunger into the bottom of the barrel.

- **Switch Configuration**: `[SPECIFY: Normally Closed (NC) or Normally Open (NO)]`
  - *Recommendation*: Normally Closed (NC) wiring is preferred for safety; if a wire breaks or disconnects, the machine registers as triggered and stops movement.
- **Pullup Resistor**: `[SPECIFY: Internal microcontroller pullup enabled in firmware]`

---

## 5. Cable Management & Safety

- Route all wiring away from the moving carriage and lead screw to prevent cables catching or chafing.
- Add zip ties or spiral wrap at key pivot points.
- Ensure all wire ferrules in screw terminals are crimped properly and checked for tightness.

`[INSERT PHOTO: Cable routing and strain relief on the frame]`

