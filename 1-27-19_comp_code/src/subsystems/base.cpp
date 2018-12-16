#include "main.h"

void runLeftBase(float voltPerc) {

    leftBase1.move_voltage((voltPerc / 100) * 12000);
    leftBase2.move_voltage((voltPerc / 100) * 12000);

}

void runRightBase(float voltPerc) {

    rightBase1.move_voltage((voltPerc / 100) * 12000);
    rightBase2.move_voltage((voltPerc / 100) * 12000);
}

int leftTarget = 0;
int rightTarget = 0;

void baseSR() {

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