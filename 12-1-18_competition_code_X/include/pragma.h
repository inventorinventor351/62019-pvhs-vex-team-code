#ifndef PRAGMA_H
#define PRAGMA_H

extern Controller master;

extern Motor leftChassis1;
extern Motor leftChassis2;
extern Motor rightChassis1;
extern Motor rightChassis2;
extern Motor intake;
extern Motor shooter;

extern Vision shooterEye;

extern ADIDigitalOut intakeLift;
extern ADIDigitalOut chassisTransmission;
extern ADIDigitalOut tipper;

extern ADIAnalogIn ballSensor;

#endif