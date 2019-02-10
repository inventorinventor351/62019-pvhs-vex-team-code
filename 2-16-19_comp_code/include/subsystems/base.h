#ifndef BASE_H
#define BASE_H

void runLeftBase(float voltPerc); //runs the left base at a percentage of max voltage from -100% to 100%
void runRightBase(float voltPerc); //runs the right base at a percentage of max voltage from -100% to 100%
float getDist(); //returns distance encoder value in float format
void resetEncs(); //resets all the motor encoders on the base
extern float yaw; //angular position of robot
extern bool resetYaw; //if set to true, it resets the yaw
void getYaw(void* param); //background tasks that gets yaw of robot using two gyros and logic
void checkTemp(void* param); //regulates the temperature of the motors
void moveStraight(float setPoint, int time); //move base on a straight line, takes in a distance with direction
void pvtBase(float setPoint, int time); //pivots base in place, takes in an angle whose sign is its direction

#endif