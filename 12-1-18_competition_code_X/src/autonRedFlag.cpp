#include "main.h"

void autonRedFlag(){
    
    drivePD(45, 1000);
    delay(500);
    intake.move(127);

    drivePD(-45, 1000);

    pvitChassis(-90, 200, 1);
    autonAimFlag();

    drivePD(-50, 1200);

    drivePD(25, 500);

/*    pvitChassis(90, 200, 1);

    drivePD(24, 500);

    intake.move(-127);
    delay(500);
    intake.move(0);
    drivePD(-5, 100);*/

}