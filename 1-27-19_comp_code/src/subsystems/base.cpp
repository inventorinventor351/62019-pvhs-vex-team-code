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
    PID diff = initPID(1, 0, 0, 0.625, 0, 0);

    distEnc.reset();
    yawEnc.reset();

    for(int i = 0; i < time; i++) {

        dist.error = setPoint - distEnc.get_value();
        diff.error = yawEnc.get_value();

        distVal = runPID(&dist);
        diffVal = runPID(&diff);

        runLeftBase(distVal - diffVal);
        runRightBase(distVal + diffVal);

        delay(1);

    }

    runLeftBase(0);
    runRightBase(0);

}

void pvtBase(int angle, int time) {

    double setPoint = -round(angle * 15 / 2.8), distVal, dispVal;

    PID dist = initPID(1, 0, 0, 0.25, 0, 7.5);
    PID disp = initPID(0, 0, 0, 0.5, 0, 2);

    distEnc.reset();
    yawEnc.reset();

    for(int i = 0; i < time; i++) {

        dist.error = setPoint - yawEnc.get_value();
        disp.error = (distEnc.get_value()) * sgn(angle);

        distVal = runPID(&dist);
        dispVal = runPID(&disp);

        if(!(i % 10))
            std::cout << "yawEnc: " << yawEnc.get_value() << "  |  " << "distEnc: " << distEnc.get_value() << "  |  " << "turnErr: " << dist.error << "  |  " << "setPnt: " << setPoint << "  |  " << "dispErr: " << disp.error << "  |  " << "distVal: " << distVal << "  |  " << "dispVal: " << dispVal << "  |  " << "ms: " << i << "\n";

        runLeftBase(distVal - dispVal);
        runRightBase(-distVal - dispVal);

        delay(1);

    }

    runLeftBase(0);
    runRightBase(0);

}