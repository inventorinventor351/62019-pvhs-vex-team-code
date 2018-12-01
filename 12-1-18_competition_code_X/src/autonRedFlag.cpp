#include "main.h"

void autonRedFlag(){
    
    intakeLift.set_value(0);
    intake.move(90);
    drivePD(40);
    delay(1000);

    intakeLift.set_value(1);
    drivePD(-35);
    delay(1000);
    intake.move(0);
    intakeLift.set_value(0);

    pvitChassis(-90, 200);
    autonAimFlag();

    /*drivePD(-50);

    drivePD(25);

    pvitChassis(90, 200);

    drivePD(24, 2000);

    intake.move(-64);
    delay(500);
    intake.move(0);
    drivePD(-5, 2000);*/

}