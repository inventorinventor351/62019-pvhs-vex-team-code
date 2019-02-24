#ifndef PRAGMA_H
#define PRAGMA_H

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
extern ADIAnalogIn cpltPot; //potentiometer that measures the angle of the catapult arm
extern ADIGyro gyro1; //gyro used for turning in autonomous
extern ADIGyro gyro2; //gyro used for turning in autonomous
/*extern ADIGyro gyro3; //gyro used for turning in autonomous
extern ADIGyro gyro4; //gyro used for turning in autonomous*/
extern ADIDigitalIn whichTeam;

#endif