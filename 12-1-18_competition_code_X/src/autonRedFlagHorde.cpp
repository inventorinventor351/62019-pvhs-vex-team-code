#include "main.h"

void autonRedFlagHorde(){

    autonAimFlag();
    pvitChassis(90, 200, 1);

    driveAbsLeft(45, 200);
    driveAbsRight(45, 200);
    intake.move(127);
    driveAbsLeft(35, 200);
    driveAbsRight(35, 200);
    intakeLift.set_value(1);
    delay(100);
    intakeLift.set_value(0);
    driveAbsLeft(48, 200);
    driveAbsRight(48, 200);
    delay(300);
    intake.move(0);
    intakeLift.set_value(1);

    pvitChassis(90, 200, 1); //Check to see if this flips the lower flag in the middle?
    driveRelativeLeft(30, 200);
    driveRelativeRight(30, 200);
    delay(300);
    intakeLift.set_value(0);
    delay(100);
    intake.move(-127);

    driveRelativeLeft(-6, 200);
    driveRelativeRight(-6, 200);
    pvitChassis(90, 200, 1);
    driveRelativeLeft(5, 100);
    driveRelativeRight(5, 100);
    intake.move(-127);
    delay(200);
    intake.move(127);
    driveRelativeLeft(5, 100);
    driveRelativeRight(5, 100);
    delay(300);
    intake.move(0);
    intakeLift.set_value(1);
    
    driveRelativeLeft(-5);
    driveRelativeRight(-5);
    pvitChassis(-90, 200, 1);
    driveRelativeLeft(6, 200);
    driveRelativeRight(-6, 200);

    //Try to do the op synergy rest of auton?

}