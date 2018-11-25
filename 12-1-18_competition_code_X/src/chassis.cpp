#include "main.h"


void driveLeft(int speed) {

    leftChassis1.move(speed);
    leftChassis2.move(speed);

}

void driveRight(int speed) {

    rightChassis1.move(speed);
    rightChassis2.move(speed);

}

void driveVelocityLeft(int rpm) {

    leftChassis1.move_velocity(rpm);
    leftChassis2.move_velocity(rpm);

}

void driveVelocityRight(int rpm) {

    rightChassis1.move_velocity(rpm);
    rightChassis2.move_velocity(rpm);

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

void driveVoltLeft(int voltage) {

    leftChassis1.move_voltage(voltage);
    leftChassis2.move_voltage(voltage);

}

void driveVoltRight(int voltage) {

    rightChassis1.move_voltage(voltage);
    rightChassis2.move_voltage(voltage);

}

void pvitChassis(float angle, int maxSpeed, int timer) {

    angle = angle * Pi * 2.34 / 180;
    
    for(int x; x < timer; x++){

        driveRelativeRight(angle, maxSpeed);
        driveRelativeLeft(-angle, maxSpeed);

        delay(1);
    }
}

float getLeftChassisPosition() {

    return (leftChassis1.get_position() + leftChassis2.get_position())/2;

}

float getRightChassisPosition() {

    return (rightChassis1.get_position() + rightChassis2.get_position())/2;
    
}

void drivePD(float setPoint, int time) {

    setPoint = -setPoint;

    float distError, distDerivative, distPrevError, distSpeed, kDistP = 9000, kDistD = 0;
    float diffError, diffDerivative, diffPrevError, diffSpeed, kDiffP = 9000, kDiffD = 0;

    resetChassisEncoderValue();

    for(int i = 0; i < abs(time); i++) {

        distError = setPoint - ((getLeftChassisPosition() + getRightChassisPosition()) / 2.0);
        distDerivative = distError - distPrevError;
        distPrevError = distError;
        distSpeed = (kDistP * distError) + (kDistD * distDerivative);

        diffError = (getLeftChassisPosition() - getRightChassisPosition()) / 2.0;
        diffDerivative = diffError - diffPrevError;
        diffPrevError = diffError;
        diffSpeed = (kDiffP * diffError) + (kDiffD * diffDerivative);

        driveVoltLeft(distSpeed - diffSpeed);
        driveVoltRight(distSpeed + diffSpeed);

        delay(1);

    }

    driveVoltLeft(0);
    driveVoltRight(0);

}

void pvitPD(int angle, int time){

    float setPoint = angle * 0.011;
    float distError, distDerivative, distPreError, distSpeed, kPDist = 0, kDDist = 0;
    float diffError, diffDerivative, diffPreError, diffSpeed, kPDiff = 0, kDDiff = 0;

    for(int i = 0; i < time; i++){

        distError = setPoint - abs((leftChassis1.get_position() + leftChassis2.get_position() - rightChassis1.get_position() - rightChassis2.get_position())/4);
        distDerivative = distError - distPreError;
        distPreError = distError;
        distSpeed = (distError * kPDist) + (distDerivative * kDDist);

        diffError = (leftChassis1.get_position() + leftChassis2.get_position() + rightChassis1.get_position() + rightChassis2.get_position()) / 4;
        diffDerivative = diffError - diffPreError;
        diffPreError = diffError;
        diffSpeed = (diffError * kPDiff) + (diffDerivative * kDDiff);

        driveVoltLeft(distSpeed - diffSpeed);
        driveVoltRight(distSpeed + diffSpeed);

        delay(1);

    }

}

void aimFlag() {

    int kP = 55;

    if(abs(shooterEye.get_by_size(0).x_middle_coord) > 320) {

        driveVoltLeft(0);
        driveVoltRight(0);

    }

    else {

        while((abs(shooterEye.get_by_size(0).x_middle_coord) >= 5) && abs(shooterEye.get_by_size(0).x_middle_coord) > 320) {

            driveVoltLeft(kP * (shooterEye.get_by_size(0).x_middle_coord));
            driveVoltRight(kP * (shooterEye.get_by_size(0).x_middle_coord) * -1);

        }

        driveVoltLeft(0);
        driveVoltRight(0);

    }

    master.rumble("-");

}

void AutonAimFlag() {

    int error, kP = 55, beforePosition;

    if(abs(shooterEye.get_by_size(0).x_middle_coord) > 320) {

        driveVoltLeft(0);
        driveVoltRight(0);

    }

    else {

        beforePosition = shooterEye.get_by_size(0).x_middle_coord;

        while((abs(shooterEye.get_by_size(0).x_middle_coord) >= 5) && abs(shooterEye.get_by_size(0).x_middle_coord) > 320) {

            driveVoltLeft(kP * (shooterEye.get_by_size(0).x_middle_coord));
            driveVoltRight(kP * (shooterEye.get_by_size(0).x_middle_coord) * -1);

        }

        driveVoltLeft(0);
        driveVoltRight(0);
        shooter.move(127);
        delay(200);

        while(!shooterBtn.get_value()){}
        
        shooter.move(0);

        while((abs(beforePosition - shooterEye.get_by_size(0).x_middle_coord) >= 5) && abs(shooterEye.get_by_size(0).x_middle_coord) > 320) {

            error = shooterEye.get_by_size(0).x_middle_coord - beforePosition;

            driveVoltLeft(kP * (error));
            driveVoltRight(kP * (error) * -1);

        }

        driveVoltLeft(0);
        driveVoltRight(0);

    }

}

void resetChassisEncoderValue() {

    leftChassis1.tare_position();
    leftChassis2.tare_position();
    rightChassis1.tare_position();
    rightChassis2.tare_position();

}