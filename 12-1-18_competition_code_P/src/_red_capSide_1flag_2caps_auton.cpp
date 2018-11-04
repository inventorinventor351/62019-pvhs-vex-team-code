#include "main.h"

void red_capSide_1flag_2caps_auton() {

    autonShoot();//shoot ball
    pivotChassis(-90, 200, 1000);//face cap
    move_absoluteRightChassis(inToRot(42),200); // move to cap
    move_absoluteLeftChassis(inToRot(42),200); // move to cap

    while(leftChassis1.get_position() < inToRot(42) && rightChassis1.get_position() < inToRot(42)) //move intake until u get to the cap
    {
        
        intake.move_velocity(100);

    }

    delay(150);
    intake.move_velocity(0); // pick up cap

    move_absoluteRightChassis(inToRot(0),200);
    move_absoluteLeftChassis(inToRot(0),200); // return to starting spot

    pivotChassis(90, 200, 1); // turn

    move_relativeRightChassis(inToRot(8),200); // go forward a bit
    move_relativeLeftChassis(inToRot(8),200); 
    
    intake.move_relative(-2, 200); // drop cap

    delay(200);

    
}