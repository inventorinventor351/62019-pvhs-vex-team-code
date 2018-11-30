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

    move_relativeLeftChassis((angle * 0.385 * -1), abs(maxSpeed));
    move_relativeRightChassis((angle * 0.375), abs(maxSpeed));

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

    float distError, distDerivative, distPrevError, distSpeed, leftSpeed, kDistP = 11700, kDistD = 0;
    float diffError, diffDerivative, diffPrevError, diffSpeed, rightSpeed, kDiffP = 317500, kDiffD = 11000;
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

    float distError, distDerivative, distPrevError, distSpeed, kDistP = 1000, kDistD = 0;
    float diffError, diffDerivative, diffPrevError, diffSpeed, kDiffP = 1, kDiffD = 1;

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

    int kP = 55, i = 0, boi;

    if(abs(catapultEye.get_by_size(0).x_middle_coord) > 320) {

        move_voltageLeftChassis(0);
        move_voltageRightChassis(0);
        std::cout << "DID NOT FIND ANYTHING\n";
        std::cout << "DID NOT FIND ANYTHING\n";

    }

    else{
        
        if(autonCount < 4)
        boi = 10;
        else
        boi = -10;

        while((abs(catapultEye.get_by_size(0).x_middle_coord - boi) > 1) && (i < 2500)){

            move_voltageLeftChassis(kP * (catapultEye.get_by_size(0).x_middle_coord - boi));
            move_voltageRightChassis(kP * (catapultEye.get_by_size(0).x_middle_coord - boi) * -1);
            std::cout << catapultEye.get_by_size(0).x_middle_coord - boi << "\n";
            i++;
            delay(1);

        }
    
    }

    move_voltageLeftChassis(0);
    move_voltageRightChassis(0);
    master.rumble("-");

}

void autonShoot() {

    int kP = 55, i = 0, boi;

    if(abs(catapultEye.get_by_size(0).x_middle_coord) > 320) {

        move_voltageLeftChassis(0);
        move_voltageRightChassis(0);
        std::cout << "DID NOT FIND ANYTHING\n";
        std::cout << "DID NOT FIND ANYTHING\n";

    }

    else{
        
        if(autonCount < 4)
            boi = 20;
        else
            boi = -20;

        while((abs(catapultEye.get_by_size(0).x_middle_coord - boi) > 1) && (i < 2500)){

            move_voltageLeftChassis(kP * (catapultEye.get_by_size(0).x_middle_coord - boi));
            move_voltageRightChassis(kP * (catapultEye.get_by_size(0).x_middle_coord - boi) * -1);
            std::cout << catapultEye.get_by_size(0).x_middle_coord - boi << "\n";
            i++;
            delay(1);

        }

        move_voltageLeftChassis(0);
        move_voltageRightChassis(0);

        /*catapult.move(127);
        delay(350);

        while(!catabut.get_value())
            catapult.move(90);
        
        catapult.move(0);*/

        std::cout << "DONE AIMING\n";
        std::cout << "DONE AIMING\n";

    }

    std::cout << "SIMPLY DONE\n";
    std::cout << "SIMPLY DONE\n";

}

void autonGetBall(int dist) {

    driveStraight(1.8, 1200);
    intake.move_velocity(500);
    driveStraight(0.59, 800);
    delay(375);
    driveStraight(dist, 1000);
    loadBall(800);
    intake.move_velocity(0);

}