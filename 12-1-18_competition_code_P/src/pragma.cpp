#include "main.h"

Motor leftChassis1(1, MOTOR_GEARSET_18, 0, MOTOR_ENCODER_ROTATIONS); //Port 1, 200 RPM, not reversed, rotations for encoder units
Motor leftChassis2(2, MOTOR_GEARSET_18, 0, MOTOR_ENCODER_ROTATIONS); //Port 2, 200 RPM, not reversed, rotations for encoder units
Motor leftChassis3(3, MOTOR_GEARSET_18, 0, MOTOR_ENCODER_ROTATIONS); //Port 3, 200 RPM, not reversed, rotations for encoder units
Motor rightChassis1(4, MOTOR_GEARSET_18, 1, MOTOR_ENCODER_ROTATIONS); //Port 4, 200 RPM, reversed, rotations for encoder units
Motor rightChassis2(5, MOTOR_GEARSET_18, 1, MOTOR_ENCODER_ROTATIONS); //Port 5, 200 RPM, reversed, rotations for encoder units
Motor rightChassis3(6, MOTOR_GEARSET_18, 1, MOTOR_ENCODER_ROTATIONS); //Port 6, 200 RPM, reversed, rotations for encoder units
Motor intake(7, MOTOR_GEARSET_18, 0, MOTOR_ENCODER_COUNTS); //Port 7, 200 RPM, not reversed, ticks for encoder units
Motor catapult(8, MOTOR_GEARSET_36, 0, MOTOR_ENCODER_COUNTS); //Port 8, 100 RPM, not reversed, ticks for encoder units

ADIAnalogIn catapultPotent(1); //potentiometer for catapult in port 1 of the legacy ports
ADIAnalogIn ballLoaderSensor(2); //light sensor to detect a ball going into the catapult in port 2 of the legacy ports
Vision catapultEye(9); //vision sensor for catapult in port 11