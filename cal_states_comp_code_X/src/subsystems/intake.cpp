#include "main.h"

void runIntk(float voltPerc) {

    intk.move_voltage((voltPerc / 100) * 12000);

}

void yaBoi() {

    runIntk(-100);
    delay(300);
    moveStraight(-100, 200);
    moveStraight(100, 200);
    runIntk(100);
    delay(500);
    runIntk(0);

}