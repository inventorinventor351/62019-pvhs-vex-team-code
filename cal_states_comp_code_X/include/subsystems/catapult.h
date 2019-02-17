#ifndef CATAPULT_H
#define CATAPULT_H

void runCplt(float voltPerc); //runs the catapult at a percentage of max voltage from -100% to 100%
extern bool shoot; //whenever this is set to true, catapult will shoot and go back to idle position
void cpltControl(void* param); //keeps catapult running against rubberbands at a desired height
void initCpltVis(); //gives the cpltVis camera the signatures for the flags
void flagAim(); //aims at the flag, takes in a preferred flag (mid or high)

#endif