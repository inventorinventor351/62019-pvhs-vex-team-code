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
        distVal = (abs(distVal) > 80) ? (80 * sgn(distVal)) : (distVal);
        diffVal = runPID(&diff);
        diffVal = (abs(diffVal) > 20) ? (20 * sgn(diffVal)) : (diffVal);

        runLeftBase(distVal - diffVal);
        runRightBase(distVal + diffVal);

        delay(1);

    }

    runLeftBase(0);
    runRightBase(0);

}

void pvtBase(int angle, int time) {

    int count = 0;

    double setPoint = round(angle * 15 / 2.8), distVal, dispVal;

    master.print(2, 0, "%f", setPoint);

    PID dist = initPID(1, 0, 0, 0.12, 0, 0);
    PID disp = initPID(1, 0, 0, 1, 0, 0);

    distEnc.reset();
    yawEnc.reset();

    for(int i = 0; i < time; i++) {

        dist.error = setPoint - yawEnc.get_value();
        disp.error = distEnc.get_value();

        distVal = runPID(&dist);
        distVal = (abs(distVal) > 80) ? (80 * sgn(distVal)) : (distVal);
        dispVal = runPID(&disp);
        dispVal = (abs(dispVal) > 20) ? (20 * sgn(dispVal)) : (dispVal);

        runLeftBase(distVal + dispVal);
        runRightBase(-distVal - dispVal);

        if(!(count % 50)) {

            master.print(0, 0, "%d", distEnc.get_value());
            delay(50);
            master.print(1, 0, "%d", yawEnc.get_value());
            delay(50);

        }

        count++;

        delay(1);

    }

    runLeftBase(0);
    runRightBase(0);

    while(true) {

        master.print(0, 0, "%d", distEnc.get_value());
        delay(50);
        master.print(1, 0, "%d", yawEnc.get_value());
        delay(50);

    }

}