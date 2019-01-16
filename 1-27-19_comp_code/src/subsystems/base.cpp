#include "main.h"

void runLeftBase(float voltPerc) {

    leftBase1.move_voltage((voltPerc / 100) * 12000);
    leftBase2.move_voltage((voltPerc / 100) * 12000);

}

void runRightBase(float voltPerc) {

    rightBase1.move_voltage((voltPerc / 100) * 12000);
    rightBase2.move_voltage((voltPerc / 100) * 12000);
}

void moveStraight(int setPoint, int direction, int time) {

    int count = 0;

    double distVal, diffVal;

    direction = (int)sgn((double)direction);

    PID dist = initPID(1, 0, 0, 0.13, 0, 0.15);
    PID diff = initPID(1, 0, 0, 0.1, 0, 0);

    distEnc.reset();
    yawEnc.reset();

    for(int i = 0; i < time; i++) {

        dist.error = setPoint - distEnc.get_value();
        diff.error = 0 - yawEnc.get_value();

        distVal = runPID(&dist);
        distVal = (abs(distVal) > 9000) ? (9000 * sgn(distVal)) : (distVal);
        diffVal = runPID(&diff);
        diffVal = (abs(diffVal) > 3000) ? (3000 * sgn(diffVal)) : (diffVal);

        runLeftBase(distVal - diffVal);
        runRightBase(distVal + diffVal);

        if(!(count % 50)) {

            master.print(0, 0, "%d", distEnc.get_value());
            delay(50);
            master.print(1, 0, "%d", yawEnc.get_value());
            delay(50);
            master.print(2, 0, "%f", diffVal);

        }

        count++;

        delay(1);

    }

    runLeftBase(0);
    runRightBase(0);

}

void pvtBase(int angle, int time) {

    double setPoint = (double)angle * 0.66, distVal, dispVal;

    PID dist = initPID(0, 0, 0, 0, 0, 0);
    PID disp = initPID(0, 0, 0, 0, 0, 0);

    distEnc.reset();
    yawEnc.reset();

    for(int i = 0; i < time; i++) {

        dist.error = setPoint - yawEnc.get_value();;

        distVal = runPID(&dist);

        runLeftBase(distVal);
        runRightBase(-distVal);

        delay(1);

    }

    runLeftBase(0);
    runRightBase(0);

}