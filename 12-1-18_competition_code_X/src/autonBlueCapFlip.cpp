#include "main.h"

void autonBlueCapFlip(){

    drivePD(45, 1000);
    delay(500);
    intake.move(64);
    delay(2000);
    intake.move(0);

    drivePD(-5, 100);

    pvitChassis(70, 200, 0.77778);
    drivePD(20, 500);
    intake.move(-64);
    delay(2000);
    intake.move(0);
    drivePD(-20, 500);
    
    pvitChassis(20, 200, 0.222222);
    drivePD(-30, 500);

    aimFlag();
    shooter.move_relative(1, 200);

}