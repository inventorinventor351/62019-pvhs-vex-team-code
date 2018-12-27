#ifndef PRAGMA_H
#define PRAGMA_H

extern Motor leftBase1; //first motor on the left side of the base
extern Motor leftBase2; //second motor on the left side of the base
extern Motor rightBase1; //first motor on the right side of the base
extern Motor rightBase2; //second motor on the right side of the base
extern Motor intk; //motor that runs the intake
extern Motor cplt; //motor that runs the catapult

extern Vision intkVis; //vision sensor that helps the intake aim for balls
extern Vision cpltVis; //vision sensor that helps the catapult aim for flags

extern ADIDigitalOut transPstn; //piston that controls the transmission

extern ADIAnalogIn cpltPot; //potentiometer that measures the angle of the catapult arm

extern ADIEncoder distEnc; //encoder on a tracking wheel that is parallel to the base wheels
extern ADIEncoder yawEnc; //encoder on a tracking wheel that is perpendicular to the base wheels

extern Controller master;

#endif