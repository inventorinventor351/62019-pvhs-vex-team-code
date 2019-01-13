#include "main.h"

void red_2cap3flag(){
    
    cpltReturn();
    runIntake(80);
    moveStraight(720, 1, 1500);
    moveStraight(720,  -1, 1500);
    runIntake(0);
    pvtBase(90, 1000);
    flagAim();
    moveStraight(300, 1, 1500);
    shoot = true;
    moveStraight(420, 1, 1000);
    moveStraight(420, -1, 1000);
    pvtBase(-90, 800);
    runIntake(-80);
    moveStraight(720, 1, 1500);
    runIntake(0);
}