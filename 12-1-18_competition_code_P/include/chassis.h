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

void pivotChassis(float angle, int maxSpeed, int time);

void aimAtFlag(float kP_, float kD_);
void autonShoot(float kP_, float kD_);

void resetLeftChassisEncoderValue();
void resetRightChassisEncoderValue();
void resetChassisEncoderValue();

#endif