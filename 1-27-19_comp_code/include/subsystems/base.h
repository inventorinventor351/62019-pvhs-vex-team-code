#ifndef BASE_H
#define BASE_H

void runLeftBase(float voltPerc); //runs the left base at a percentage of max voltage from -100% to 100%
void runRightBase(float voltPerc); //runs the right base at a percentage of max voltage from -100% to 100%

extern int leftTarget; //target voltage for slew rate
extern int rightTarget; //target voltage for slew rate
void baseSR(void* param); //base's slew rate, runs evert 1 ms, controls accel of base

#endif