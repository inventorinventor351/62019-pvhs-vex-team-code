#include "main.h"

void blueCap() {

    armSetPoint += 5000;
    moveStraight(1320, 1150);
    moveStraight(-1500, 1150);
    pvtBase(114, 900);
    //moveStraight(-750, 900);
    shoot = true;
    delay(200);
    pvtBase(-30, 300);
    moveStraight(1300, 1200);
    pvtBase(-83, 800);
    moveStraight(650, 425);
    yaBoi();
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