#include "main.h"

void autonRedCapFlip(){

    driveAbsLeft(45, 200);
    driveAbsRight(45, 200);
    delay(500);
    intake.move(127);
    delay(2000);
    intake.move(0);

    driveAbsLeft(40, 200);
    driveAbsRight(40, 200);

    pvitChassis(-70, 200, 0.77778);
    driveRelativeLeft(20, 200);
    driveRelativeRight(20, 200);
    intake.move(-127);
    delay(2000);
    intake.move(0);
    driveRelativeLeft(-20, 200);
    driveRelativeRight(-20, 200);
    
    pvitChassis(-20, 200, 0.222222);
    driveRelativeLeft(-30, 200);
    driveRelativeRight(-30, 200);

    aimFlag();
    shooter.move_relative(1, 200);

}