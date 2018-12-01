#include "main.h"

void red_capSide_1flags_2caps_auton() {

    autonShoot();
    pivotChassisBAD(87, 150, 1500);// shoot the ball and turn 87 degrees right

    autonGetBall(1.95, -1); // get the ball, load it, and turn 45 degress right
    pivotChassisBAD(-45, 150, 800);

    intake.move_velocity(-450);// run the intake backwards then drive into the cap to flip it
    driveStraight(1, 1000);
    intake.move_velocity(0);

    delay(200); // park(drive back 2.6 rotations)
    driveStraight(-2.6, 2000);
}