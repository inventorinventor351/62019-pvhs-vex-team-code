#include "main.h"

void redFlag(){
    
    runIntk(80);
    moveStraight(1800, 1600);

    moveStraight(-650, 1000);
    pvtBase(90, 1000);
    runIntk(-100);
    moveStraight(1200, 1000);
    runIntk(100);

    moveStraight(-1200, 1000);
    pvtBase(90, 1000);
    moveStraight(600, 700);
    pvtBase(90, 1000);
    moveStraight(-400, 300);
    flagAim();
    flagAim();
    delay(100);
    shoot = true;
    delay(200);
    runIntk(0);

    pvtBase(15, 500);
    moveStraight(-1800, 1000);
    moveStraight(1000, 1000);
    
}