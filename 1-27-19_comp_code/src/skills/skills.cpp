#include "main.h"

void skills() {

    runIntake(100);
    moveStraight(1800, 1, 2000); //
    moveStraight(650, -1, 1000);

    pvtBase(-90, 1500);
    moveStraight(1000, 1, 800);
    pvtBase(90, 1200);

    runIntake(-100);
    moveStraight(1640, 1, 1000);
    delay(400);
    moveStraight(2290, -1, 800);
    runIntake(0);

    pvtBase(90, 1000);
    moveStraight(2670, 2000);
    pvtBase(-90, 1000);
    moveStraight(700, -1, 1000);

    //phase 2

    runIntake(80);
    moveStraight(1800, 1, 1600);
    moveStraight(750, -1, 1000);

    pvtBase(90, 1000);
    runIntake(-100);
    moveStraight(1000, 1, 1000);
    runIntake(0);
    moveStraight(1000, -1, 800);

    //phase 3

    pvtBase(90, 1000);
    moveStraight(500, 1, 700);
    pvtBase(90, 1000);
    moveStraight(300, -1, 300);

    flagAimTop();
    flagAimTop();
    delay(100);
    shoot = true;
    delay(200);
    pvtBase(20, 400);
    moveStraight(1800, -1, 1000);

    moveStraight(2950, 1, 2000);
    pvtBase(90, 1500);
    moveStraight(700, -1, 700);
    delay(300);

    runRightBase(100);
    runLeftBase(100);
    delay(2350);
    runRightBase(0);
    runLeftBase(0);

}