#include "main.h"

void runLeftBase(float voltPerc) {

    leftBase1.move_voltage((voltPerc / 100) * 12000);
    leftBase2.move_voltage((voltPerc / 100) * 12000);

    if(whichTeam.get_value())
        leftBase3.move_voltage((voltPerc / 100) * 12000);

}

void runRightBase(float voltPerc) {

    rightBase1.move_voltage((voltPerc / 100) * 12000);
    rightBase2.move_voltage((voltPerc / 100) * 12000);

    if(whichTeam.get_value())
        rightBase3.move_voltage((voltPerc / 100) * 12000);

}

float getDist() {

    return (float)distEnc.get_value();

}

float getYaw() {

    return (float)gyro.get_value() * 0.94;

}

void moveStraight(float setPoint, int time) {

    float distVal, diffVal;

    PID dist = initPID(1, 0, 1, 0.1, 0, 0.275);
    PID diff = initPID(1, 0, 0, 0.8, 0, 0);

    distEnc.reset();
    gyro.reset();

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

    float distVal, dispVal;
    setPoint *= 10.0;

    PID dist = initPID(1, 0, 0, 0.081, 0, 0);
    PID disp = initPID(0, 0, 0, 0, 0, 0);

    distEnc.reset();
    gyro.reset();

    for(int i = 0; i < time; i++) {

        dist.error = getYaw() + setPoint;
        disp.error = getDist();

        distVal = runPID(&dist);
        dispVal = runPID(&disp);

        runLeftBase(-distVal - dispVal);
        runRightBase(distVal - dispVal);

        delay(1);

    }

    runLeftBase(0);
    runRightBase(0);

}