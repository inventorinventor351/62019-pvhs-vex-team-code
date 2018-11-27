#include "main.h"

void autonBlueFlag(){
    
    drivePD(45, 1000);
    delay(500);
    intake.move(64);

    drivePD(-45, 1000);

    pvitChassis(90, 200, 1);
    autonAimFlag();

    drivePD(-50, 1200);
    drivePD(25, 600);

/*    pvitChassis(-90, 200, 1)

    drivePD(24, 600);

    intake.move(-64);
    delay(500);
    intake.move(0);
    drivePD(-5, 200);*/

}