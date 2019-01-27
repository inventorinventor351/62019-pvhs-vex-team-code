#include "main.h"

void runLeftBase(float voltPerc) {

    leftBase1.move_voltage((voltPerc / 100) * 12000);
    leftBase2.move_voltage((voltPerc / 100) * 12000);

}

void runRightBase(float voltPerc) {

    rightBase1.move_voltage((voltPerc / 100) * 12000);
    rightBase2.move_voltage((voltPerc / 100) * 12000);
}

void moveStraight(double setPoint, double direction, int time) {

    double distVal, diffVal;
 
    setPoint = abs(setPoint) * sgn(direction);

    PID dist = initPID(1, 0, 1, 0.1, 0, 0.275);
    PID diff = initPID(1, 0, 0, 0.8, 0, 0);

    distEnc.reset();
    gyro.reset();

    for(int i = 0; i < time; i++) {

        dist.error = setPoint - distEnc.get_value();
        diff.error = (gyro.get_value() * 0.94);

        distVal = runPID(&dist);
        distVal = (abs(distVal) > 90) ? (90 * sgn(distVal)) : distVal;
        diffVal = runPID(&diff);

        runLeftBase(distVal - diffVal);
        runRightBase(distVal + diffVal);

        if(!(i % 10))
            std::cout << "gyro: " << gyro.get_value() << "  |  " << "distEnc: " << distEnc.get_value() << "  |  " << "distErr: " << dist.error << "  |  " << "setPnt: " << setPoint << "  |  " << "diffErr: " << diff.error << "  |  " << "distVal: " << distVal << "  |  " << "diffVal: " << diffVal << "  |  " << "ms: " << i << "\n";

        delay(1);

    }

    runLeftBase(0);
    runRightBase(0);

}

void pvtBase(int setPoint, int time) {

    double distVal, dispVal;
    setPoint *= 10;

    PID dist = initPID(1, 0, 0, 0.081, 0, 0);
    PID disp = initPID(0, 0, 0, 0, 0, 0);

    distEnc.reset();
    gyro.reset();

    for(int i = 0; i < time; i++) {

        dist.error = (gyro.get_value() * 0.94) + setPoint;
        disp.error = (distEnc.get_value());

        distVal = runPID(&dist);
        dispVal = runPID(&disp);

        if(!(i % 10))
        std::cout << "gyro: " << gyro.get_value() << "  |  " << "distEnc: " << distEnc.get_value() << "  |  " << "turnErr: " << dist.error << "  |  " << "setPnt: " << setPoint << "  |  " << "dispErr: " << disp.error << "  |  " << "distVal: " << distVal << "  |  " << "dispVal: " << dispVal << "  |  " << "ms: " << i << "\n";

        runLeftBase(-distVal - dispVal);
        runRightBase(distVal - dispVal);

        delay(1);

    }

    runLeftBase(0);
    runRightBase(0);

}