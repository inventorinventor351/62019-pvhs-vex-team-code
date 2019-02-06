#include "main.h"

void redCap() {

    /*moveStraight(400, 400);
    pvtBase(70, 1000);
    moveStraight(-200, 300);
    shoot = true;
    moveStraight(200, 300);
    pvtBase(-70, 1000);
    runIntake(100);
    moveStraight(1400, 1200);
    moveStraight(-400, 400);
    pvtBase(40, 500);
    moveStraight(100, 200);
    shoot = true;
    runIntake(0);
    moveStraight(-800, 800);
    pvtBase(-40, 500);
    runIntake(-80);
    moveStraight(800, 800);
    moveStraight(-400, 500);*/

    ///shoot = true;
    delay(300);
    pvtBase(120, 1000);
    runLeftBase(-100);
    runRightBase(-100);
    delay(750);
    runLeftBase(0);
    runRightBase(0);
    runIntake(80);
    moveStraight(1800, 1600);
    moveStraight(-590, 1000);
    pvtBase(-90, 1000);
    transPstn.set_value(0);
    delay(450);
    moveStraight(575, 800);
    pvtBase(67, 1250);
    runIntake(-100);
    moveStraight(1250, 1250);
    delay(300);
    moveStraight(-640, 800);
    runIntake(0);
    pvtBase(140, 2000);
    runRightBase(100);
    runLeftBase(100);
    delay(2350);
    runRightBase(0);
    runLeftBase(0);

    /*runIntake(100);
    moveStraight(1800, 2000);
    moveStraight(-650, 1000);
    pvtBase(-90, 1500);
    transPstn.set_value(1);
    delay(450);
    moveStraight(600, 800);
    pvtBase(67, 1200);
    runIntake(-100);
    moveStraight(1040, 1000);
    delay(400);
    moveStraight(-760, 800);
    runIntake(0);
    pvtBase(103, 2100);
    runRightBase(100);
    runLeftBase(100);
    delay(2350);
    runRightBase(0);
    runLeftBase(0);*/

}