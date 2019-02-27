#ifndef INTAKE_H
#define INTAKE_H

void runIntk(float voltPerc); //runs the intake at a percentage of max voltage from -100% to 100%
void yaBoi(); //uses the passive tipper
extern float armSetPoint; //setPoint of the intake arm control PID
extern bool resetIntkEnc;
void intkArmControl(void* param); //controls the position of the intake arm to make it easier to use

#endif