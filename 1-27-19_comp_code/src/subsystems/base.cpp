#include "main.h"

void runLeftBase(float voltPerc) {

    leftBase1.move_voltage((voltPerc / 100) * 12000);
    leftBase2.move_voltage((voltPerc / 100) * 12000);

}

void runRightBase(float voltPerc) {

    rightBase1.move_voltage((voltPerc / 100) * 12000);
    rightBase2.move_voltage((voltPerc / 100) * 12000);
}

double getDist() {

    return (double)distEnc.get_value();

}

double getYaw() {

    return (double)yawEnc.get_value();

}

int leftTarget = 0;
int rightTarget = 0;

void baseSR(void* param) {

    std::uint_least32_t now = millis();

    float leftCurrent = 0; //variable for the current voltage
    float rightCurrent = 0; //variable for the current voltage
    float accel = 1; //variable for the accel
	
	while(true) {

        if(leftTarget > leftCurrent) {

            leftCurrent += accel;

        }

        else if(leftTarget < leftCurrent) {

            leftCurrent -= accel;

        }

        else if(abs(rightTarget - rightCurrent) < accel) {

            leftCurrent = leftTarget;

        }

        if(rightTarget > rightCurrent) {

            rightCurrent += accel;

        }

        else if(rightCurrent < rightTarget) {

            rightCurrent -= accel;

        }

        else if(abs(rightTarget - rightCurrent) < accel) {

            rightCurrent = rightTarget;

        }

        runLeftBase(leftCurrent);
        runRightBase(rightCurrent);

		Task::delay_until(&now, 1); //loop slew rate 1000 times per second
		
	}

}

void moveStrtBase(double setPoint, int direction, int time) {

    double distVal, diffVal;

    direction = (int)sgn((double)direction);

    PID dist = initPID(0, 0, 0, 0, 0, 0);
    PID diff = initPID(0, 0, 0, 0, 0, 0);

    distEnc.reset();
    yawEnc.reset();

    for(int i = 0; i < time; i++) {

        dist.error = setPoint - getDist();
        diff.error = 0 - getYaw();

        distVal = runPID(&dist);
        diffVal = runPID(&diff);

        leftTarget = distVal - diffVal;
        rightTarget = distVal + diffVal;

        delay(1);

    }

    leftTarget = 0;
    rightTarget = 0;

}

void pvtBase(int angle, int time) {

    double setPoint = (double)angle * 0.66, distVal, dispVal;

    PID dist = initPID(0, 0, 0, 0, 0, 0);
    PID disp = initPID(0, 0, 0, 0, 0, 0);

    distEnc.reset();
    yawEnc.reset();

    for(int i = 0; i < time; i++) {

        dist.error = setPoint - getYaw();

        distVal = runPID(&dist);

        leftTarget = distVal;
        rightTarget = -distVal;

        delay(1);

    }

    leftTarget = 0;
    rightTarget = 0;

}