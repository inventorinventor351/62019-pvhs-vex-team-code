#include "main.h"

void blueCap() {

    runIntake(100);
    moveStraight(1800, 2000);
    moveStraight(-650, 1000);
    pvtBase(90, 1500);
    transPstn.set_value(1);
    delay(450);
    moveStraight(600, 800);
    pvtBase(-68, 1200);
    runIntake(-100);
    moveStraight(1040, 1000);
    delay(400);
    moveStraight(-760, 800);
    runIntake(0);
    /*pvtBase(-111, 2100);
    runRightBase(100);
    runLeftBase(100);
    delay(2350);
    runRightBase(0);
    runLeftBase(0);*/

}