#include "main.h"

Motor leftChassis1(1, MOTOR_GEARSET_18, 0, MOTOR_ENCODER_DEGREES); //Port 1, 200 RPM, not reversed, degrees for encoder units
Motor leftChassis2(2, MOTOR_GEARSET_18, 0, MOTOR_ENCODER_DEGREES); //Port 2, 200 RPM, not reversed, degrees for encoder units
Motor leftChassis3(3, MOTOR_GEARSET_18, 0, MOTOR_ENCODER_DEGREES); //Port 3, 200 RPM, not reversed, degrees for encoder units
Motor rightChassis1(4, MOTOR_GEARSET_18, 1, MOTOR_ENCODER_DEGREES); //Port 4, 200 RPM, reversed, degrees for encoder units
Motor rightChassis2(5, MOTOR_GEARSET_18, 1, MOTOR_ENCODER_DEGREES); //Port 5, 200 RPM, reversed, degrees for encoder units
Motor rightChassis3(6, MOTOR_GEARSET_18, 1, MOTOR_ENCODER_DEGREES); //Port 6, 200 RPM, reversed, degrees for encoder units
Motor intake(7, MOTOR_GEARSET_18, 0, MOTOR_ENCODER_DEGREES); //Port 7, 200 RPM, not reversed, degrees for encoder units
Motor catapult(8, MOTOR_GEARSET_36, 0, MOTOR_ENCODER_DEGREES); //Port 8, 100 RPM, not reversed, degrees for encoder units