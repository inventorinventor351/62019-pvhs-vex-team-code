#include "main.h"

void runIntake(float voltPerc) {

    intk.move_voltage((voltPerc / 100) * 12000);

}

void runIntakeTime(float voltPerc, int time) {

    intk.move_voltage((voltPerc / 100) * 12000);
    delay(time);
    intk.move_voltage(0);

}

void getBall() {

    if(abs(intkVis.get_by_size(0).x_middle_coord) > 320) {

        runLeftBase(0);
        runRightBase(0);

    }

    else {

        for(int i = 0; i < 3000; i++) {


            
        }

    }
}

bool isBall() {

    int i;
    
    if(ballSensor.get_value < 14) 
        i = 1;
    else
        i = 0;

    return i;
}