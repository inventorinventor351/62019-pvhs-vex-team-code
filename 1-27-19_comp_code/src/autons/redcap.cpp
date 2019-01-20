#include "main.h"

void redCap() {

    transPstn.set_value(1);
    //cpltReturn();
    runIntake(80);
    moveStraight(1800, 1, 1200);
    moveStraight(800, -1, 800);
    pvtBase(-90, 1200);
    moveStraight(800, 1, 800);
    pvtBase(72, 1200);
    runIntake(-100);
    moveStraight(930, 1, 900);
    /*runIntake(0);
    moveStraight(600, -1, 800);
    pvtBase(90, 1000);
    moveStraight(2, 1, 1000);*/

}