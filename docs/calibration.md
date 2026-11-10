# Calibration & Testing Guide

This guide covers the procedures for calibrating linear axis displacement, calculating volumetric conversion factors for different syringe sizes, and experimentally verifying dispensing accuracy using gravimetric testing.

`[INSERT PHOTO: Calibration setup with digital scale, beaker, and syringe pump]`

---

## 1. Volumetric Calculation Theory

Because the lead screw drives the syringe plunger linearly, volumetric flow is directly proportional to linear displacement and the internal cross-sectional area of the syringe barrel.

### 1.1 Volume Conversion Formula

$$\Delta V = A \times \Delta L = \pi \times \left(\frac{D}{2}\right)^2 \times \Delta L$$

Where:
- $\Delta V$ = Dispensed volume ($\text{mm}^3$ or $\text{mL}$, where $1\text{ mL} = 1000\text{ mm}^3$)
- $D$ = Inner diameter of the syringe barrel ($\text{mm}$)
- $\Delta L$ = Linear travel distance of the plunger ($\text{mm}$)

### 1.2 Volumetric Resolution (Steps per mL)

$$\text{Steps per mL} = \frac{\text{Steps per mm} \times 1000}{\pi \times (D/2)^2}$$

### 1.3 Flow Rate Calculation

$$\text{Flow Rate } (Q) = A \times \text{Feedrate } (v)$$

To dispense at flow rate $Q$ ($\text{mL/min}$), set linear feedrate $F$ ($\text{mm/min}$) to:

$$F = \frac{Q \times 1000}{\pi \times (D/2)^2}$$

---

## 2. Syringe Specifications Reference

Fill in the measured inner dimensions for each syringe intended for use:

| Syringe Model / Brand | Nominal Volume (mL) | Inner Diameter $D$ (mm) | Usable Stroke Length (mm) | Volume per mm ($\mu\text{L/mm}$) |
| :--- | :--- | :--- | :--- | :--- |
| `[SPECIFY: Syringe 1]` | `[SPECIFY: Volume]` | `[SPECIFY: ID]` | `[SPECIFY: Stroke]` | `[SPECIFY: Vol/mm]` |
| `[SPECIFY: Syringe 2]` | `[SPECIFY: Volume]` | `[SPECIFY: ID]` | `[SPECIFY: Stroke]` | `[SPECIFY: Vol/mm]` |

---

## 3. Physical Linear Calibration (Dry Test)

Before loading liquid, confirm that commanded linear travel matches actual carriage movement.

### Procedure
1. Mount a digital caliper or dial indicator parallel to the linear axis.
2. Zero the caliper against the moving plunger pusher.
3. Command a 10 mm move:
   ```gcode
   G91
   G1 [AXIS]10 F100
   ```
4. Record actual travel on the caliper.
5. Repeat for 25 mm and 50 mm moves.

### Linear Travel Verification Results

| Commanded Travel (mm) | Measured Travel Run 1 (mm) | Measured Travel Run 2 (mm) | Measured Travel Run 3 (mm) | Error (%) |
| :--- | :--- | :--- | :--- | :--- |
| 10.00 | `[ADD DATA]` | `[ADD DATA]` | `[ADD DATA]` | `[ADD DATA]` |
| 25.00 | `[ADD DATA]` | `[ADD DATA]` | `[ADD DATA]` | `[ADD DATA]` |
| 50.00 | `[ADD DATA]` | `[ADD DATA]` | `[ADD DATA]` | `[ADD DATA]` |

`[INSERT PHOTO: Caliper measurement check on carriage]`

---

## 4. Gravimetric Dispensing Calibration (Fluid Test)

Water has a density of approximately $1.000\text{ g/mL}$ (at 20°C). Dispensing into a tared container on a precision digital balance provides an accurate validation of volumetric accuracy.

### Procedure
1. Fill the syringe with distilled water, ensuring all air bubbles are purged.
2. Mount the syringe securely in the cradle.
3. Prime the syringe tip until a droplet forms, then wipe clean.
4. Place a small beaker or collection vial on a precision scale (0.01 g or 0.001 g resolution) and tare to zero.
5. Command a specified dispense volume via G-code.
6. Record the mass reading on the balance.
7. Repeat across multiple target volumes.

### Gravimetric Calibration Data

`[ADD DATA: Calibration results]`

| Target Volume (mL) | Commanded Distance (mm) | Measured Mass (g) | Calculated Volume (mL) | Error (%) | Notes |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 0.50 | `[ADD DATA]` | `[ADD DATA]` | `[ADD DATA]` | `[ADD DATA]` | `[NOTES]` |
| 1.00 | `[ADD DATA]` | `[ADD DATA]` | `[ADD DATA]` | `[ADD DATA]` | `[NOTES]` |
| 2.50 | `[ADD DATA]` | `[ADD DATA]` | `[ADD DATA]` | `[ADD DATA]` | `[NOTES]` |
| 5.00 | `[ADD DATA]` | `[ADD DATA]` | `[ADD DATA]` | `[ADD DATA]` | `[NOTES]` |
| 10.00 | `[ADD DATA]` | `[ADD DATA]` | `[ADD DATA]` | `[ADD DATA]` | `[NOTES]` |

`[INSERT IMAGE: Graph of Commanded vs. Actual Dispensed Volume]`

---

## 5. Flow Rate vs. Backpressure Evaluation

Test dispensing at varying flow rates to identify motor stall limits under needle or tubing hydraulic resistance:

| Feedrate (mm/min) | Target Flow Rate (mL/min) | Observed Consistency | Motor Skipping / Stalling? |
| :--- | :--- | :--- | :--- |
| 10 | `[ADD DATA]` | `[ADD DATA]` | `[ADD DATA]` |
| 30 | `[ADD DATA]` | `[ADD DATA]` | `[ADD DATA]` |
| 60 | `[ADD DATA]` | `[ADD DATA]` | `[ADD DATA]` |
| 120 | `[ADD DATA]` | `[ADD DATA]` | `[ADD DATA]` |

`[INSERT PHOTO: Dispense stream or droplet formation during testing]`

