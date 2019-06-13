#include "main.h"

void redFlag() {

    armSetPoint += 5000;
    moveStraight(1320, 1150);
    moveStraight(-1350, 1350);
    pvtBase(-85, 650);
    moveStraight(-300, 500);
    flagAim();
    shoot = true;
    delay(200);
    pvtBase(15, 1000);
    moveStraight(-1270, 1200);
    moveStraight(800, 850);
    armSetPoint -= 1000;
    pvtBase(90, 1000);
    moveStraight(350, 350);
    armSetPoint += 1500;
    /*pvtBase(10, 200);
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
    shoot = true;*/

}