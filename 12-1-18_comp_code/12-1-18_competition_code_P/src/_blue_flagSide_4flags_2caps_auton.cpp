#include "main.h"

void blue_flagSide_4flags_2caps_auton() {

    intake.move_velocity(127);
    driveStraight(2.85, 1500);
    delay(100);
    intake.move_velocity(0);
    driveStraight(-2.85, 1500);

    loadBall(750);
    pivotChassis(-90, 1000);
    autonShoot();

    driveStraight(2.5, 1500);
    driveStraight(-1, 1500);

    pivotChassis(90, 500);
    intake.move_velocity(-63.5);
    driveStraight(3, 2000);
    intake.move_velocity(127);
    driveStraight(0.75, 500);
    intake.move_velocity(0);
    
    pivotChassis(-125, 750);
    driveStraight(1.5, 1000);
    runintake(-127, 400);


}