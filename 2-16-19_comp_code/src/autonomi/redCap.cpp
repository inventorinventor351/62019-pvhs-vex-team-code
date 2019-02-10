#include "main.h"

void redCap() {

    runIntk(80);
    moveStraight(1800, 1600);
    moveStraight(-1500, 1500);
    pvtBase(-120, 1200);
    moveStraight(-500, 700);
    shoot = true;
    pvtBase(30, 500);
    runIntk(0);
    moveStraight(1400, 1400);
    pvtBase(90, 1000);
    runIntk(-100);
    moveStraight(700, 900);
    moveStraight(2000, 1750);
    pvtBase(-90, 1000);
    moveStraight(-1400, 1400);
    pvtBase(-90, 1000);
    runLeftBase(100);
    runRightBase(100);
    delay(2000);
    runLeftBase(0);
    runRightBase(0);

}