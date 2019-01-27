#include "main.h"

void redCap() {

    transPstn.set_value(1);
    runIntake(80);
    moveStraight(1800, 1, 2000);
    moveStraight(800, -1, 1000);
    pvtBase(-90, 2000);
    moveStraight(600, 1, 800);
    pvtBase(75, 1200);
    transPstn.set_value(0);
    runIntake(-100);
    moveStraight(970, 1, 1000);
    moveStraight(400, -1, 800);
    pvtBase(100, 2000);
    runIntake(0);
    moveStraight(1200, 1, 1000);

}