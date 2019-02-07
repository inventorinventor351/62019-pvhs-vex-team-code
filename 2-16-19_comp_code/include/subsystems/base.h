#ifndef BASE_H
#define BASE_H

void runLeftBase(float voltPerc); //runs the left base at a percentage of max voltage from -100% to 100%
void runRightBase(float voltPerc); //runs the right base at a percentage of max voltage from -100% to 100%
float getDist(); //returns distance encoder value in float format
void resetEncs(); //resets all the motor encoders on the base
float getYaw(); //returns angular position of robot in float format
void resetGyros(); //resets the gyros in a way, setting robot's current angular position as 0
void moveStraight(float setPoint, int time); //move base on a straight line, takes in a distance with direction
void pvtBase(float setPoint, int time); //pivots base in place, takes in an angle whose sign is its direction

#endif