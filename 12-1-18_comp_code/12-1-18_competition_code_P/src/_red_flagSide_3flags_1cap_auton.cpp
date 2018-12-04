#include "main.h"

void red_flagSide_3flags_1caps_auton() {

    
    autonGetBall(1.8, -1.78);

    delay(500);
    pivotChassisBAD(-60, 200, 1000);
    autonShoot();
    delay(150);
    pivotChassisBAD(-13, 150, 2000);
    driveStraight(-3, 1500);

}