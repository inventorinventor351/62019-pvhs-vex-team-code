#ifndef CHASSIS_H
#define CHASSIS_H

void moveLeftChassis(int speed);
void moveRightChassis(int speed);

void move_absoluteLeftChassis(float distance, int maxSpeed);
void move_absoluteRightChassis(float distance, int maxSpeed);

void move_relativeLeftChassis(float distance, int maxSpeed);
void move_relativeRightChassis(float distance, int maxSpeed);

void move_velocityLeftChassis(int rpm);
void move_velocityRightChassis(int rpm);

void move_voltageLeftChassis(int voltage);
void move_voltageRightChassis(int voltage);

float getLeftChassisPosition();
float getRightChassisPosition();

void pivotChassisBAD(float angle, int maxSpeed, int time);

void aimAtFlag();
void autonShoot();

void resetLeftChassisEncoderValue();
void resetRightChassisEncoderValue();
void resetChassisEncoderValue();

void driveChassisRelative(int dist, int speed);
void driveChassisAbs(int dist, int speed);
void driveChassisVoltage(int time, int voltage);

void driveStraight(float setPoint, int time);
void pivotChassis(int angle, int time);

#endif