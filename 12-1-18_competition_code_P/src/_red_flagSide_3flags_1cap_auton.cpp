#include "main.h"

void red_flagSide_3flags_1cap_auton() {

<<<<<<< HEAD
    resetChassisEncoderValue();

    move_absoluteLeftChassis(3.38, 200);
    move_absoluteRightChassis(3.38, 200);

    while(getLeftChassisPosition() < 2.75 && getRightChassisPosition() < 2.75) {
    
        intake.move_velocity(200);
        delay(1);

    }
    
    delay(250);
    intake.move_velocity(0);

    while(getLeftChassisPosition() < 3.38 && getRightChassisPosition() < 3.38) {
    
        delay(1);

    }

    move_absoluteLeftChassis(0, 200);
    move_absoluteRightChassis(0, 200);

    while(getLeftChassisPosition() > 0 && getRightChassisPosition() > 0) {
    
        delay(1);

    }

    pivotChassis(90, 200, 1000);

    resetChassisEncoderValue();
=======
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

    

    



>>>>>>> 15c946952fb3582b77f20b754691a03b1f587766

}