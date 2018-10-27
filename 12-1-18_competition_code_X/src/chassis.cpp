#include "main.h"


void driveLeft(int speed) {

    leftChassis1.move(speed);
    leftChassis2.move(speed);

}

void driveRight(int speed) {

    rightChassis1.move(speed);
    rightChassis2.move(speed);

}

void driveAbsLeft(int distance, int maxSpeed) {

    leftChassis1.move_absolute(distance);
    leftChassis2.move_absolute(distance);

}

void driveAbsRight(int distance, int maxSpeed) {

    rightChassis1.move_absolute(distance);
    rightChassis2.move_absolute(distance);

}

void driveRelativeLeft(int distance, int maxSpeed) {

    leftChassis1.move_relative(distance);
    leftChassis2.move_relative(distance);

}

void driveRelativeRight(int distance, int maxSpeed) {

    rightChassis1.move_relative(distance);
    rightChassis2.move_relative(distance);

}

void driverpmLeft(int rpm) {

    leftChassis1.move_velocity(rpm);
    leftChassis2.move_velocity(rpm);

}

void driverpmRight(int rpm) {

    rightChassis1.move_velocity(rpm);
    rightChassis2.move_velocity(rpm);
}

void driveVoltLeft(int voltage) {

    leftChassis1.move_voltage(voltage);
    leftChassis2.move_voltage(voltage);

}

void driveVoltRight(int voltage) {

    rightChassis1.move_voltage(voltage);
    rightChassis2.move_voltage(voltage);

}

void pvitChassis(float angle, int maxSpeed, int timer) {

    for(int x, x < timer, x = x + 1){

        driveRelativeRight(angle * 2.34, maxSpeed);
        driveRelativeLeft(-angle * 2.34, maxSpeed);

        delay(500)

    }

void aimFlag(){

    int comparingValue = 1000000;
    vision_object_s_t closestID;
    int error_, preError_, derivative_)

    for(int i = 0, i < shooterEye.get_object_count, i++)
    {

        vision_object_s_t suspect = shooterEye.get_by_size(1);

        if(comparingValue > abs(suspect.x_middle_coord))
        {
            closestObject = suspect;
            comparingValue = abs(suspect.x_middle_coord);
        }

    }

    while((closestObject.x_middle_coord>-5) && (closestObject.x_middle_coord<5) && (i > 1))
    {

        error_ = closestObject.x_middle_coord;
        derivative = preError - error
        preError_ = error

        driveVoltLeft((kP * error) + (kD * derivative));
        driveVoltRight(-(kP * error) + (kD * derivative));

    }

}