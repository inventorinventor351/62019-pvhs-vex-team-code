#include "main.h"

void autonBlueFlag(){
    
    /*drivePD(45, 2000);
    delay(500);
    intake.move(64);

    drivePD(-45, 2000);

    pvitChassis(90, 200);
    autonAimFlag();

    drivePD(-50, 2000);
    drivePD(25, 2000);

    pvitChassis(-90, 200)

    drivePD(24);

    intake.move(-64);
    delay(500);
    intake.move(0);
    drivePD(-5);*/

    intakeLift.set_value(0);
    intake.move(90);
    drivePD(40);
    delay(1000);

    intakeLift.set_value(1);
    drivePD(-35);
    delay(1000);
    intake.move(0);
    intakeLift.set_value(0);

    pvitChassis(90, 200);
    autonAimFlag();
    delay(200);

}