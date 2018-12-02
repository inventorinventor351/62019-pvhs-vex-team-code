#include "main.h"

void blue_capSide_1flags_2caps_auton() {

    autonShoot();
    pivotChassis(90, 500);
    intake.move_velocity(127);
    driveStraight(2.85, 1000);
    delay(150);
    intake.move_velocity(0);
    driveStraight(-0.5, 500);
    loadBall(750);
    pivotChassis(70, 500);
    intake.move_velocity(-63.5);
    driveStraight(1, 1000);
    intake.move_velocity(0);
    
}