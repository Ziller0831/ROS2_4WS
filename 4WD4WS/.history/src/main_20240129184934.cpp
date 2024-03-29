#include <Arduino.h>
#include <AccelStepper.h>
#include "pinSetup.h"

AccelStepper motor(motorInterfaceType, STEP, DIR);

void setup()
{
  Serial.begin(115200);
  motor.setMaxSpeed(1000);
  motor.setAcceleration(60);
  motor.setSpeed(600);
  motor.moveTo(0);
}

void loop()
{
  motor.runSpeed();
}