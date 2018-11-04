#include "main.h"

void autonBlueCapLine(){

    autonAimFlag();

    pvitChassis(90, 200, 1);
    driveAbsLeft(45, 200);
    driveAbsRight(45, 200);
    delay(500);
    intake.move(127);

    driveAbsLeft(30, 200);
    driveAbsRight(30, 200);
    intakeLift.set_value(1);
    delay(100);
    intakeLift.set_value(0);

    driveAbsLeft(48, 200);
    driveAbsRight(48, 200);
    
    delay(500);
    intake.move(0);
    intakeLift.set_value(1);

    driveAbsLeft(18, 200);
    driveAbsRight(18, 200);
    pvitChassis(-90, 200, 1);
    driveRelativeLeft(10, 200);
    driveRelativeRight(10, 200);
    delay(100);
    intakeLift.set_value(0);
    intake.move(-127);
    driveRelativeLeft(-34, 200);
    driveRelativeRight(-34, 200);

    pvitChassis(90, 200, 1);
    driveRelativeLeft(20, 100);
    driveRelativeRight(20, 100);
    intake.move(-127);
    delay(500);
    driveRelativeLeft(10, 100);
    driveRelativeRight(10, 100);
    intake.move(127);
    delay(500);
    intakeLift.set_value(1);
    delay(300);

    driveRelativeLeft(-50, 200);
    driveRelativeRight(-50, 200);
    pvitChassis(-90, 200, 1);
    driveRelativeLeft(30, 200);
    driveRelativeRight(30, 200);
    delay(700);
    intakeLift.set_value(0);
    delay(200);
    intake.move(-127);
    driveRelativeLeft(-5, 200);
    driveRelativeRight(-5, 200);

}