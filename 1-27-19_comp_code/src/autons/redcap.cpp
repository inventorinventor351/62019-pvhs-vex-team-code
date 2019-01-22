#include "main.h"

void redCap() {

    transPstn.set_value(1);
    //cpltReturn();
    runIntake(80);
    moveStraight(1800, 1, 2000);
    moveStraight(800, -1, 1000);
    pvtBase(-90, 2000);
    moveStraight(800, 1, 800);
    pvtBase(85, 1200);
    runIntake(-100);
    moveStraight(950, 1, 900);
    moveStraight(600, -1, 800);
    pvtBase(100, 2000);
    runIntake(0);
    moveStraight(1200, 1, 1000);

}