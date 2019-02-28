#include "main.h"

void redFlag() {//works

    armSetPoint += 5000;
    moveStraight(1300, 1100);
    moveStraight(-1350, 1300);
    pvtBase(-85, 650);

    moveStraight(-600, 500);
    shoot = true;
    delay(200);
    moveStraight(-1450, 1100);
    moveStraight(500, 500);
    pvtBase(-80, 650);
    moveStraight(-1600, 1200);

    pvtBase(44, 400);
    moveStraight(230, 500);
    yaBoi();
    delay(3500);
    armSetPoint -= 1000;
    delay(1000);
    moveStraight(600, 500);
    shoot = true;
    armSetPoint += 1500;

}