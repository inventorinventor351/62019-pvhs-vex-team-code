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

    return ((float)distEnc.get_value() * PorX(-1, 1));

}

float getYaw() {

    return ((float)gyro.get_value() * 0.94);

}

void moveStraight(float setPoint, int time) {

    float distVal, diffVal;

    PID dist = PorX(initPID(1, 0, 1, 0.1, 0, 0.275), initPID(1, 0, 1, 0.3, 0, 1));
    PID diff = PorX(initPID(1, 0, 0, 0.8, 0, 0), initPID(1, 0, 0, 0.5, 0, 0));

    distEnc.reset();
    gyro.reset();

    for(int i = 0; i < time; i++) {

        dist.error = setPoint - getDist();
        diff.error = getYaw();

        distVal = runPID(&dist);
        distVal = (abs(distVal) > 90) ? (90 * sgn(distVal)) : distVal;
        diffVal = runPID(&diff);

        std::cout << "gyro: " << gyro.get_value() << "  |  " << "distEnc: " << distEnc.get_value() << "  |  " << "Err: " << dist.error << "  |  " << "setPnt: " << setPoint << "  |  " << "diffErr: " << diff.error << "  |  " << "distVal: " << distVal << "  |  " << "diffVal: " << diffVal << "  |  " << "ms: " << i << "\n";

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

    PID dist = initPID(1, 0, 0, 0.14, 0, 0);
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

        std::cout << "gyro: " << gyro.get_value() << "  |  " << "distEnc: " << distEnc.get_value() << "  |  " << "turnErr: " << dist.error << "  |  " << "setPnt: " << setPoint << "  |  " << "dispErr: " << disp.error << "  |  " << "distVal: " << distVal << "  |  " << "dispVal: " << dispVal << "  |  " << "ms: " << i << "\n";

        delay(1);

    }

    runLeftBase(0);
    runRightBase(0);

}