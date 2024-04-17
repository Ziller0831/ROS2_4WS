#include "Arduino.h"
#include "kinematic.h"

Kinematics::Kinematics(base robot_base,
                       int motor_max_rpm,
                       float wheelDiameter,
                       float wheelBase,
                       float track)
    : eBasePlatform_(robot_base),
      iMaxRpm_(motor_max_rpm),
      fWheelBase_(eBasePlatform_ == DIFFERENTIAL_DRIVE ? 0 : wheelBase),
      fTrack_(track),
      fWheelCircumference_(PI * wheelDiameter * 0.0254){};

Kinematics::MControl Kinematics::inverseKinematics(MCommand *mCommand)
{
    if (eBasePlatform_ == ACKERMAN)
    {
    }
    // else if (eBasePlatform_ == ACKERMAN_SELF_ROTATE)
    // {
    // }
}

Kinematics::MControl Kinematics::ackerman(MCommand *mCommand)
{
    float linear_x_mins;
    float center_rotation_rad;
    float turning_angle;

    linear_x_mins = mCommand->linear_x * 1000; //* m/s -> m
    center_rotation_rad = mCommand->center_rotation_rad;
    turning_angle = mCommand->turning_distance;

    center_rotation_rad = ;

    MControl mControl;

    if (center_rotation_rad > 800 && turning_angle > 0)
    {
    }
    else if (center_rotation_rad < -800 && turning_angle > 0)
    {
    }
    else if (center_rotation_rad == 0 &&)
    {
        mControl.angle.STEPPER_R = 0;
        mControl.angle.STEPPER_L = 0;
    }

    return mControl;
}