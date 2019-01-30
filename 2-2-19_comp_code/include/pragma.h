#ifndef PRAGMA_H
#define PRAGMA_H

#define PorX(p, x) !whichTeam.get_value() ? p : x

extern Controller master;

//V5 Components
extern Motor leftBase1; //first motor on the left side of the base
extern Motor leftBase2; //second motor on the left side of the base
extern Motor leftBase3; //third motor on the left side of the base, but only X team has it
extern Motor rightBase1; //first motor on the right side of the base
extern Motor rightBase2; //second motor on the right side of the base
extern Motor rightBase3; //third motor on the right side of the base, but only X team has it
extern Motor intk; //motor that runs the intake
extern Motor cplt; //motor that runs the catapult

extern Vision cpltVis; //vision sensor on catapult to aid in flag aiming

//Legacy Components
extern ADIDigitalIn whichTeam; //jumper that allows code to distinguish between P team and X team
extern ADIAnalogIn cpltPot; //potentiometer that measures the angle of the catapult arm
extern ADIGyro gyro; //gyro used for turning in autonomous
extern ADIEncoder distEnc; //encoder on a tracking wheel that is parallel to the base wheels
extern ADIDigitalOut descorer; //piston for descoring high flags and only P team has it
extern ADIDigitalOut transPstn; //piston that controls the transmission and only P team has it

#endif