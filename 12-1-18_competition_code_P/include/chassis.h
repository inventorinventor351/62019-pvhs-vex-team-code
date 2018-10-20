#ifndef CHASSIS_H
#define CHASSIS_H

extern Motor leftChassis1;
extern Motor leftChassis2;
extern Motor leftChassis3;
extern Motor rightChassis1;
extern Motor rightChassis2;
extern Motor rightChassis3;

void moveLeftChassis(int speed);
void moveRightChassis(int speed);

void move_absoluteLeftChassis(int distance, int maxSpeed);
void move_absoluteRightChassis(int distance, int maxSpeed);

void move_relativeLeftChassis(int distance, int maxSpeed);
void move_relativeRightChassis(int distance, int maxSpeed);

void move_velocityLeftChassis(int rpm);
void move_velocityRightChassis(int rpm);

void move_voltageLeftChassis(int voltage);
void move_voltageRightChassis(int voltage);

#endif