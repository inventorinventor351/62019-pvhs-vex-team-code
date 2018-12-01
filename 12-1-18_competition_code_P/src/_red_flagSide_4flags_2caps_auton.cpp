#include "main.h"

void red_flagSide_4flags_2caps_auton() {

    autonGetBall(1.8, -1.78);
    pivotChassisBAD(90, 150, 1000);
    autonShoot();

    driveStraight(2.5, 1300);
    driveStraight(-1, 800);

    pivotChassisBAD(-90, 150, 500);
    intake.move_velocity(-380);
    driveStraight(2.5, 2000);
    intake.move_velocity(0);
    
    pivotChassisBAD(90, 150, 750);
    driveStraight(0.8, 1000);

}