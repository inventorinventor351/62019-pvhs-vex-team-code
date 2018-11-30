#include "main.h"

void red_flagSide_3flags_1caps_auton() {

    
    driveStraight(1.8, 1200);
    intake.move_velocity(500);
    driveStraight(0.59, 800);
    
    
    delay(375);

    driveStraight(-1.78, 1000);
    loadBall(1000);
    intake.move_velocity(0);
    delay(500);
    pivotChassisBAD(-60, 200, 1000);
    autonShoot();
    delay(150);
    //pivotChassisBAD(15, 150, 800);
    //driveStraight(-3, 1500);

}