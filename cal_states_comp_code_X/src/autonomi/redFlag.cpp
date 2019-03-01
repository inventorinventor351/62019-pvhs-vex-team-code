#include "main.h"

void redFlag() {

    armSetPoint += 5000;
    moveStraight(1300, 1100);
    moveStraight(-1330, 1300);
    pvtBase(-85, 650);

    moveStraight(-600, 500);
    shoot = true;
    delay(200);
    moveStraight(-1450, 1100);
    pvtBase(10, 200);
    moveStraight(500, 500);
    pvtBase(-80, 600);
    moveStraight(-1700, 1200);

    pvtBase(40, 400);
    moveStraight(400, 500);
    yaBoi();
    armSetPoint -= 2500;
    delay(1500);
    armSetPoint += 2500;
    delay(2000);
    flagAim();
    shoot = true;

}