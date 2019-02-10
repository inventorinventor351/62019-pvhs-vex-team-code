#include "main.h"

void redCap() {

<<<<<<< HEAD
    /*shoot = true;
=======
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
>>>>>>> ad8992ed401751d6d6edced3dafc11b669f2f614
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
    moveStraight(575, 800);
    pvtBase(67, 1250);
    runIntake(-100);
    moveStraight(1000, 1250);
    delay(300);
    moveStraight(-640, 800);
    runIntake(0);
<<<<<<< HEAD
    pvtBase(120, 2100);
=======
    pvtBase(140, 2000);
>>>>>>> ad8992ed401751d6d6edced3dafc11b669f2f614
    runRightBase(100);
    runLeftBase(100);
    delay(2350);
    runRightBase(0);
    runLeftBase(0);*/

    runIntake(100);
    moveStraight(1800, 2000);
    moveStraight(-650, 1000);
    pvtBase(-90, 1500);
    transPstn.set_value(1);
    delay(450);
    moveStraight(600, 800);
    pvtBase(67, 1200);
    runIntake(-100);
    moveStraight(940, 1000);
    delay(400);
    moveStraight(-700, 800);
    runIntake(0);
    pvtBase(115, 2100);
    runRightBase(100);
    runLeftBase(100);
    delay(2350);
    runRightBase(0);
    runLeftBase(0);

}