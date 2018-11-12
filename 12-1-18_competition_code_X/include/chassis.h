#ifndef CHASSIS_H
#define CHASSIS_H
#include "api.h"

void driveRight(int speed);
void driveLeft(int speed);

void driverpmRight(int rpm);
void driverpmLeft(int rpm);

void driveVoltRight(int voltage);
void driveVoltLeft(int voltage);

void driveAbsRight(float distance, int maxSpeed);
void driveAbsLeft(float distance, int maxSpeed);

void driveRelativeRight(float distance, int maxSpeed);
void driveRelativeLeft(float distance, int maxSpeed);

void drivePD(float goal, int time);
void pvitPD(int angle, int time);

void pvitChassis(float angle, int maxSpeed, int timer);

void aimFlag();
void autonAimFlag();

#endif