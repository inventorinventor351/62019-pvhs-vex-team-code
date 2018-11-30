#include "main.h"

void red_flagSide_3flags_1caps_auton() {

    
    driveStraight(2.32, 1500);
    driveStraight(-1, 500);
    intake.move_velocity(500);
    driveStraight(1.05, 500);
    delay(100);

    driveStraight(-1.95, 1500);
    loadBall(1500);
    intake.move_velocity(0);
    delay(500);
    pivotChassisBAD(-80, 200, 1000);
    autonShoot();
    driveStraight(-3, 1500);


}