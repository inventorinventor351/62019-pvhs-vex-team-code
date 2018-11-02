#include "main.h"

void autonBlueFlag(){
    
    driveAbsLeft(45, 200);
    driveAbsRight(45, 200);
    delay(500);
    intake.move(127);
    delay(1500);

    driveAbsLeft(0, 200);
    driveAbsRight(0, 200);

    pvitChassis(90, 200, 1);
    aimFlag();
    shooter.move_relative(1, 200);

    driveRelativeLeft(50, 200);
    driveRelativeRight(50, 200);

    driveRelativeLeft(-25, 200);
    driveRelativeLeft(-25, 200);

/*    pvitChassis(-90, 200, 1)

    driveRelativeLeft(24, 200);
    driveRelativeRight(24, 200);

    intake.move(-127);
    delay(500);
    driveRelativeLeft(-5, 200);
    driveRelativeRight(-5, 200);*/

}