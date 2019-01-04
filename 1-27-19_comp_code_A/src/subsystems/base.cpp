#include "main.h"

void runLeftBase(float voltPerc) {

    leftBase1.move_voltage((voltPerc / 100) * 12000);
    leftBase2.move_voltage((voltPerc / 100) * 12000);
    leftBase3.move_voltage((voltPerc / 100) * 12000);

}

void runRightBase(float voltPerc) {

    rightBase1.move_voltage((voltPerc / 100) * 12000);
    rightBase2.move_voltage((voltPerc / 100) * 12000);
    rightBase3.move_voltage((voltPerc / 100) * 12000);

}



void driveLeft(int speed) {

    leftBase1.move(speed);
    leftBase2.move(speed);
    leftBase3.move(speed);

}

void driveRight(int speed) {

    rightBase1.move(speed);
    rightBase2.move(speed);
    rightBase3.move(speed);

}

void driveVelocityLeft(int rpm) {

    leftBase1.move_velocity(rpm);
    leftBase2.move_velocity(rpm);
    leftBase3.move_velocity(rpm);

}

void driveVelocityRight(int rpm) {

    rightBase1.move_velocity(rpm);
    rightBase2.move_velocity(rpm);
    rightBase3.move_velocity(rpm);

}

void driveAbsLeft(float distance, int maxSpeed) {

    distance = inToRot(distance);
    leftBase1.move_absolute(distance, maxSpeed);
    leftBase2.move_absolute(distance, maxSpeed);
    leftBase3.move_absolute(distance, maxSpeed);

}

void driveAbsRight(float distance, int maxSpeed) {

    distance = inToRot(distance);
    rightBase1.move_absolute(distance, maxSpeed);
    rightBase2.move_absolute(distance, maxSpeed);
    rightBase3.move_absolute)distance, maxSpeed);

}

void driveRelativeLeft(float distance, int maxSpeed) {

    leftBase1.move_relative(distance, maxSpeed);
    leftBase2.move_relative(distance, maxSpeed);
    leftBase3.move_relative(distance, maxSpeed);

}

void driveRelativeRight(float distance, int maxSpeed) {

    rightBase1.move_relative(distance, maxSpeed);
    rightBase2.move_relative(distance, maxSpeed);
    rightBase3.move_relative(distance, maxSpeed);

}


void pvitChassis(int angle, int maxSpeed) {

    float distance = angle * Pi / 440;

    driveRelativeRight(distance, maxSpeed);
    driveRelativeLeft(-distance, maxSpeed);
    
}

float getLeftChassisPosition() {

    return (leftBase1.get_position() + leftBase2.get_position() + leftBase3.get_position())/3;

}

float getRightChassisPosition() {

    return (rightBase1.get_position() + rightBase2.get_position() + rightBase3.get_position())/3;
    
}