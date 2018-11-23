#include "main.h"
 
void moveLeftChassis(int speed) {

    leftChassis1.move(speed);
    leftChassis2.move(speed);
  

}

void moveRightChassis(int speed) {

    rightChassis1.move(speed);
    rightChassis2.move(speed);


}

void move_absoluteLeftChassis(float distance, int maxSpeed) {

    leftChassis1.move_absolute(distance, abs(maxSpeed));
    leftChassis2.move_absolute(distance, abs(maxSpeed));


}

void move_absoluteRightChassis(float distance, int maxSpeed) {

    rightChassis1.move_absolute(distance, abs(maxSpeed));
    rightChassis2.move_absolute(distance, abs(maxSpeed));
  

}

void move_relativeLeftChassis(float distance, int maxSpeed) {

    leftChassis1.move_relative(distance, abs(maxSpeed));
    leftChassis2.move_relative(distance, abs(maxSpeed));
   

}

void move_relativeRightChassis(float distance, int maxSpeed) {

    rightChassis1.move_relative(distance, abs(maxSpeed));
    rightChassis2.move_relative(distance, abs(maxSpeed));
  

}

void move_velocityLeftChassis(int rpm) {

    leftChassis1.move_velocity(rpm);
    leftChassis2.move_velocity(rpm);
 

}

void move_velocityRightChassis(int rpm) {

    rightChassis1.move_velocity(rpm);
    rightChassis2.move_velocity(rpm);


}

void move_voltageLeftChassis(int voltage) {

    leftChassis1.move_voltage(voltage);
    leftChassis2.move_voltage(voltage);


}

void move_voltageRightChassis(int voltage) {

    rightChassis1.move_voltage(voltage);
    rightChassis2.move_voltage(voltage);


}

float getLeftChassisPosition() {

    //return (leftChassis1.get_position() + leftChassis2.get_position())/2;
    return leftChassis1.get_position();

}

float getRightChassisPosition() {

    //return (rightChassis1.get_position() + rightChassis2.get_position())/2;
    return leftChassis1.get_position();
    
}

void pivotChassisBAD(float angle, int maxSpeed, int time) {

    angle *= (3.14159265358979323846 / 180.0);

    move_relativeLeftChassis((angle * 0.64 * -1), abs(maxSpeed));
    move_relativeRightChassis((angle * 0.64), abs(maxSpeed));

    for(int i = 0; i < abs(time); i++) {

        delay(1);

    }

}

void resetLeftChassisEncoderValue() {

    leftChassis1.tare_position();
    leftChassis2.tare_position();

}

void resetRightChassisEncoderValue() {

    rightChassis1.tare_position();
    rightChassis2.tare_position();
    
}

void resetChassisEncoderValue() {

    resetLeftChassisEncoderValue();
    resetRightChassisEncoderValue();
}

void driveChassisAbs(int dist, int speed) {
    move_absoluteRightChassis(inToRot(dist), speed);
    move_absoluteLeftChassis(inToRot(dist), speed);
}

void driveChassisRelative(int dist , int speed){
    move_relativeLeftChassis(inToRot(dist), speed);
    move_relativeRightChassis(inToRot(dist), speed);
}

void driveChassisVoltage(int time, int voltage){
    move_voltageLeftChassis(voltage);
    move_voltageRightChassis(voltage);
    delay(time);
    move_velocityLeftChassis(0);
    move_velocityRightChassis(0);
}

void driveStraight(float setPoint, int time) {

    float distError, distDerivative, distPrevError, distSpeed, leftSpeed, kDistP = 9000, kDistD = 0;
    float diffError, diffDerivative, diffPrevError, diffSpeed, rightSpeed, kDiffP = 13000, kDiffD = 11000;
    float maxSpeed = 12001;

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

        leftSpeed = distSpeed - diffSpeed;
        rightSpeed = distSpeed + diffSpeed;

        move_voltageLeftChassis(leftSpeed > maxSpeed ? maxSpeed : leftSpeed);
        move_voltageRightChassis(rightSpeed > maxSpeed ? maxSpeed : rightSpeed);

        delay(1);

    }

    move_voltageLeftChassis(0);
    move_voltageRightChassis(0);

}

void pivotChassis(int angle, int time) {

    float setPoint = angle * 0.011;

    float distError, distDerivative, distPrevError, distSpeed, kDistP = 100, kDistD = 1;
    float diffError, diffDerivative, diffPrevError, diffSpeed, kDiffP = 100, kDiffD = 1;

    for(int i = 0; i < abs(time); i++) {

        distError = setPoint - abs((getLeftChassisPosition() - getRightChassisPosition()) / 2.0);
        distDerivative = distError - distPrevError;
        distPrevError = distError;
        distSpeed = (kDistP * distError) + (kDistD * distDerivative);

        diffError = (getLeftChassisPosition() + getRightChassisPosition()) / 2.0;
        diffDerivative = diffError - diffPrevError;
        diffPrevError = diffError;
        diffSpeed = (kDiffP * diffError) + (kDiffD * diffDerivative);

        move_voltageLeftChassis((-distSpeed) + diffSpeed);
        move_voltageRightChassis(distSpeed - diffSpeed);

        delay(1);

    }

    move_voltageLeftChassis(0);
    move_voltageRightChassis(0);

}

void aimAtFlag() {

    vision_object_s_t target;
    int lowestScore = 321, range = 5;
    int error = 0, kP = 100;

    for(int i = 0; i < catapultEye.get_object_count(); i++) {

        vision_object_s_t suspect = catapultEye.get_by_size(i);

        if(abs(suspect.x_middle_coord) < lowestScore) {

            lowestScore = abs(suspect.x_middle_coord);
            target = suspect;

        }

    }

    while(abs(target.x_middle_coord) > range) {

        error = target.x_middle_coord;

        move_voltageLeftChassis(kP * error);
        move_voltageRightChassis(kP * error * -1);

    }

    move_voltageLeftChassis(0);
    move_voltageRightChassis(0);

    master.rumble("-");

}

void autonShoot() {

    vision_object_s_t target;
    int lowestScore = 321, range = 5;
    int error = 0, kP = 100;

    for(int i = 0; i < catapultEye.get_object_count(); i++) {

        vision_object_s_t suspect = catapultEye.get_by_size(i);

        if(abs(suspect.x_middle_coord) < lowestScore) {

            lowestScore = abs(suspect.x_middle_coord);
            target = suspect;

        }

    }

    int beforePosition = target.x_middle_coord;

    while(abs(target.x_middle_coord) > range) {

        error = target.x_middle_coord;

        move_voltageLeftChassis(kP * error);
        move_voltageRightChassis(kP * error * -1);

    }

    move_voltageLeftChassis(0);
    move_voltageRightChassis(0);

    catapult.move_relative(3, 200);
    delay(100);
    error = 0;

    while(abs(beforePosition - target.x_middle_coord) > range) {

        error = target.x_middle_coord - beforePosition;

        move_voltageLeftChassis(kP * error);
        move_voltageRightChassis(kP * error * -1);

    }

    move_voltageLeftChassis(0);
    move_voltageRightChassis(0);

}