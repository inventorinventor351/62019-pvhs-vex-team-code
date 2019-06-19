#include "main.h"

void skills() {

    runIntk(100);
    moveStraight(1800, 1800);
    moveStraight(-1800, 1800);

    moveStraight(400, 800);
    pvtBase(-90, 1500);
    moveStraight(-400, 600);
    shoot = true;
    delay(2000);

    moveStraight(2300, 2300);
    pvtBase(90, 1500);
    runLeftBase(-50);
    runRightBase(-50);
    delay(500);
    runLeftBase(0);
    runRightBase(0);
    moveStraight(1800, 1800);
    moveStraight(-1800, 1800);

    moveStraight(400, 600);
    pvtBase(90, 1500);
    moveStraight(2000, 2000);
    pvtBase(90, 1500);
    moveStraight(-1400, 1500);
    pvtBase(90, 1500);
    moveStraight(300, 500);
    moveStraight(-500, 700);
    pvtBase(-25, 500);
    shoot = true;
    delay(500);
    runIntk(0);

    pvtBase(-20, 500);
    moveStraight(1900, 2000);
    pvtBase(-50, 1000);
    moveStraight(-800, 700);
    moveStraight(500, 700);
    runLeftBase(-100);
    runRightBase(-100);
    delay(2500);
    runLeftBase(0);
    runRightBase(0);

}