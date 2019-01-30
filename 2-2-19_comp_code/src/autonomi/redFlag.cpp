#include "main.h"

void redFlag(){
    
    runIntake(80);
    moveStraight(1800, 1, 1600);

    moveStraight(750, -1, 1000);
    pvtBase(90, 1000);
    runIntake(-100);
    moveStraight(1000, 1, 1000);
    runIntake(0);

    /*pvtBase(110, 1000);
    flagAim();
    shoot = true;
    pvtBase(140);
    moveStraight(1);
    moveStraight(-1);
    pvtBase(-30);
    getBall(1000);
    moveStraight(-1);
    getBall(1000);
    runLeftBase(100);
    runRightBase(100);
    delay(200);
    runLeftBase(0);
    runRightBase(0);*/
    
    moveStraight(1000, -1, 800);
    pvtBase(90, 1000);
    moveStraight(500, 1, 700);
    pvtBase(90, 1000);
    moveStraight(300, -1, 300);
    flagAimTop();
    flagAimTop();
    delay(100);
    shoot = true;
    delay(200);

    pvtBase(20, 400);
    moveStraight(1800, -1, 1000);
    moveStraight(1800, 1, 1000);
    
}