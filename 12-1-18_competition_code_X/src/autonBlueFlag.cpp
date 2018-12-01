#include "main.h"

void autonBlueFlag(){
    
    drivePD(1.8);
    intake.move(90);
    drivePD(0.59);
    delay(375);
    drivePD(-1.78);
    intakeLift.set_value(1);
    delay(1200);
    intakeLift.set_value(0);
    intake.move(0);
    delay(500);
    pvitChassis(90, 150);
    delay(2000);
    autonAimFlag();
    delay(150);

}