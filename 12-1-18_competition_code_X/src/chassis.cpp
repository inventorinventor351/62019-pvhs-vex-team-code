#include "main.h"

Motor leftChassis1(1, MOTOR_GEARSET_18, 0, MOTOR_ENCODER_DEGREES); //Port 1, 200 RPM, not reversed, degrees for encoder units
Motor leftChassis2(2, MOTOR_GEARSET_18, 0, MOTOR_ENCODER_DEGREES); //Port 2, 200 RPM, not reversed, degrees for encoder units
Motor leftChassis3(3, MOTOR_GEARSET_18, 0, MOTOR_ENCODER_DEGREES); //Port 3, 200 RPM, not reversed, degrees for encoder units
Motor rightChassis1(4, MOTOR_GEARSET_18, 1, MOTOR_ENCODER_DEGREES); //Port 4, 200 RPM, reversed, degrees for encoder units
Motor rightChassis2(5, MOTOR_GEARSET_18, 1, MOTOR_ENCODER_DEGREES); //Port 5, 200 RPM, reversed, degrees for encoder units
Motor rightChassis3(6, MOTOR_GEARSET_18, 1, MOTOR_ENCODER_DEGREES); //Port 6, 200 RPM, reversed, degrees for encoder units
 
void driveLeft(int speed) {

    leftChassis1.move(speed);
    leftChassis2.move(speed);
    leftChassis3.move(speed);

}

void driveRight(int speed) {

    rightChassis1.move(speed);
    rightChassis2.move(speed);
    rightChassis3.move(speed);

}

void driveabsLeft(int distance) {

    leftChassis1.move_absolute(distance);
    leftChassis2.move_absolute(distance);
    leftChassis3.move_absolute(distance);

}

void driveabsRight(int distance) {

    rightChassis1.move_absolute(distance);
    rightChassis2.move_absolute(distance);
    rightChassis3.move_absolute(distance);

}

void driveRelativeLeft(int distance) {

    leftChassis1.move_relative(distance);
    leftChassis2.move_relative(distance);
    leftChassis3.move_relative(distance);

}

void driveRelativeRight(int distance) {

    rightChassis1.move_relative(distance);
    rightChassis2.move_relative(distance);
    rightChassis3.move_relative(distance);

}

void driverpmLeft(int rpm) {

    leftChassis1.move_velocity(rpm);
    leftChassis2.move_velocity(rpm);
    leftChassis3.move_velocity(rpm);

}

void driverpmRight(int rpm) {

    rightChassis1.move_velocity(rpm);
    rightChassis2.move_velocity(rpm);
    rightChassis3.move_velocity(rpm);

}

void driveVoltLeft(int voltage) {

    leftChassis1.move_voltage(voltage);
    leftChassis2.move_voltage(voltage);
    leftChassis3.move_voltage(voltage);

}

void driveVoltRight(int voltage) {

    rightChassis1.move_voltage(voltage);
    rightChassis2.move_voltage(voltage);
    rightChassis3.move_voltage(voltage);

}