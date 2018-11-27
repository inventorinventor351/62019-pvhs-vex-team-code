#include "main.h"

void red_flagSide_3flags_1caps_auton() {

    intake.move(400);
    driveStraight(2.35, 1500);
    delay(100);

    driveStraight(-2.1, 1500);
    loadBall(1500);
    intake.move_velocity(0);
    delay(500);
    pivotChassisBAD(-80, 200, 1000);
    catapult.move_velocity(127);
    delay(300);
    catapult.move_velocity(0);
    delay(200);
    driveStraight(-3, 1500);


}