#ifndef CHASSIS_H
#define CHASSIS_H
#include "api.h"

extern Motor leftChassis1;
extern Motor leftChassis2;
extern Motor leftChassis3;
extern Motor rightChassis1;
extern Motor rightChassis2;
extern Motor rightChassis3;

void driveRight(int speed);
void driveLeft(int speed);

void driverpmRight(int rpm);
void driverpmLeft(int rpm);

void driveVoltRight(int voltage);
void driveVoltLeft(int voltage);

void driveabsRight(int distance);
void driceabsLeft(int distance);

void driveRelativeRight(int distance);
void driveRelativeLeft(int distance);

#endif