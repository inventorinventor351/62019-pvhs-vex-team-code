#include "main.h"

void blueCap() {

    runIntake(100);
    moveStraight(1800, 1, 2000);
    moveStraight(650, -1, 1000);
    pvtBase(90, 1500);
    transPstn.set_value(1);
    delay(450);
    moveStraight(600, 1, 800);
    pvtBase(-68, 1200);
    runIntake(-100);
    moveStraight(1040, 1, 1000);
    delay(400);
    moveStraight(760, -1, 800);
    runIntake(0);
    /*pvtBase(-111, 2100);
    runRightBase(100);
    runLeftBase(100);
    delay(2350);
    runRightBase(0);
    runLeftBase(0);*/

}