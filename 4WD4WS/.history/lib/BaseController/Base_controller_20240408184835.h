/**
 * @file Base_controller.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-08
 * 
 * *目前這個部分是將整個底層控制器當成一個物件來管理，後面可改成將每顆馬達物件化
 * 
 * 
 */

#ifndef BASE_CONTROLLER_H
#define BASE_CONTROLLER_H

#include <Arduino.h>
#include <AccelStepper.h>
#include "base_config.h"

AccelStepper RightStepper(AccelStepper::DRIVER, STEP_R, DIR_R);
AccelStepper LeftStepper(AccelStepper::DRIVER, STEP_L, DIR_L);

double Pulse2Deg = 360 / ((360 / StepAngle) * MicroStep * GearRatio);

class base_controller
{
public:
    struct pwm
    {
        float BLDC_R;
        float BLDC_L;
    };

    struct pulse
    {
        float STEPPER_R;
        float STEPPER_L;
    };

private:
    void MotorDrive(byte PWM_R, float );
    void Steering(float thetaR, float thetaL);

    void BLDCSetting();
    void SteperSetting();
};


#endif