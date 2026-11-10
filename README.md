# Syringe Pump

A smallish, mostly 3D printed syringe pump built around an Arduino Uno, a 28BYJ-48 stepper motor, Ender roller and a T8 lead screw. The idea was to make a simple mechanism that can push a syringe plunger at a adjustable rate.
The entire mechanical assembly is custom 3D printed, with a linear carriage that moves along an extrusion and pushes the syringe plunger. The servo is controlled using a potentiometer so that the flow rate can be adjusted while the pump is running.

## Why?

For a larger prototype I am working on, I needed a way to move fluid through a system at a controlled rate. Instead of using a manually operated syringe or trying to control the flow by hand (basically impossible) , I wanted to build a small motorised mechanism that could push the syringe at a consistent speed.

Commercial syringe pumps ARE VERRRYYYY expensive (60$+), especially when all I really needed was a relatively simple mechanism with adjustable flow. I decided to build 1 myself, using readily available electronics and 3D printed parts, combining the parts i and eshant had, we had all the parts so there was no need to buy anything!

## How it works

[INSERT IMAGE: Full assembled syringe pump]

The main structure is built around an extrusion which acts as the guide for the moving carriage. At one end, a 28BYJ48 stepper motor drives a T8 threaded lead screw. As the screw rotates, it moves a constrained carriage forward or backward along the extrusion. The carriage rides on rollers and has a pusher attached to it, which presses against the syringe plunger.

At the other end of the extrusion is a separate syringe holder. The syringe sits between the holder and the moving carriage, with its plunger facing the carriage. When the motor turns the lead screw, the carriage moves towards the syringe and pushes the plunger, displacing the liquid inside it. Reversing the motor moves the carriage in the opposite direction.

The syringe holder and the other mechanical components are custom designed and 3D printed. The syringe itself is removable, so different syringes can be fitted without having to rebuild the entire mechanism.

If this is confusing, please watch the video here -> i gotta put the link

![Assembley](docs/assembley.png)

## Electronics and control

The electronics are based around an Arduino Uno. A 28BYJ-48 stepper motor is connected through a ULN2003 driver board, while a potentiometer is used to control the motor speed. A 16x2 LCD with an I2C interface displays the calculated flow rate.

The potentiometer works around a centre position. Turning it towards one side increases the forward speed, while turning it towards the other side reverses the motor. Keeping it around the centre stops the motor. This gives a continuous way of adjusting the pump rather than having to choose between a few fixed speed settings.

One thing I wanted to avoid was displaying only motor RPM, since that doesn't tell the user much about how quickly liquid is actually being displaced. Instead, the Arduino calculates the theoretical flow rate in mL/s using the syringe dimensions and the lead screw's movement per revolution, and displays that value directly.

[INSERT IMAGE: Electronics setup with Arduino, ULN2003 and LCD]

![Wiring diagram](docs/Wiring_diagram.png)

## How the flow rate is calculated

The flow rate depends on two things: how far the syringe plunger moves and the internal cross-sectional area of the syringe barrel.

For this build, the lead screw has a pitch of 2 mm and four starts, giving a lead of 8 mm per revolution. This means that one complete rotation moves the carriage by 8 mm.

The volume displaced in one revolution is therefore:

\[
V = \frac{\pi D^2}{4} \times L
\]

Where:

- \(D\) is the internal diameter of the syringe barrel in mm.
- \(L\) is the lead screw lead in mm per revolution.

The flow rate is then calculated using:

\[
Q = \frac{\pi D^2}{4} \times \frac{L \times RPM}{60000}
\]

The result is in mL/s.

For the current setup, the code uses an approximate syringe internal diameter of 16 mm and a lead screw lead of 8 mm. These values can be changed in the firmware to accommodate different syringe dimensions.

This means the calculation isn't tied to one particular syringe capacity. As long as the internal diameter is known, the firmware can calculate the corresponding theoretical flow rate.

## Firmware

The pump is controlled using an Arduino Uno and the Arduino firmware is in the `Firmware` folder.

