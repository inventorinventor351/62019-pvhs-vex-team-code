#include "main.h"

Controller master(E_CONTROLLER_MASTER); //Master Controller

Motor leftChassis1(1, MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_ROTATIONS); //Port 1, 200 RPM gearset, reversed, units of rotations for encoder
Motor leftChassis2(2, MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_ROTATIONS); //Port 2, 200 RPM gearset, not reversed, units of rotations for encoder
Motor rightChassis1(3, MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_ROTATIONS); //Port 3, 200 RPM gearset, not reversed, units of rotations for encoder
Motor rightChassis2(4, MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_ROTATIONS); //Port 4, 200 RPM gearset, reversed, units of rotations for encoder
Motor intake(5, MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_ROTATIONS); //Port 5, 200 RPM gearset, not reversed, units of rotations for encoder
Motor shooter(6, MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_ROTATIONS); //Port 6, 200 RPM gearset, not reversed, units of rotations for encoder

Vision shooterEye(7); //Port 7, vision sensor for shooter

ADIDigitalOut intakeLift(1); //Port 1, solonoid for raising intake
ADIDigitalOut chassisTransmission(2); //Port 2, solonoid for transmission in the chassis
ADIDigitalOut tipper(3); //Port 3, solonoid for tipping high caps

ADIAnalogIn ballSensor(4); //Port 7, light sensor for the ball