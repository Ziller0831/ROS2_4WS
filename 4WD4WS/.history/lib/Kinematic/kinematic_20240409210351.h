/**
 * @file kinematic.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-08
 * 
 * @copyright Copyright (c) 2024
 * 
 * *負責將ROS2輸入進來的線速度與角速度最終轉換成PWM與Pulse
 */

#ifndef KINEMATIC_H
#define KINEMATIC_H

#include <Arduino.h>

class Kinematics
{
public:
    enum base
    {
        ACKERMANN,            // 1
        ACKERMANN_SELF_ROTATE, // 2
        DIFFERENTIAL_DRIVE
    };

    enum base base_platform;

    
    struct Velocities
    {
        float linear_x;
        float rotate_z; //* maybe steering angle or rotate vel
    };

    struct rpm
    {
        int BLDC_R;
        int BLDC_L;
    };

    struct pwm
    {
        float BLDC_R;
        float BLDC_L;
    };

    struct angle
    {
        float STEPPER_R;
        float STEPPER_L;
    };

    struct pulse
    {
        float STEPPER_R;
        float STEPPER_L;
    };

    Kinematics(base robot_base, int motor_max_rpm, float wheelDiameter, float wheelsBase, float track);
    rpm inverseKinematics(float linear_x, float rotate_z);

private:

    int max_rpm_;
    float wheelsBase_;
    float track_;
    float wheel_circumference_;

    rpm ackermann(float linear_x, float steering)
};

#endif