The code uses the following libraries:

- `Wire.h` for I2C communication.
- `LiquidCrystal_I2C.h` for the LCD.
- `AccelStepper.h` for controlling the stepper motor.

To get it running, install these libraries through the Arduino IDE Library Manager, open `Firmware/Arduino-code.cpp`, select the Arduino Uno as the board, and upload the code.

The current pin configuration is:

| Component | Arduino pin |
|---|---|
| ULN2003 IN1 | D8 |
| ULN2003 IN2 | D9 |
| ULN2003 IN3 | D10 |
| ULN2003 IN4 | D11 |
| Potentiometer output | A0 |
| LCD SDA | A4 |
| LCD SCL | A5 |

The LCD uses I2C address `0x27`.

A few values can be changed directly in the code depending on the hardware being used:

| Variable | Current value | Purpose |
|---|---:|---|
| `Diameter` | 16.0 mm | Internal syringe diameter |
| `Lead_MM` | 8.0 mm | Lead screw movement per revolution |
| `Steps_per_rev` | 4096 | Approximate motor output steps per revolution |
| `max_rpm` | 10.0 | Maximum lead screw RPM |
| `deadzone` | 35 | Potentiometer centre deadzone |

The flow rate shown on the LCD is calculated from these values, so changing the syringe or lead screw dimensions requires updating the corresponding variables.

## Assembly

The complete assembly consists of the extrusion, lead screw, stepper motor, moving carriage, syringe holder and the printed brackets and supports.

[INSERT IMAGE: Exploded CAD view of the assembly]

[INSERT IMAGE: Motor mounting and lead screw connection]

[INSERT IMAGE: Carriage and roller arrangement]

[INSERT IMAGE: Syringe installed in the holder]

The motor is mounted at one end of the extrusion and connected to the lead screw. The lead screw runs alongside the extrusion and engages with the nut attached to the moving carriage. The carriage is constrained by its rollers, allowing it to travel along the extrusion without rotating along with the screw.

The syringe holder is mounted at the opposite end. Once the syringe is installed, its plunger rests against the pusher attached to the carriage. The mechanical arrangement allows the motor to move the plunger in either direction.

More detailed assembly photographs and CAD files will be added to the repository as the documentation is updated.

## BOM

The following is the bill of materials for the build. All the components were already available to us, so the actual money spent on this build was ₹0. The prices below are the approximate replacement costs of the components.

| Component | Details | Quantity | Price |
|---|---|---:|---:|
| 3D printed parts | Custom mechanical components; relatively little filament used | 1 set | ₹0 |
| Stepper motor + driver | 28BYJ-48 5V with ULN2003 driver board | 1 | ₹100 |
| T8 lead screw | 8 mm diameter, 2 mm pitch, 4-start | 1 | ₹270 |
| LCD display | JHD162A or similar 16x2 LCD with I2C backpack | 1 | ₹180 |
| Arduino Uno | UNO R3 compatible board | 1 | ₹250 |
| **Total** | | | **₹800 ($8.55)** |

Purchase links and the complete BOM are available in [`BOM.csv`](BOM.csv).

## Known issues and things to improve

The flow rate displayed by the firmware is currently a theoretical calculation based on the syringe diameter and lead screw movement. Actual delivered flow can differ due to mechanical friction, backlash, variations in the syringe dimensions and the performance of the stepper motor. The system will need to be calibrated against measured liquid output to establish how closely the displayed rate matches the actual flow rate.

The current firmware also uses an approximate steps-per-revolution value for the 28BYJ-48, and the actual motor speed should be checked during calibration. The maximum speed is currently limited to 10 RPM.

[ADD: Any other known issues or improvements]

## Repository structure

```text
Syringe_pump/
│
├── CAD/
│   └── [CAD source files and exports]
│
├── docs/
│   └── [Assembly, wiring and other documentation]
│
├── Firmware/
│   ├── Arduino-code.cpp
│   └── README.md
│
├── BOM.csv
├── .gitignore
└── README.md
