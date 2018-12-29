#include "main.h"

void red_flagSide_3flags_1caps_auton() {
 
    autonGetBall(2.15, -1.78);
    pivotChassisBAD(-90, 150, 1000);
    aimAtFlag();
    catapult.move(127);
    delay(350);

    while(!catabut.get_value())
        catapult.move(90);
        
    catapult.move(0);

    
    driveStraight(-2.5, 1300);
    driveStraight(1, 800);

}