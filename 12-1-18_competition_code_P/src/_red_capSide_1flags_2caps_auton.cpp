#include "main.h"

void red_capSide_1flags_2caps_auton() {

    //autonShoot(1.0, 0.01);//shoot ball
    pivotChassisBAD(-90, 100, 1000);//face cap
    move_absoluteRightChassis(inToRot(42),100); // move to cap
    move_absoluteLeftChassis(inToRot(42),100); // move to cap

    while(leftChassis1.get_position() < inToRot(42) && rightChassis1.get_position() < inToRot(42)) //move intake until u get to the cap
    {
        
        intake.move_velocity(100);

    }

    delay(150);
    intake.move_velocity(0); // pick up ball

    move_absoluteRightChassis(inToRot(40), 100); //move back a tad
    move_absoluteLeftChassis(inToRot(40), 100);

    intakePiston1.set_value(1);// load ball
    intakePiston2.set_value(1);//load ball

    delay(250);

    intakePiston1.set_value(0);// reset
    intakePiston2.set_value(0);// reset

    move_absoluteRightChassis(inToRot(42), 100);//move forward a tad
    move_absoluteLeftChassis(inToRot(42), 100);

    intake.move_velocity(200);
    delay(200);
    intake.move_velocity(0);

    move_absoluteRightChassis(inToRot(0),100);
    move_absoluteLeftChassis(inToRot(0),100); // return to starting spot

    pivotChassisBAD(90, 100, 1000); // turn

    move_relativeRightChassis(inToRot(8),100); // go forward a bit
    move_relativeLeftChassis(inToRot(8),100); 
    
    intake.move_relative(-2, 200); // drop cap

    delay(200);

    move_voltageLeftChassis(-6000);
    move_voltageRightChassis(-6000);
    delay(1000);
    move_voltageLeftChassis(0);
    move_voltageRightChassis(0);

    pivotChassisBAD(-90, 100, 1000);

    resetChassisEncoderValue();

    move_relativeLeftChassis(42, 100);
    move_relativeRightChassis(42, 100);

     while(leftChassis1.get_position() < inToRot(42) && rightChassis1.get_position() < inToRot(42)) //move intake until u get to the cap
    {
        
        intake.move_velocity(-200);

    }

    delay(200);
    intake.move_velocity(100);

    move_relativeLeftChassis(inToRot(5), 100);
    move_relativeRightChassis(inToRot(5), 100);

    delay(150);

    intake.move_velocity(0);

    move_relativeRightChassis(inToRot(-38), 200);
    move_relativeLeftChassis(inToRot(-38), 200);

    pivotChassisBAD(90, 200, 200);
    
    move_relativeRightChassis(inToRot(48), 100);
    move_relativeLeftChassis(inToRot(48), 100);

    intake.move_velocity(-200);
    delay(150);
    intake.move_velocity(0);
    
}