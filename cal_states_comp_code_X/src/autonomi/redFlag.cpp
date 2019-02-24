#include "main.h"

void redFlag() {//works

    runIntk(100);
    moveStraight(1800, 1200);
    moveStraight(-1400, 1100);
    pvtBase(-90, 650);
    runIntk(0);
    shoot = true;
    delay(500);

    moveStraight(-2050, 1400);
    moveStraight(750, 650);
    pvtBase(-80, 650);
    moveStraight(-2000, 1400);

    pvtBase(30, 400);
    moveStraight(700, 500);
    yaBoi();
    shoot = true;
    delay(500);

}