#include "main.h"
 
void moveLeftChassis(int speed) {

    leftChassis1.move(speed);
    leftChassis2.move(speed);
    leftChassis3.move(speed);

}

void moveRightChassis(int speed) {

    rightChassis1.move(speed);
    rightChassis2.move(speed);
    rightChassis3.move(speed);

}

void move_absoluteLeftChassis(int distance, int maxSpeed) {

    leftChassis1.move_absolute(distance, maxSpeed);
    leftChassis2.move_absolute(distance, maxSpeed);
    leftChassis3.move_absolute(distance, maxSpeed);

}

void move_absoluteRightChassis(int distance, int maxSpeed) {

    rightChassis1.move_absolute(distance, maxSpeed);
    rightChassis2.move_absolute(distance, maxSpeed);
    rightChassis3.move_absolute(distance, maxSpeed);

}

void move_relativeLeftChassis(int distance, int maxSpeed) {

    leftChassis1.move_relative(distance, maxSpeed);
    leftChassis2.move_relative(distance, maxSpeed);
    leftChassis3.move_relative(distance, maxSpeed);

}

void move_relativeRightChassis(int distance, int maxSpeed) {

    rightChassis1.move_relative(distance, maxSpeed);
    rightChassis2.move_relative(distance, maxSpeed);
    rightChassis3.move_relative(distance, maxSpeed);

}

void move_velocityLeftChassis(int rpm) {

    leftChassis1.move_velocity(rpm);
    leftChassis2.move_velocity(rpm);
    leftChassis3.move_velocity(rpm);

}

void move_velocityRightChassis(int rpm) {

    rightChassis1.move_velocity(rpm);
    rightChassis2.move_velocity(rpm);
    rightChassis3.move_velocity(rpm);

}

void move_voltageLeftChassis(int voltage) {

    leftChassis1.move_voltage(voltage);
    leftChassis2.move_voltage(voltage);
    leftChassis3.move_voltage(voltage);

}

void move_voltageRightChassis(int voltage) {

    rightChassis1.move_voltage(voltage);
    rightChassis2.move_voltage(voltage);
    rightChassis3.move_voltage(voltage);

}

float getLeftChassisPosition() {

    return (leftChassis1.get_position() + leftChassis2.get_position() + leftChassis3.get_position())/3;

}

float getRightChassisPosition() {

    return (rightChassis1.get_position() + rightChassis2.get_position() + rightChassis3.get_position())/3;
    
}