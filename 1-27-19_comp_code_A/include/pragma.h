#ifndef PRAGMA_H
#define PRAGMA_H

extern Motor leftBase1; //first motor on the left side of the base
extern Motor leftBase2; //second motor on the left side of the base
extern Motor leftBase3; // third motor on the left side of base
extern Motor rightBase1; //first motor on the right side of the base
extern Motor rightBase2; //second motor on the right side of the base
extern Motor rightBase3; //third motor on the right side of the base
extern Motor intake; //motor that spin the sprotet to flip caps
extern Motor deSr; //motor used to de-score caps and help flip caps

//extern ADIEncoder distEnc; //encoder on a tracking wheel that is parallel to the base wheels

extern Vision visn; //vision sensor used in autons

extern Controller master;

#endif


