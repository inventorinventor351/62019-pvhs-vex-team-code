#include "main.h"

void autonRedFlag(){
    
    drivePD(45, 2000);
    delay(500);
    intake.move(64);

    drivePD(-45, 2000);

    pvitChassis(-90, 200);
    autonAimFlag();

    drivePD(-50, 2000);

    drivePD(25, 2000);

/*    pvitChassis(90, 200);

    drivePD(24, 2000);

    intake.move(-64);
    delay(500);
    intake.move(0);
    drivePD(-5, 2000);*/

}