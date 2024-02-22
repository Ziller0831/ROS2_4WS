#include "4WD4WS.h"
#include "Ackerman.h"

void setup()
{
  pinMode(STEP_R, OUTPUT);
  pinMode(DIR_R, OUTPUT);
  pinMode(STEP_L, OUTPUT);
  pinMode(DIR_L, OUTPUT);

  Serial.begin(115200);

  RightStepper.setMaxSpeed(3200);
  // RightStepper.setAcceleration(3200 / 2);
  RightStepper.setSpeed(1600);

  LeftStepper.setMaxSpeed(3200);
  // LeftStepper.setAcceleration(3200 / 2);
  LeftStepper.setSpeed(1600);

  steppers.addStepper(RightStepper);
  steppers.addStepper(LeftStepper);
}

void loop()
{
  if(Serial.available() > 0)
    Angle = Serial.parseInt();

  Pulse[0] = Angle / 8;
  Pulse[1] = Pulse2Deg / 8;
  steppers.moveTo(Pulse);
  steppers.runSpeedToPosition(); // Blocks until all are in position
  delay(1000);
}


