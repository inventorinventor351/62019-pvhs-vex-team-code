#include "main.h"

void blueFlag(){
    
    runIntk(100);
    moveStraight(1800, 1200);

    moveStraight(-550, 500);
    pvtBase(-90, 650);
    runIntk(-60);
    runLeftBase(60);
    runRightBase(60);
    delay(1000);
    runIntk(100);

    moveStraight(-800, 800);
    pvtBase(-90, 650);
    moveStraight(700, 700);
    pvtBase(-90, 650);
    flagAim();
    delay(800);
    shoot = true;
    delay(500);
    runIntk(0);

    runLeftBase(-100);
    runRightBase(-100);
    delay(1000);
    runLeftBase(0);
    runRightBase(0);
    /*delay(100);
    moveStraight(2600, 1600);
    runLeftBase(100);
    runRightBase(0);
    delay(600);
    runLeftBase(-100);
    runRightBase(-100);
    delay(1300);
    runLeftBase(0);
    runRightBase(0);*/
    
}