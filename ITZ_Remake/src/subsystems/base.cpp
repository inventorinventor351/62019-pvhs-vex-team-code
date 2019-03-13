#include "main.h"

void runLeftBase(float voltPerc) {

    leftBase1.move_voltage((voltPerc / 100) * 12000);
    leftBase2.move_voltage((voltPerc / 100) * 12000);

}

void runRightBase(float voltPerc) {

    rightBase1.move_voltage((voltPerc / 100) * 12000);
    rightBase2.move_voltage((voltPerc / 100) * 12000);

}


void moveStraight(float setPoint, int time) {

    float distVal, diffVal;
    setPoint *= 0.678788;

    PID dist = initPID(1, 0, 1, 0.5, 0, 1);
    PID diff = initPID(1, 0, 0, 2, 0, 0);

    resetEncs();
    delay(1);

    for(int i = 0; i < time; i++) {

        dist.error = setPoint - (getLeftPos() + getRightPos()) / 2;  
        diff.error = getYaw();

        distVal = runPID(&dist);
        distVal = (abs(distVal) > 90) ? (90 * sgn(distVal)) : distVal;
        diffVal = runPID(&diff);

        if(!(i % 10))
            std::cout << "yaw: " << getYaw() << "  |  " << "distEnc: " << (getLeftPos() + getRightPos()) / 2 << "  |  " << "Err: " << dist.error << "  |  " << "setPnt: " << setPoint << "  |  " << "diffErr: " << diff.error << "  |  " << "distVal: " << distVal << "  |  " << "diffVal: " << diffVal << "  |  time: " << i << "\n";

        runLeftBase(distVal - diffVal);
        runRightBase(distVal + diffVal);

        delay(1);

    }

    runLeftBase(0);
    runRightBase(0);

}

void turn(float setPoint, int time) {

    float yawVal, dispVal, prevYaw;
    //setPoint *= -4.0366;
    setPoint *= -3.3;

    PID YAW = initPID(1, 0, 0, 1.3, 0, 0);
    PID disp = initPID(1, 0, 0, 1, 0, 0);

    resetEncs();
    delay(1);

    for(int i = 0; i < time; i++) {

        YAW.error = setPoint - (getLeftPos() - getRightPos());
        disp.error = (getLeftPos() + getRightPos()) / 2;

        yawVal = runPID(&YAW);
        dispVal = runPID(&disp);

        std::cout << "yaw: " << (getLeftPos() - getRightPos()) << " | " << "Err: " << YAW.error << " | " << "setPnt: " << setPoint << " | " << "dispErr: " << disp.error << " | " << "yawVal: " << yawVal << " | " << "dispVal: " << dispVal << " | " << "ms: " << i << "\n";

        runLeftBase(yawVal - dispVal);
        runRightBase(-yawVal - dispVal);

        delay(1);

    }

    runLeftBase(0);
    runRightBase(0);

}


float getLeftPos() {

    return leftBase1.get_position();

}

float getRightPos() {

    return rightBase1.get_position();

}

float getYaw() {

    return yawEnc.get_value();

}

void resetEncs() {

    leftBase1.tare_position();
    rightBase1.tare_position();

}

void resetYaw() {

    yawEnc.reset();

}


void moveMogo(float mogoVel) {

    leftBase1.move_voltage(-(mogoVel / 100) * 12000);
    leftBase2.move_voltage((mogoVel / 100) * 12000);
    rightBase1.move_voltage(-(mogoVel / 100) * 12000);
    rightBase2.move_voltage((mogoVel / 100) * 12000);

}