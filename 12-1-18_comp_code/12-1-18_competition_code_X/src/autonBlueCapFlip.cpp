#include "main.h"

void autonBlueCapFlip(){

    intake.move(90);
    drivePD(2.39);
    delay(375);
    drivePD(-1);
    intakeLift.set_value(1);
    delay(2000);
    intakeLift.set_value(0);
    delay(400);
    pvitChassis(45, 100);
    delay(600);
    intake.move(-90);
    delay(1000);

    drivePD(-0.6);
    drivePD(1.8);
    drivePD(-0.7);
    pvitChassis(-130, 150);
    delay(1500);
    chassisTransmission.set_value(1);
    drivePD(1.8);
    intake.move(0);

}