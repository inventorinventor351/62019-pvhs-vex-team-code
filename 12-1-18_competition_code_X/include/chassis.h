#ifndef CHASSIS_H
#define CHASSIS_H
#include "api.h"

void driveRight(int speed);
void driveLeft(int speed);

void driverpmRight(int rpm);
void driverpmLeft(int rpm);

void driveVoltRight(int voltage);
void driveVoltLeft(int voltage);

void driveAbsRight(int distance, int maxSpeed);
void driveAbsLeft(int distance, int maxSpeed);

void driveRelativeRight(int distance, int maxSpeed);
void driveRelativeLeft(int distance, int maxSpeed);

void pvitChassis(float angle, int maxSpeed, int timer);

void aimFlag();

#endif