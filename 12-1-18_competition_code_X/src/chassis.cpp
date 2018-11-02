#include "main.h"


void driveLeft(int speed) {

    leftChassis1.move(speed);
    leftChassis2.move(speed);

}

void driveRight(int speed) {

    rightChassis1.move(speed);
    rightChassis2.move(speed);

}

void driveAbsLeft(float distance, int maxSpeed) {

    distance = inToRot(distance);
    leftChassis1.move_absolute(distance, maxSpeed);
    leftChassis2.move_absolute(distance, maxSpeed);

}

void driveAbsRight(float distance, int maxSpeed) {

    distance = inToRot(distance);
    rightChassis1.move_absolute(distance, maxSpeed);
    rightChassis2.move_absolute(distance, maxSpeed);

}

void driveRelativeLeft(float distance, int maxSpeed) {

    distance = inToRot(distance);
    leftChassis1.move_relative(distance, maxSpeed);
    leftChassis2.move_relative(distance, maxSpeed);

}

void driveRelativeRight(float distance, int maxSpeed) {

    distance = inToRot(distance);
    rightChassis1.move_relative(distance, maxSpeed);
    rightChassis2.move_relative(distance, maxSpeed);

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

    angle = angle * pi * 2.34 / 180;
    
    for(int x; x < timer; x = x + 1){

        driveRelativeRight(angle, maxSpeed);
        driveRelativeLeft(-angle, maxSpeed);

        delay(500);
    }
}

void aimFlag(){

    int comparingValue = 1000000;
    vision_object_s_t closestObject;
    int i, error_, preError_, derivative_;
    float error, preError, derivative, kP, kD;

    for(i = 0; i < shooterEye.get_object_count(); i++){

        vision_object_s_t suspect = shooterEye.get_by_size(1);

        if(comparingValue > abs(suspect.x_middle_coord)){
            
            closestObject = suspect;
            comparingValue = abs(suspect.x_middle_coord);

        }

    }

    while(!(closestObject.x_middle_coord>-5) && (closestObject.x_middle_coord<5) && (i > 1)){

        error_ = closestObject.x_middle_coord;
        derivative = preError - error;
        preError_ = error;

        driveVoltLeft((kP * error) + (kD * derivative));
        driveVoltRight(-(kP * error) + (kD * derivative));

        delay(1);

    }

    master.rumble("-");

}