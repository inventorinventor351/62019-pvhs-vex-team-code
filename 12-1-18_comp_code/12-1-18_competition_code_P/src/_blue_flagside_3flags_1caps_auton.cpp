#include "main.h"

void blue_flagSide_3flags_1caps_auton() {

    driveStraight(2.85, 1500);
    intake.move(127);
    driveStraight(-2.85, 1500);
    intakePiston1.set_value(1);
    intakePiston2.set_value(1);
    delay(750);
    intakePiston1.set_value(0);
    intakePiston2.set_value(0);
    pivotChassis(-90, 1000);
    autonShoot();
    driveStraight(3, 1500);

}