#ifndef BASE_H
#define BASE_H

void runLeftBase(float voltPerc); //runs the left base at a percentage of max voltage from -100% to 100%
void runRightBase(float voltPerc); //runs the right base at a percentage of max voltage from -100% to 100%
void moveStraight(double setPoint, double direction, int time); //move base on a straight line, takes in a distance and a direction
void pvtBase(int angle, int time); //pivots base in place, takes in an angle whose sign is its direction

#endif