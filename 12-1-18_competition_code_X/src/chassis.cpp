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

    leftChassis1.move_relative(distance, maxSpeed);
    leftChassis2.move_relative(distance, maxSpeed);

}

void driveRelativeRight(float distance, int maxSpeed) {

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

void pvitChassis(int angle, int maxSpeed) {

    float distance = angle * Pi / 440;

    driveRelativeRight(distance, maxSpeed);
    driveRelativeLeft(-distance, maxSpeed);
    
}

float getLeftChassisPosition() {

    return (leftChassis1.get_position() + leftChassis2.get_position())/2;

}

float getRightChassisPosition() {

    return (rightChassis1.get_position() + rightChassis2.get_position())/2;
    
}

void drivePD(float setPoint) {

    float distError, distDerivative, distPrevError, distSpeed, kDistP = 11700, kDistD = 0;
    float diffError, diffDerivative, diffPrevError, diffSpeed, kDiffP = 317500, kDiffD = 11000;
    float leftSpeed = 1000, rightSpeed = 1000;

    resetChassisEncoderValue();

    while(abs(leftSpeed) > 200) {

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

        driveVoltRight(rightSpeed > 12000 ? 12000 : rightSpeed);
        driveVoltLeft(leftSpeed > 12000 ? 12000 : leftSpeed);

        delay(1);

    }

    driveVoltLeft(0);
    driveVoltRight(0);

}

void pvitPD(int angle){

    float setPoint = inToRotHS(angle) / 500;
    float distError, distDerivative, distPreError, distSpeed, kPDist = 5000, kDDist = 0;
    float diffError, diffDerivative, diffPreError, diffSpeed, kPDiff = 0, kDDiff = 0;
    float leftSpeed = 1000, rightSpeed = 1000;

    resetChassisEncoderValue();

    while(abs(leftSpeed) > 200){

        distError = setPoint - (abs(getLeftChassisPosition()) - abs(getRightChassisPosition()) / 2);
        distDerivative = distError - distPreError;
        distPreError = distError;
        distSpeed = (distError * kPDist) + (distDerivative * kDDist);

        diffError = abs(getLeftChassisPosition() - getRightChassisPosition()) / 4;
        diffDerivative = diffError - diffPreError;
        diffPreError = diffError;
        diffSpeed = (diffError * kPDiff) + (diffDerivative * kDDiff);

        leftSpeed = distSpeed - diffSpeed;
        rightSpeed = distSpeed + diffSpeed;

        driveVoltLeft(leftSpeed);
        driveVoltRight(-rightSpeed);

        std::cout << getLeftChassisPosition() << ":" << leftSpeed << "\n";
        delay(1);

    }

    driveVoltLeft(0);
    driveVoltRight(0);
    std::cout << "done!\n";

}

void aimFlag() {

    int kP = 70, i = 0, shift;

    if(abs(shooterEye.get_by_size(0).x_middle_coord) > 320) {

        driveVoltLeft(0);
        driveVoltRight(0);

    }

    else{
        
        if(autonCount < 4)
        shift = 10;
        else
        shift = -10;

        while((abs(shooterEye.get_by_size(0).x_middle_coord + shift) > 1) && (i < 2500)){

            driveVoltLeft(kP * (shooterEye.get_by_size(0).x_middle_coord + shift));
            driveVoltRight(kP * (shooterEye.get_by_size(0).x_middle_coord + shift));

            i++;
            delay(1);

        }
    
    }

    driveVoltLeft(0);
    driveVoltRight(0);
    std::cout << shooterEye.get_by_size(0).x_middle_coord << "\n";
    master.rumble("-");

}

void autonAimFlag() {

    int kP = 70, i = 0, shift;

    if(abs(shooterEye.get_by_size(0).x_middle_coord) > 320) {

        driveVoltLeft(0);
        driveVoltRight(0);

    }

    else{
        
        if(autonCount < 4)
        shift = 10;
        else
        shift = -10;

        while((abs(shooterEye.get_by_size(0).x_middle_coord - shift) > 1) && (i < 2500)){

            driveVoltLeft(kP * (shooterEye.get_by_size(0).x_middle_coord - shift));
            driveVoltRight(kP * (shooterEye.get_by_size(0).x_middle_coord - shift) * -1);

            i++;
            delay(1);

        }
    
    }

    driveVoltLeft(0);
    driveVoltRight(0);
    shooter.move(127);
    delay(300);
    while(!shooterBtn.get_value())
    shooter.move(90);

    shooter.move(0);

}

void resetChassisEncoderValue() {

    leftChassis1.tare_position();
    leftChassis2.tare_position();
    rightChassis1.tare_position();
    rightChassis2.tare_position();
    

}