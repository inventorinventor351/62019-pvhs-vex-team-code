#ifndef PRAGMA_H
#define PRAGMA_H

extern Controller master;

//V5 Components
extern Motor leftBase1; //first motor on the left side of the base
extern Motor leftBase2; //second motor on the left side of the base
extern Motor rightBase1; //first motor on the right side of the base
extern Motor rightBase2; //second motor on the right side of the base
extern Motor leftLift;
extern Motor rightLift;

extern Vision coneVis1;
extern Vision coneVis2;


//Legacy Components
extern ADIEncoder yawEnc;
extern ADIDigitalOut liftPstn1;
extern ADIDigitalOut liftPstn2;

#endif