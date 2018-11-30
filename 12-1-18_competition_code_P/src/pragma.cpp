#include "main.h"

Motor leftChassis1(1, MOTOR_GEARSET_18, 0, MOTOR_ENCODER_ROTATIONS);
Motor leftChassis2(2, MOTOR_GEARSET_18, 1, MOTOR_ENCODER_ROTATIONS);
Motor rightChassis1(3, MOTOR_GEARSET_18, 0, MOTOR_ENCODER_ROTATIONS);
Motor rightChassis2(4, MOTOR_GEARSET_18, 1, MOTOR_ENCODER_ROTATIONS);
Motor catapult(5, MOTOR_GEARSET_36, 0, MOTOR_ENCODER_ROTATIONS);
Motor intake(6, MOTOR_GEARSET_6, 0, MOTOR_ENCODER_ROTATIONS);

Vision catapultEye(19, E_VISION_ZERO_CENTER);

ADIDigitalOut intakePiston1(2);
ADIDigitalOut intakePiston2(3);
ADIDigitalOut chassisTransmissionPiston(4);
ADIDigitalIn is_cap(5);
ADIDigitalIn catabut(6);

Controller master(E_CONTROLLER_MASTER);
Controller partner(E_CONTROLLER_PARTNER);