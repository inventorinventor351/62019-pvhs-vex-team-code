#ifndef CHASSIS_H
#define CHASSIS_H
#include "api.h"

void driveRight(int speed);
void driveLeft(int speed);

void driverpmRight(int rpm);
void driverpmLeft(int rpm);

void driveVoltRight(int voltage);
void driveVoltLeft(int voltage);

void driveAbsRight(int distance);
void driceAbsLeft(int distance);

void driveRelativeRight(int distance);
void driveRelativeLeft(int distance);

#endif