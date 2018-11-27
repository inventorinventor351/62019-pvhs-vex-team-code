#include "main.h"

void autonBlueCapLine(){

    autonAimFlag();

    pvitChassis(-90, 200);
    drivePD(45, 2000);
    delay(500);
    intake.move(64);

    drivePD(-15, 2000);
    intakeLift.set_value(1);
    delay(100);
    intakeLift.set_value(0);

    drivePD(18, 2000);
    
    delay(500);
    intake.move(0);
    intakeLift.set_value(1);
    intakeLiftCap.set_value(1);

    drivePD(-30, 2000);
    pvitChassis(-90, 200);
    drivePD(10, 2000);
    delay(100);
    intakeLift.set_value(0);
    intakeLiftCap.set_value(0);
    intake.move(-64);
    drivePD(-34, 2000);

    pvitChassis(90, 200);
    drivePD(20, 2000);
    intake.move(-64);
    delay(500);
    drivePD(10, 2000);
    intake.move(64);
    delay(500);
    intakeLift.set_value(1);
    intakeLiftCap.set_value(1);
    delay(300);

    drivePD(-50, 2000);
    pvitChassis(-90, 200);
    drivePD(30, 2000);
    delay(700);
    intakeLift.set_value(0);
    intakeLiftCap.set_value(0);
    delay(200);
    intake.move(-64);
    drivePD(-5, 2000);

}