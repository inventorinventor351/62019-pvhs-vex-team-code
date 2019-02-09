#include "main.h"

void blueFlag(){
    
    runIntake(80);
    moveStraight(1800, 1600);

    moveStraight(-650, 1000);
    pvtBase(-90, 1000);
    runIntake(-100);
    moveStraight(1200, 1000);
    runIntake(100);

    moveStraight(-1200, 1000);
    pvtBase(-90, 1000);
    moveStraight(600, 700);
    pvtBase(-90, 1000);
    moveStraight(-400, 300);
    flagAim(1);
    flagAim(1);
    delay(100);
    shoot = true;
    delay(200);
    runIntake(0);

    pvtBase(-15, 500);
    moveStraight(-1800, 1000);
    moveStraight(1000, 1000);
    
}