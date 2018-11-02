#include "main.h"

void autonBlueCapLine(){

    shooter.move_relative(1, 200);

    pvitChassis(90, 200, 1)
    driveAbsLeft(45, 200);
    driveAbsRight(45, 200);
    delay(500);
    move.intake(127);
    delay(200);

    driveAbsLeft(30, 200);
    driveAbsRight(30, 200);

    driveAbsLeft(48, 200);
    driveAbsRight(48, 200);
    
    delay(500);
    move.intake(0);
    intakeLift.set_value(1);
    intakeLift1.set_value(1);

    driveAbsLeft(24, 200);
    driveAbsRight(24, 200);
    pvitChassis(-90, 200, 1);
    driveRelativeLeft(20, 200);
    driveRelativeRight(20, 200);
    delay(100);
    intakeLift.set_value(0);
    intakeLift1.set_value(0);
    move.intake(-127);
    driveRelativeLeft(-30, 200);
    driveRelativeRight(-30, 200);

    pvitChassis(90, 200, 1);
    driveRelativeLeft(30, 100);
    driveRelativeRight(30, 100);
    move.intake(-127);
    delay(500);
    move.intake(127);
    intakeLift.set_value(0);
    intakeLift1.set_value(0);
    delay(300);

    driveRelativeLeft(-50, 200);
    driveRelativeRight(-50, 200);
    pvitChassis(-90, 200, 1);
    driveRelativeLeft(30, 200);
    driveRelativeRight(30, 200);
    intakeLift.set_value(0);
    intakeLift.set_value(0);
    move.intake(-127);
    driveRelativeLeft(-10, 200);
    driveRelativeRight(-10, 200);

}