#include "main.h"

void red_flagSide_3flags_1cap_auton() {

    autonShoot();//shoot ball
    move_absoluteRightChassis(IntoRot(42),200); // move to cap
    move_absoluteLeftChassis(IntoRot(42),200); // move to cap

    while(leftChassis1.get_position() < IntoRot(42) && rightChassis1.get_position() < IntoRot(42)) //move intake until u get to the cap
    {
        
        intake.move_velocity(100);

    }

    delay(150);
    intake.move_velocity(0); // pick up cap

    move_absoluteRightChassis(IntoRot(0),200);
    move_absoluteLeftChassis(IntoRot(0),200); // return to starting spot

    pivotChassis(90, 200, 1); // turn

    move_relativeRightChassis(IntoRot(8),200); // go forward a bit
    move_relativeLeftChassis(IntoRot(8),200); 
    
    intake.move_relative(-2, 200) // drop cap

    delay(200);

    

    




}