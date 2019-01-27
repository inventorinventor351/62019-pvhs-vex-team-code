#include "main.h"

void blueFlag(){
    
    runIntake(80);
    moveStraight(1600, 1, 1800);

    moveStraight(750, -1, 500);
    pvtBase(-90, 1500);
    runIntake(-100);
    moveStraight(800, 1, 2500);
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
    
    moveStraight(800, -1, 2500);
    pvtBase(-90, 1700);
    moveStraight(600, 1, 1800);
    pvtBase(-90, 2000);
    moveStraight(600, -1, 800);
    flagAimTop();
    delay(300);
    shoot = true;
    delay(500);

    pvtBase(10, 500);
    moveStraight(1800, -1, 1000);
    moveStraight(1800, 1, 1000);
    
}