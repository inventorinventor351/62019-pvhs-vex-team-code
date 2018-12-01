#include "main.h"

void blue_capSide_1flags_2caps_auton() {

    autonShoot();
    pivotChassisBAD(-87, 200, 700);// shoot the ball and turn 87 degrees right
    
    autonGetBall(1.95, -1);
    pivotChassisBAD(45, 150, 800);// get the ball, load it, and turn 45 degress right

    intake.move_velocity(-450);
    driveStraight(1, 1000);
    intake.move_velocity(0);// run the intake backwards then drive into the cap to flip it

    delay(200);
    driveStraight(-2.6, 2000); // park(drive back 2.6 rotations)
    
}