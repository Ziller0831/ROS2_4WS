/*
 * @file main.cpp
 * @Jhih-Bin Huang (F112102103@nkust.edu.tw)
 * @brief
 * @version 0.1
 * @date 2024-02-21
 *
 * @copyright Copyright (c) 2024
 *
 * Input argument:
 *    Robot_yaw -> 轉彎角度
 *    v -> 車體速度
 */

#include <Arduino.h>
#include "ros_communication.h"
#include "Base_controller.h"
#include "kinematic.h"

Kinematics kinematics(
    Kinematics::ACKERMAN,
    MAX_BLDC_RPM,
    WHEEL_DIAMETER,
    WHEELBASE,
    TRACK
);

ROS_communication ros;


BLDC bldcR_controller(0, BLDC_R_PWM, R_PWM_CHANNEL, BLDC_R_REV, 120);
BLDC bldcL_controller(0, BLDC_L_PWM, L_PWM_CHANNEL, BLDC_L_REV, 120);



void setup()
{
  Stepper_init();

  ros.initialize();
  ros.subscriber_define();
  ros.executors_start();
}

void loop()
{
  ros.start_receiving_msgs();
}