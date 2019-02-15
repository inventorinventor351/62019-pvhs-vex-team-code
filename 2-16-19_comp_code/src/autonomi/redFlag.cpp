#include "main.h"

void redFlag(){
    
    runIntk(80);
    moveStraight(1800, 1200);

    moveStraight(-550, 500);
    pvtBase(90, 700);
    runIntk(-60);
    runLeftBase(60);
    runRightBase(60);
    delay(700);
    runIntk(100);

    moveStraight(-800, 800);
    pvtBase(90, 700);
    moveStraight(700, 700);
    pvtBase(90, 700);
    flagAim();
    delay(50);
    shoot = true;
    delay(100);
    runIntk(0);

    runLeftBase(-100);
    runRightBase(-100);
    delay(1000);
    runLeftBase(0);
    runRightBase(0);
    delay(100);
    moveStraight(3200, 2100);
    pvtBase(-90, 700);
    runLeftBase(100);
    runRightBase(100);
    delay(300);
    runLeftBase(0);
    runLeftBase(0);
    delay(100);
    runLeftBase(-100);
    runRightBase(-100);
    delay(1300);
    runLeftBase(0);
    runRightBase(0);
    
}