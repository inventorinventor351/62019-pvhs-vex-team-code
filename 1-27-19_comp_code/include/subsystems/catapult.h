#ifndef CATAPULT_H
#define CATAPULT_H

void runCplt(float voltPerc); //runs the catapult at a percentage of max voltage from -100% to 100%
void cpltShoot(); //rotates the catapult once
void flagAim(); //aims at the flag
void initCpltVis(); //gives the cpltVis camera the signature for the flag
void cpltReturn(); // for autons, returns catapult to setpoint
extern bool shoot;

#endif