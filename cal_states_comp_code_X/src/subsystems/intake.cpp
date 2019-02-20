#include "main.h"

void runIntk(float voltPerc) {

    intk.move_voltage((voltPerc / 100) * 12000);

}

void yaBoi() {

    runIntake(-100);
    delay(500);
    moveStraight(-100, 300);
    moveStraight(100, 300);
    runIntake(100);
    delay(2000);
    runIntake(0);

}