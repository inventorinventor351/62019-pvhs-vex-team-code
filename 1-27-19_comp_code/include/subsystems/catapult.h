#ifndef CATAPULT_H
#define CATAPULT_H

void runCatapult(float voltPerc); //runs the catapult at a percentage of max voltage from -100% to 100%
void cpltShoot(); //rotates the catapult once
void flagAim(); //aims at the flag
void initCpltVis(); //gives the cpltVis camera the signature for the flag

#endif