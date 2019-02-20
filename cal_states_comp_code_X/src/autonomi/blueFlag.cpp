#include "main.h"

void blueFlag() {

    runIntk(100);
    moveStraight(1800, 1200);
    moveStraight(-1500, 1150);
    pvtBase(90, 650);
    moveStraight(-700, 600);
    shoot = true;
    delay(500);
    runIntk(0);

    moveStraight(-1100, 900);
    moveStraight(600, 500);
    pvtBase(75, 600);
    moveStraight(-2000, 1300);

    pvtBase(-30, 400);
    moveStraight(1200, 1000);
    yaBoi();
    shoot = true;
    delay(500);

}