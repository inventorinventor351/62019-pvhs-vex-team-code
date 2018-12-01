#include "main.h"

void autonBlueCapFlip(){

    intake.move(90);
    drivePD(2.39);
    delay(375);
    drivePD(-1);
    intakeLift.set_value(1);
    delay(1200);
    intakeLift.set_value(0);
    delay(400);
    pvitChassis(45, 100);
    delay(600);
    intake.move(-90);
    delay(1000);

    drivePD(-0.6);
    drivePD(1.6);
    drivePD(-0.5);
    pvitChassis(-130, 150);
    delay(1500);
    drivePD(1.8);
    intake.move(0);

}