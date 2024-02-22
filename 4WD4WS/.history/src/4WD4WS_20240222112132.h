#include <Arduino.h>
#include <AccelStepper.h>
#include <MultiStepper.h>

const int DIR_R = 12;
const int STEP_R = 14;
const int DIR_L = 2;
const int STEP_L = 15;

AccelStepper RightStepper(AccelStepper::DRIVER, STEP_R, DIR_R);
AccelStepper LeftStepper(AccelStepper::DRIVER, STEP_L, DIR_L);

MultiStepper steppers;

const float StepAngle = 1.8;
const int MicroStep = 16;
const int GearRatio = 10;       // 10:1

int RobotVelocity;
int RobotAngle;

const int WheelAxleSpacing = 1120; // mm
const int WheelSpacing = 750;      // mm

//* 輪子轉一圈要的脈衝數
double Pulse2Deg = 360 / ((360 / StepAngle) * MicroStep * GearRatio); // (360/1.8)*16*10 = 32000  1 pulse = 0.01125 degree

float Angle;
long Pulse[2];

typedef struct{

}