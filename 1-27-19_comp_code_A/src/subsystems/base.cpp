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
    rightBase3.move_absolute(distance, maxSpeed);

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


void pvitBase(int angle, int maxSpeed) {

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

float Pi = 3.1415926535897932384;

float rotToIn(float Rotations) 
{
    return (Rotations * 41.41 * Pi);
}

float inToRot(float Inches)
{
    return (Inches / 2.475 / Pi);
}

float inToRotHS(float Inches)
{
    return (Inches / 5.775 / Pi);
}

void drivePD(float setPoint) {

    float distError, distDerivative, distPrevError, distSpeed, kDistP = 11700, kDistD = 0;
    float diffError, diffDerivative, diffPrevError, diffSpeed, kDiffP = 317500, kDiffD = 11000;
    float leftSpeed = 1200, rightSpeed = 1200;

    resetBaseEncoderValue();

    while(abs(leftSpeed) > 1000) {

        distError = setPoint - ((getLeftChassisPosition() + getRightChassisPosition()) / 2.0);
        distDerivative = distError - distPrevError;
        distPrevError = distError;
        distSpeed = (kDistP * distError) + (kDistD * distDerivative);

        diffError = (getLeftChassisPosition() - getRightChassisPosition()) / 2.0;
        diffDerivative = diffError - diffPrevError;
        diffPrevError = diffError;
        diffSpeed = (kDiffP * diffError) + (kDiffD * diffDerivative);

        leftSpeed = distSpeed - diffSpeed;
        rightSpeed = distSpeed + diffSpeed;

        runLeftBase(rightSpeed > 12000 ? 12000 : rightSpeed);
        runRightBase(leftSpeed > 12000 ? 12000 : leftSpeed);

        delay(1);

    }

    runLeftBase(0);
    runRightBase(0);

}

void resetBaseEncoderValue() {

    leftBase1.tare_position();
    leftBase2.tare_position();
    leftBase3.tare_position();
    rightBase1.tare_position();
    rightBase2.tare_position();
    rightBase3.tare_position();

    

}

void driveDist(int dist, int speed){

    resetBaseEncoderValue();

     leftBase1.tare_position();
    leftBase2.tare_position();
    leftBase3.tare_position();
    rightBase1.tare_position();
    rightBase2.tare_position();
    rightBase3.tare_position();

    dist = dist * 360;

     while(abs(leftBase1.get_position()) < dist && abs(rightBase1.get_position()) < dist) {

        driveVelocityLeft(speed);
        driveVelocityRight(speed);

    }

    driveVelocityLeft(0);
    driveVelocityRight(0);

    resetBaseEncoderValue();

}