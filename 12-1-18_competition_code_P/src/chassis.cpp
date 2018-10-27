#include "main.h"
 
void moveLeftChassis(int speed) {

    leftChassis1.move(speed);
    leftChassis2.move(speed);
  

}

void moveRightChassis(int speed) {

    rightChassis1.move(speed);
    rightChassis2.move(speed);


}

void move_absoluteLeftChassis(int distance, int maxSpeed) {

    leftChassis1.move_absolute(distance, maxSpeed);
    leftChassis2.move_absolute(distance, maxSpeed);


}

void move_absoluteRightChassis(int distance, int maxSpeed) {

    rightChassis1.move_absolute(distance, maxSpeed);
    rightChassis2.move_absolute(distance, maxSpeed);
  

}

void move_relativeLeftChassis(int distance, int maxSpeed) {

    leftChassis1.move_relative(distance, maxSpeed);
    leftChassis2.move_relative(distance, maxSpeed);
   

}

void move_relativeRightChassis(int distance, int maxSpeed) {

    rightChassis1.move_relative(distance, maxSpeed);
    rightChassis2.move_relative(distance, maxSpeed);
  

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

    move_relativeLeftChassis((angle * 2.34 * -1), maxSpeed);
    move_relativeRightChassis((angle * 2.34), maxSpeed);

    for(int i = 0; i < time; i++) {

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

}