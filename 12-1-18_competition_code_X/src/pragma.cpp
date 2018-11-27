#include "main.h"

Controller master(E_CONTROLLER_MASTER); //Master Controller

Motor leftChassis1(1, MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_ROTATIONS); //Port 1, 200 RPM gearset, reversed, units of rotations for encoder
Motor leftChassis2(2, MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_ROTATIONS); //Port 2, 200 RPM gearset, not reversed, units of rotations for encoder
Motor rightChassis1(3, MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_ROTATIONS); //Port 3, 200 RPM gearset, not reversed, units of rotations for encoder
Motor rightChassis2(4, MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_ROTATIONS); //Port 4, 200 RPM gearset, reversed, units of rotations for encoder
Motor shooter(5, MOTOR_GEARSET_36, 0, E_MOTOR_ENCODER_ROTATIONS); //Port 5, 100 RPM gearset, not reversed, units of rotations for encoder
Motor intake(6, MOTOR_GEARSET_6, 0, E_MOTOR_ENCODER_ROTATIONS); //Port 6, 600 RPM gearset, not reversed, units of rotations for encoder

Vision shooterEye(7); //Port 7, vision sensor for shooter

ADIDigitalOut intakeLift(2); //Port 1, solonoid for raising intake
ADIDigitalOut intakeLiftCap(3); //Port 2, supports first intakeLift when lifting caps
ADIDigitalOut chassisTransmission(4); //Port 3, solonoid for transmission in the chassis

ADIDigitalIn capSensor(5); //Port 4, limit switch that determines 1 or 2 pistons for the intake lift
ADIDigitalIn shooterBtn(6); //Port 5, button for stopping the shooter motor