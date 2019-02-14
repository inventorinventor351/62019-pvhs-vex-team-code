#include "main.h"

void blueCap() {

    runIntk(80);
    moveStraight(1800, 1200);
    moveStraight(-1500, 1150);
    pvtBase(118, 900);
    moveStraight(-920, 900);
    shoot = true;
    pvtBase(-30, 300);
    runIntk(0);
    moveStraight(1600, 1200);
    pvtBase(-83, 800);
    runIntk(-80);
    runLeftBase(100);
    runRightBase(100);
    delay(300);
    runLeftBase(60);
    runRightBase(60);
    delay(500);
    pvtBase(-120, 1000);
    moveStraight(2200, 1500);
    pvtBase(-60, 500);
    runLeftBase(100);
    runRightBase(100);
    delay(300);
    runLeftBase(-100);
    runRightBase(-100);
    delay(1500);
    runLeftBase(0);
    runRightBase(0);

}