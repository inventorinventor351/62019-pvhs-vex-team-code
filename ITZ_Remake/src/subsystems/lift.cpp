#include "main.h"

void runLeftLift(float voltPerc) {

    leftLift.move_voltage((voltPerc / 100) * 12000);

}

void runRightLift(float voltPerc) {

    rightLift.move_voltage((voltPerc / 100) * 12000);

}

float getLiftPos() {

    return (leftLift.get_position() + rightLift.get_position()) / 2;

}


bool stack = 0;

void holdLift(void* param) {

    std::uint_least32_t now = millis();
    float liftVal, liftDiffVal, setPoint;
    bool coneVis = 1;

    PID lift = initPID(0, 0, 0, 0, 0, 0);
    PID liftDiff = initPID(0, 0, 0, 0, 0, 0);

    leftLift.tare_position();
    rightLift.tare_position();

    while(true) {

        if(!idle)
            setPoint = 0;

        else if(idle)
            setPoint = 0;

        if(stack) {

            while(coneVis) {

                runLeftLift(100);
                runRightLift(100);

                if(!(coneVis1.get_object_count() + coneVis2.get_object_count()))
                    coneVis = 0;

            }

            liftPstn1.set_value(1);
            liftPstn2.set_value(1);

            runLeftLift(-100);
            runRightLift(-100);
            delay(500);

            liftPstn1.set_value(0);
            liftPstn2.set_value(0);

        }

        lift.error = setPoint - getLiftPos();
        liftDiff.error = leftLift.get_position() - rightLift.get_position();

        liftVal = runPID(&lift);
        liftDiffVal = runPID(&liftDiff);

        runLeftLift(liftVal - liftDiffVal);
        runRightLift(liftVal + liftDiffVal);

        Task::delay_until(&now, 1);

    }

}


void initConeVis() {

    

}