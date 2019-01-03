#ifndef BASE_H
#define BASE_H

void runLeftBase(float voltPerc); //runs the left base at a percentage of max voltage from -100% to 100%
void runRightBase(float voltPerc); //runs the right base at a percentage of max voltage from -100% to 100%

extern int leftTarget; //target voltage for slew rate
extern int rightTarget; //target voltage for slew rate
void baseSR(void* param); //base's slew rate, runs evert 1 ms, controls accel of base
void moveStraight(int setPoint, int direction, int time); //move base on a straight line, takes in a distance and a direction
void pvtBase(int angle, int time); //pivots base in place, takes in an angle whose sign is its direction
double getDist(); //returns, as a double, the distance encoder value
double getYaw(); //returns as a double, the yaw encoder value

#endif