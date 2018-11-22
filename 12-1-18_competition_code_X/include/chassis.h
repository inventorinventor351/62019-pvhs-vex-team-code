#ifndef CHASSIS_H
#define CHASSIS_H
#include "api.h"

void driveRight(int speed);
void driveLeft(int speed);

void driveVelocityRight(int rpm);
void driveVelocityLeft(int rpm);

void driveAbsRight(float distance, int maxSpeed);
void driveAbsLeft(float distance, int maxSpeed);

void driveRelativeRight(float distance, int maxSpeed);
void driveRelativeLeft(float distance, int maxSpeed);

void driveVoltRight(int voltage);
void driveVoltLeft(int voltage);

void pvitChassis(float angle, int maxSpeed, int timer);

void drivePD(float goal, int time);
void pvitPD(int angle, int time);

void aimFlag();
void autonAimFlag();

void resetChassisEncoderValueX();

#endif