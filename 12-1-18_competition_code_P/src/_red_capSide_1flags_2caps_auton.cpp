#include "main.h"

void red_capSide_1flags_2caps_auton() {

    //autonShoot();
    pivotChassisBAD(87, 150, 1500);
    driveStraight(-0.78, 1000);
    driveStraight(0.2, 400);
    autonGetBall(-1);
    pivotChassisBAD(-45, 150, 1500);
    intake.move_velocity(-450);
    driveStraight(1, 1000);
    intake.move_velocity(0);
    delay(200);
    driveStraight(-2.6, 2000);
}