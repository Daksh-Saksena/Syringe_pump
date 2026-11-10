# Syringe Pump Mechanical Assembly Guide

This guide covers the physical teardown of the donor Creality Ender 3 and the step-by-step assembly of the syringe pump conversion.

`[INSERT PHOTO: Complete assembled syringe pump]`

---

## 1. Required Tools & Materials

### Tools
- Metric Allen / Hex keys (1.5mm, 2.0mm, 2.5mm, 3.0mm, 4.0mm)
- Open-end wrench / adjustable wrench (for V-slot eccentric nuts and M3/M4/M5 nuts)
- Calipers or ruler (for alignment verification)
- Soldering iron (if installing threaded brass heat-set inserts into 3D printed parts)
- Screwdriver set

### Components
- Stripped Ender 3 aluminum extrusion frame and linear motion hardware
- 3D printed custom parts (printed from [`Production/`](../Production/README.md))
- Fasteners (M3/M4/M5 screws, lock nuts, washers, and extrusion T-nuts)
- Syringe: `[SPECIFY: Syringe model and volume]`

---

## 2. Donor Teardown & Frame Preparation

Before installing the syringe-specific brackets, remove unnecessary 3D printing components from the Ender 3:

1. **Power Down & Disconnect**: Ensure the printer is completely unplugged from wall AC power.
2. **Remove the Hotend & Bowden Extruder**: Unbolt the hotend assembly, fan shroud, and heatsink from the carriage. Remove the extruder motor bracket or repurpose its motor if needed.
3. **Handle Unneeded Heated Bed Components**: 
   - `[SPECIFY: Bed removal details - e.g., removed entirely to leave a compact vertical/horizontal rig, or bed plate clamped in place]`
4. **Clean & Inspect Linear Motion**:
   - Clean the aluminum V-slot extrusions with isopropyl alcohol.
   - Inspect the POM V-wheels for flat spots or wear.
   - Clean and lightly lubricate the T8 lead screw.

`[INSERT PHOTO: Teardown progress - Ender 3 frame prepped for conversion]`

---

## 3. Step-by-Step Assembly

### Step 3.1: Mount the Stationary Syringe Cradle
The syringe body must remain absolutely stationary under substantial axial pushing pressure.

1. Position the 3D-printed syringe cradle against the 2020/2040 aluminum extrusion.
2. Insert M4 or M5 bolts with drop-in T-nuts into the extrusion slot.
3. Tighten fasteners evenly, verifying that the cradle sits parallel to the axis of motion.
4. If using a clamp-down top collar, test-fit the syringe barrel without overtightening.

`[INSERT IMAGE: CAD render of syringe cradle mounted to extrusion]`
`[INSERT PHOTO: Syringe cradle bolted to the frame]`

---

### Step 3.2: Assemble the Plunger Pusher Carriage
The plunger pusher attaches to the moving carriage and drives the syringe piston forward.

1. Attach the 3D-printed plunger interface block to the linear carriage `[SPECIFY: X-carriage or Z-axis leadscrew carriage]`.
2. Ensure the face of the pusher makes flush, perpendicular contact with the circular thumb flange of the syringe plunger.
3. Tighten the mounting bolts securely to avoid any tilting or deflection under fluid backpressure.

`[INSERT IMAGE: CAD render of plunger pusher interface]`
`[INSERT PHOTO: Plunger pusher attached to carriage]`

---

### Step 3.3: Align the Lead Screw & Motor Coupling
Lead screw binding causes lost steps, uneven flow rates, or motor stalls.

1. Ensure the flexible or rigid shaft coupler between the NEMA 17 stepper motor and the T8 lead screw is securely seated and grub screws are tightened onto the motor D-shaft flat.
2. Adjust the brass lead screw nut on the moving carriage. Leave the mounting screws slightly loose while running the carriage through its full stroke, then snug them down to prevent axial binding.
3. Check the eccentric nuts on the V-slot wheels. They should be snug enough to prevent carriage wobble, but loose enough to spin with light thumb friction.

`[INSERT PHOTO: Lead screw, motor coupler, and carriage alignment]`

---

### Step 3.4: Install Limit Switches (Endstops)
Endstop switches prevent the motor from driving the plunger into the syringe bottom or pulling the plunger out of the barrel.

1. Mount the minimum-travel limit switch at the point where the plunger reaches its fully dispensed stroke limit `[SPECIFY: Mounting bracket location]`.
2. Mount the maximum-travel limit switch (or configure software limits) at the full-draw position.
3. Hand-test the carriage travel to confirm the limit switch clicks before physical mechanical collision occurs.

`[INSERT PHOTO: Limit switch mounting position]`

---

## 4. Mechanical Validation Checklist

Before wiring or powering on:

- [ ] Carriage moves smoothly along the entire travel distance with no binding.
- [ ] Syringe sits firmly in the cradle with zero axial or radial play.
- [ ] Plunger pusher contacts the syringe plunger squarely and evenly.
- [ ] Endstop triggers cleanly before any hard mechanical stop is hit.
- [ ] All frame bolts and extrusion joints are rigid and squared.

`[INSERT PHOTO: Fully assembled mechanical setup with syringe installed]`

