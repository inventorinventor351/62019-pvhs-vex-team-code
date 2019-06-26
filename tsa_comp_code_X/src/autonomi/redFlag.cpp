#include "main.h"

void redFlag() {

    runIntk(100);
    moveStraight(1800, 1800);
    moveStraight(-1800, 1800);

    moveStraight(350, 800);
    pvtBase(-90, 1200);
    moveStraight(-400, 600);
    shoot = true;
    delay(500);

    moveStraight(-1700, 1500);
    moveStraight(900, 1000);
    pvtBase(90, 1200);
    runIntk(-100);
    moveStraight(1500, 1500);
    delay(2000);
    runIntk(0);

}