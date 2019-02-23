#include "main.h"

void redCap() {

    runIntk(80);
    moveStraight(1800, 1200);
    moveStraight(-1500, 1150);
    pvtBase(-118, 900);
    moveStraight(-920, 900);
    shoot = true;

    pvtBase(118, 900);
    runIntk(-100);
    delay(500);
    pvtBase(-90, 650);
    runIntk(100);
    moveStraight(2000, 1500);
    pvtBase(-10, 300);
    shoot = true;
    runIntk(0);

    pvtBase(100, 700);
    moveStraight(1000, 800);
    //yaBoi();
    pvtBase(-150, 1000);
    moveStraight(1200, 1000);
    shoot = true;
    delay(500);

}