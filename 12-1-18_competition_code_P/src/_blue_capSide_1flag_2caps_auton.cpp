#include "main.h"

void red_capSide_1flag_2caps_auton() {

    autonShoot();//shoot ball
    pivotChassis(90, 200, 1000);//face cap
    move_absoluteRightChassis(IntoRot(42),200); // move to cap
    move_absoluteLeftChassis(IntoRot(42),200); // move to cap

    while(leftChassis1.get_position() < IntoRot(42) && rightChassis1.get_position() < IntoRot(42)) //move intake until u get to the cap
    {
        
        intake.move_velocity(100);

    }

    delay(150);
    intake.move_velocity(0); // pick up ball

    move_absoluteRightChassis(IntoRot(40), 200)//move back a tad
    move_absoluteLefttChassis(IntoRot(40), 200)

    intakePiston1.set_value(1);// load ball
    intakePiston2.set_value(1);//load ball

    delay(250);

    intakePiston1.set_value(0);// reset
    intakePiston2.set_value(0);// reset

    move_absoluteRightChassis(IntoRot(42), 200)//move forward a tad
    move_absoluteLefttChassis(IntoRot(42), 200)

    intake.move_velocity(200);
    delay(200);
    intake.move_velocity(0);

    move_absoluteRightChassis(IntoRot(0),200);
    move_absoluteLeftChassis(IntoRot(0),200); // return to starting spot

    pivotChassis(-90, 200, 1); // turn

    move_relativeRightChassis(IntoRot(8),200); // go forward a bit
    move_relativeLeftChassis(IntoRot(8),200); 
    
    intake.move_relative(-2, 200); // drop cap

    delay(200);

    move_voltageLeftChassis(-12000);
    move_voltageRightChassis(-12000);
    delay(1000);
    move_voltageLeftChassis(0);
    move_voltageRightChassis(0);

    pivotChassis(90, 200, 100);

    resetChassisEncoderValue();

    move_relativeLeftChassis(42, 200);
    move_relativeRightChassis(42, 200);

     while(leftChassis1.get_position() < IntoRot(42) && rightChassis1.get_position() < IntoRot(42)) //move intake until u get to the cap
    {
        
        intake.move_velocity(-200);

    }

    delay(200);
    intake.move_velocity(100);

    move_relativeLeftChassis(inToRot(5), 200);
    move_relativeRightChassis(inToRot(5), 200);

    delay(150);

    intake.move_velocity(0);

    move_relativeRightChassis(inToRot(-38), 200);
    move_relativeLeftChassis(inToRot(-38), 200);

    pivotChassis(-90, 200, 200);
    
    move_relativeRightChassis(inToRot(48), 200);
    move_relativeLeftChassis(inToRot(48), 200);

    intake.move_velocity(-200);
    delay(150);
    intake.move_velocity(0);
    
}