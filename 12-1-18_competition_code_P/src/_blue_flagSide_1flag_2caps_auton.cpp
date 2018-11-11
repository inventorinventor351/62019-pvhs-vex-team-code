#include "main.h"

void blue_flagSide_1flag_2caps_auton() {

    resetChassisEncoderValue();

    autonShoot(1.0, 0.01); // shoot
    
    pivotChassisBAD(-90, 200, 1000); // turn 90

    driveChassisRelative(40, 200);// drive to cap
    
    while (getRightChassisPosition() > inToRot(39) && getLeftChassisPosition() > inToRot(39)) {
        
        intake.move_velocity(200);//grab ball from under cap

    }
    
    delay(400);

    intake.move_velocity(0);

    driveChassisRelative(-12, 200);// move back

    intakePiston1.set_value(1);// load ball
    intakePiston2.set_value(1);//load ball

    delay(250);

    intakePiston1.set_value(0);// reset
    intakePiston2.set_value(0);// reset

    driveChassisRelative(12, 200);

    while (getRightChassisPosition() > inToRot(11) && getLeftChassisPosition() > inToRot(11)) {

        intake.move_velocity(200);

    }

    delay(300);

    intake.move_velocity(0);

    pivotChassisBAD(90, 200, 1000);

    driveChassisRelative(40, 200);

    pivotChassisBAD(155, 200, 1000);

    driveChassisRelative(26, 200);

    while (getRightChassisPosition() > inToRot(19) && getLeftChassisPosition() > inToRot(19)) {

        intake.move_velocity(-200);

    }

    delay(400);

    intake.move_velocity(0);


}