#include "main.h"

void autonRedCapFlip(){

    intake.move(90);
    drivePD(40);
    intakeLift.set_value(1);
    drivePD(-5);
    intakeLift.set_value(0);

    pvitChassis(-70, 200);
    drivePD(20);
    intake.move(-64);
    delay(2000);
    intake.move(0);
    drivePD(-20);
    
    pvitChassis(-20, 200);
    drivePD(-30);

    aimFlag();
    drivePD(5);

}