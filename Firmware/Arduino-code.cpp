#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <AccelStepper.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ULN2003 , change values based on what u pick, but i picked IN1 = 8, IN2 = 9, IN3 = 10, IN4 = 11
AccelStepper motor(AccelStepper::HALF4WIRE, 8, 10, 9, 11);

const int Pot = A0; // Potentiometer, again change values on what u pick

// syring specifications , ive made the code such that it works with any syringe size, just measure values
const float Diameter = 16.0;
const float Lead_MM = 8.0;

const float Steps_per_rev = 4096.0; // depends on servo
const float max_rpm = 10.0;
const int deadzone = 35; // Center of the potentioemter

unsigned long lastDisplayUpdate = 0;
const unsigned long DISPLAY_INTERVAL = 150;
float currentFlowRate = 0;
String direction = "STOP";

void setup() {
  lcd.init();
  lcd.backlight();
  motor.setMaxSpeed(800);
  lcd.setCursor(0, 0);
  lcd.print("Syringe Pump"); // this is just to to reset motor and wait time for it
  lcd.setCursor(0, 1);
  lcd.print("Starting");
  delay(1500);
  lcd.clear();
}

void loop() {
  int potValue = analogRead(Pot);
  const int Center = 512;
  float normalizedSpeed = 0;
  if (potValue > Center + deadzone) {
    normalizedSpeed =
      (float)(potValue - Center - deadzone) /
      (1023 - Center - deadzone);
    direction = "FWD";
  }
  else if (potValue < Center - deadzone) {
    normalizedSpeed =
      (float)(Center - deadzone - potValue) /
      (Center - deadzone);
    direction = "REV";
  }
  else {
    normalizedSpeed = 0;
    direction = "STOP";
  }
  normalizedSpeed = constrain(normalizedSpeed, 0.0, 1.0);
  float rpm = normalizedSpeed * max_rpm;

  // Calculate flow rate -> Q = area * lead * RPM / 60000
  float area = PI * pow(Diameter / 2.0, 2);

  currentFlowRate =
    (area * Lead_MM * rpm) / 60000.0;

  // Convert lead screw RPM to motor steps/sec
  float stepsPerSecond =
    (rpm * Steps_per_rev) / 60.0;

  // Set motor direction
  if (direction == "REV") {
    stepsPerSecond = -stepsPerSecond;
  }

  if (direction == "STOP") {
    motor.setSpeed(0);
  } else {
    motor.setSpeed(stepsPerSecond);
  }

  // Run motor continuously
  motor.runSpeed();

  if (millis() - lastDisplayUpdate >= DISPLAY_INTERVAL) {

    lastDisplayUpdate = millis();
    lcd.setCursor(0, 0);
    lcd.print("Flow: ");
    lcd.print(currentFlowRate, 3);
    lcd.print(" mL/s ");
    lcd.setCursor(0, 1);
    lcd.print("Direction: ");
    lcd.print(direction);
    lcd.print("    ");
  }
}
