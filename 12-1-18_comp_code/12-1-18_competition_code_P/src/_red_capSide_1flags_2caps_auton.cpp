#include "main.h"

void red_capSide_1flags_2caps_auton() {

 /*aimAtFlag();
    catapult.move(127);
    delay(350);

    while(!catabut.get_value())
        catapult.move(90);
        
    catapult.move(0);`
    pivotChassisBAD(-87, 200, 700);// shoot the ball and turn 87 degrees right */
    
    autonGetBall(2.15, -1);
    pivotChassisBAD(90, 150, 800);
    driveStraight(3.1, 2500);

  
    
}