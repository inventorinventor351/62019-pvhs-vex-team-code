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

    return (leftChassis1.get_position() + leftChassis2.get_position())/2;

}

float getRightChassisPosition() {

    return (rightChassis1.get_position() + rightChassis2.get_position())/2;
    
}

void pivotChassis(float angle, int maxSpeed, int time) {

    angle *= (3.14159265358979323846 / 180.0);

    move_relativeLeftChassis((angle * 2.34 * -1), abs(maxSpeed));
    move_relativeRightChassis((angle * 2.34), abs(maxSpeed));

    for(int i = 0; i < abs(time); i++) {

        delay(1);

    }

}

void aimAtFlag(float kP_, float kD_) {

    int smallestValue = 321;
    vision_object_s_t closestObject;

    int error_, derivative_, prevError_;

    for(int i = 0; i < catapultEye.get_object_count(); i++) {

        vision_object_s_t currentObject = catapultEye.get_by_size(i);

        if(smallestValue > abs(currentObject.x_middle_coord)) {

            smallestValue = abs(currentObject.x_middle_coord);
            closestObject = currentObject;

        }

    }

    while((!((-5 <= closestObject.x_middle_coord) && (closestObject.x_middle_coord <= 5))) && (catapultEye.get_object_count() > 0)) {

        error_ = closestObject.x_middle_coord;
        derivative_ = error_ - prevError_;
        prevError_ = error_;

        move_voltageLeftChassis((kP_ * error_) + (kD_ * derivative_));
        move_voltageRightChassis(((kP_ * error_) + (kD_ * derivative_)) * -1);

        delay(1);
        
    }

    master.rumble("-");

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


void autonShoot(float kP_, float kD_) {

    int smallestValue = 321;
    vision_object_s_t closestObject;

    int error_, derivative_, prevError_;

    for(int i = 0; i < catapultEye.get_object_count(); i++) {

        vision_object_s_t currentObject = catapultEye.get_by_size(i);

        if(smallestValue > abs(currentObject.x_middle_coord)) {

            smallestValue = abs(currentObject.x_middle_coord);
            closestObject = currentObject;

        }

    }

    int beforeposition = closestObject.x_middle_coord;

    while((!((-5 <= closestObject.x_middle_coord) && (closestObject.x_middle_coord <= 5))) && (catapultEye.get_object_count() > 0)) {

        error_ = closestObject.x_middle_coord;
        derivative_ = error_ - prevError_;
        prevError_ = error_;

        move_voltageLeftChassis((kP_ * error_) + (kD_ * derivative_));
        move_voltageRightChassis(((kP_ * error_) + (kD_ * derivative_)) * -1);

        delay(1);
        
    }

    intake.move_relative(1, 200);

    error_ = 0;
    derivative_ = 0;
    prevError_ = 0;
    
    while((!((-5 <= closestObject.x_middle_coord) && (closestObject.x_middle_coord <= 5))) && (catapultEye.get_object_count() > 0)) {

        error_ = beforeposition - closestObject.x_middle_coord;
        derivative_ = error_ - prevError_;
        prevError_ = error_;

        move_voltageRightChassis((kP_ * error_) + (kD_ * derivative_));
        move_voltageLeftChassis(((kP_ * error_) + (kD_ * derivative_)) * -1);

        delay(1);
        
    }



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