#include "ros_communication.h"
#include "Base_controller.h"

rcl_subscription_t sub;
geometry_msgs__msg__Twist Twist;

rcl_allocator_t allocator;
rclc_support_t support;
rcl_node_t node;
rclc_executor_t executor;

ROS_communication::ROS_communication() {}

void ROS_communication::initialize()
{
    Serial.begin(115200);
    Serial.println("ROS Communication node started");
    set_microros_serial_transports(Serial);

    allocator = rcl_get_default_allocator();

    rclc_support_init(&support, 0, NULL, &allocator);
    rcl_node_options_t node_ops = rcl_node_get_default_options();
    node_ops.domain_id = 56;
    rclc_node_init_with_options(&node, "Base_controller", "", &support, &node_ops);
}

void ROS_communication::executors_start()
{
    rclc_executor_init(&executor, &support.context, 1, &allocator);
    rclc_executor_add_subscription(
        &executor,
        &sub,
        &Twist,
        &ROS_communication::vel_callback,
        ON_NEW_DATA);

    Serial.println("Executors Started");
}

void ROS_communication::subscriber_define()
{
    rclc_subscription_init_default(
        &sub,
        &node,
        ROSIDL_GET_MSG_TYPE_SUPPORT(geometry_msgs, msg, Twist),
        "/cmd_vel");
}

void ROS_communication::vel_callback(const void *msg_recv)
{
    const geometry_msgs__msg__Twist *received_data = (const geometry_msgs__msg__Twist *)msg_recv;
    float linear_vel = received_data->linear.x;
    float steer_angle = received_data->angular.z;

    /* 馬達控制函式*/
    MotorDrive(linear_vel);
    Ackermann(steer_angle);
}

void ROS_communication::start_receiving_msgs()
{
    rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100));
    delay(100);
}