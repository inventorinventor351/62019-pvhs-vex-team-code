#include "main.h"

void skills() {

    runIntk(100);
    moveStraight(1800, 1200);
    moveStraight(-1400, 1100);
    pvtBase(-90, 650);
    runIntk(0);
    shoot = true;
    delay(500);

    moveStraight(-2050, 1400);
    moveStraight(2050, 1400);
    pvtBase(135, 900);
    moveStraight(700, 500);

    yaBoi();
    pvtBase(-45, 500);
    moveStraight(1300, 1100);
    pvtBase(-90, 650);
    moveStraight(500, 400);
    shoot = true;
    moveStraight(-2050, 1400);

    moveStraight(600, 500);
    pvtBase(45, 500);
    moveStraight(500, 400);
    yaBoi();

    moveStraight(2000, 1400);
    pvtBase(-45, 500);
    shoot = true;

    moveStraight(-2050, 1400);
    moveStraight(3000, 2000);
    pvtBase(90, 650);
    runLeftBase(-100);
    runRightBase(-100);
    delay(1700);

}