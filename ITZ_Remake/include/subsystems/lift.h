#ifndef LIFT_H
#define LIFT_H

void runLeftLift(float voltPerc);
void runRightLift(float voltPerc);

float getLiftPos();

void holdLift(void* param);
extern bool stack, idle;

void initConeVis();

#endif