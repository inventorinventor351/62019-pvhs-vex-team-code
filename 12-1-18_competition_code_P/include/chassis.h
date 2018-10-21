#ifndef CHASSIS_H
#define CHASSIS_H

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