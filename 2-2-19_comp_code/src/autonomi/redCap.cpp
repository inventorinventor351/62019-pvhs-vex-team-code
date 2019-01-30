#include "main.h"

void redCap() {

    runIntake(100);
    moveStraight(1800, 2000);
    moveStraight(-650, 1000);
    pvtBase(-90, 1500);
    transPstn.set_value(1);
    delay(450);
    moveStraight(600, 800);
    pvtBase(67, 1200);
    runIntake(-100);
    moveStraight(1040, 1000);
    delay(400);
    moveStraight(-760, 800);
    runIntake(0);
    /*pvtBase(103, 2100);
    runRightBase(100);
    runLeftBase(100);
    delay(2350);
    runRightBase(0);
    runLeftBase(0);*/

}