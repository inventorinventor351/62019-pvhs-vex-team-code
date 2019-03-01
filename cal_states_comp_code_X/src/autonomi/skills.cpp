#include "main.h"

void skills() {

    armSetPoint += 5000;
    moveStraight(1300, 1100);
    moveStraight(-1350, 1300);
    pvtBase(-85, 650);

    moveStraight(-600, 500);
    shoot = true;
    delay(200);
    moveStraight(-1450, 1100);
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