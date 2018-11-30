#include "main.h"

void red_flagSide_3flags_1caps_auton() {

    
    driveStraight(2.32, 1500);
    driveStraight(-.6, 500);
    intake.move_velocity(500);
    driveStraight(1.1, 500);
    delay(100);

    driveStraight(-1.78, 1000);
    loadBall(1500);
    intake.move_velocity(0);
    delay(500);
    pivotChassisBAD(-85, 200, 1000);
    autonShoot();
    delay(150);
    driveStraight(-3, 1500);

}