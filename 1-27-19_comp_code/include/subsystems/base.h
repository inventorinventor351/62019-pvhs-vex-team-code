#ifndef BASE_H
#define BASE_H

void runLeftBase(float voltPerc); //runs the left base at a percentage of max voltage from -100% to 100%
void runRightBase(float voltPerc); //runs the right base at a percentage of max voltage from -100% to 100%

extern int target;
void baseSR(); //base's slew rate, runs evert 1 ms, controls accel of base
void getBaseSpeed(); //returns angular speed of base every 2 ms, speed is in degrees per ms
void basePosPID(); //runs base's position PID every 4 ms
void baseVelPID(); //run base's velocity PID every 4 ms

#endif