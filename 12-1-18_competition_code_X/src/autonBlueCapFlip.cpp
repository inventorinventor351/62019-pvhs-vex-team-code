#include "main.h"

void autonBlueCapFlip(){

    drivePD(35, 2000);
    delay(500);
    intake.move(90);
    delay(2000);
    intake.move(0);

    drivePD(-5, 2000);

    pvitChassis(70, 200);
    drivePD(20, 2000);
    intake.move(-90);
    delay(2000);
    intake.move(0);
    drivePD(-20, 2000);
    
    pvitChassis(20, 200);
    drivePD(-30, 2000);

    aimFlag();
    shooter.move_relative(1, 200);

}