#include "main.h"

void runLeftBase(float voltPerc) {

    leftBase1.move_voltage((voltPerc / 100) * 12000);
    leftBase2.move_voltage((voltPerc / 100) * 12000);
    leftBase3.move_voltage((voltPerc / 100) * 12000);

}

void runRightBase(float voltPerc) {

    rightBase1.move_voltage((voltPerc / 100) * 12000);
    rightBase2.move_voltage((voltPerc / 100) * 12000);
    rightBase3.move_voltage((voltPerc / 100) * 12000);

}

float getDist() {

    return ((leftBase1.get_position() + leftBase2.get_position() + leftBase3.get_position() + rightBase1.get_position() + rightBase2.get_position() + rightBase3.get_position()) / 6);

}

void resetEncs() {

    leftBase1.tare_position();
    leftBase2.tare_position();
    leftBase3.tare_position();
    rightBase1.tare_position();
    rightBase2.tare_position();
    rightBase3.tare_position();

}

float getYaw() {

    return ((((float)gyro1.get_value() + (float)gyro2.get_value()) / 2) * 0.094);

}

void resetGyros() {

    gyro1.reset();
    gyro2.reset();

}

void moveStraight(float setPoint, int time) {

    float distVal, diffVal;

    PID dist = PorX(initPID(1, 0, 1, 0.1, 0, 0.275), initPID(1, 0, 1, 0.24, 0, 1));
    PID diff = PorX(initPID(1, 0, 0, 0.8, 0, 0), initPID(1, 0, 0, 0.5, 0, 0));

    resetEncs();
    resetGyros();

    for(int i = 0; i < time; i++) {

        dist.error = setPoint - getDist();
        diff.error = getYaw();

        distVal = runPID(&dist);
        distVal = (abs(distVal) > 90) ? (90 * sgn(distVal)) : distVal;
        diffVal = runPID(&diff);

        runLeftBase(distVal - diffVal);
        runRightBase(distVal + diffVal);

        delay(1);

    }

    runLeftBase(0);
    runRightBase(0);

}

void pvtBase(float setPoint, int time) {

    float yawVal, dispVal;

    PID yaw = initPID(1, 0, 0, 0.11, 0, 0);
    PID disp = initPID(0, 0, 0, 0, 0, 0);

    resetEncs();
    resetGyros();

    for(int i = 0; i < time; i++) {

        yaw.error = getYaw() + setPoint;
        disp.error = getDist();

        yawVal = runPID(&yaw);
        dispVal = runPID(&disp);

        runLeftBase(-yawVal - dispVal);
        runRightBase(yawVal - dispVal);

        delay(1);

    }

    runLeftBase(0);
    runRightBase(0);

}