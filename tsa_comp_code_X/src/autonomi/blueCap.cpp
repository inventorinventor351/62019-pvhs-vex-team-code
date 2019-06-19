#include "main.h"

void blueCap() {

    runIntk(100);
    moveStraight(1800, 1800);
    moveStraight(-1800, 1800);

    moveStraight(400, 800);
    pvtBase(90, 1500);
    moveStraight(-400, 600);
    shoot = true;
    delay(2000);

    moveStraight(-1500, 1500);
    moveStraight(700, 800);
    pvtBase(-90, 1200);
    runIntk(-100);
    moveStraight(2000, 2000);

}