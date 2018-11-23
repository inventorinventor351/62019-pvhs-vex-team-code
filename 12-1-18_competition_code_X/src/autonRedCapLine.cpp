#include "main.h"

void autonBlueCapLine(){

    autonAimFlag();

    pvitChassis(90, 200, 1);
    drivePD(45, 1000);
    delay(500);
    intake.move(127);

    drivePD(15, 500);
    intakeLift.set_value(1);
    delay(100);
    intakeLift.set_value(0);

    drivePD(-18, 500);
    
    delay(500);
    intake.move(0);
    intakeLift.set_value(1);

    drivePD(30, 1000);
    pvitChassis(-90, 200, 1);
    drivePD(-10, 300);
    delay(100);
    intakeLift.set_value(0);
    intake.move(-127);
    drivePD(34, 1000);

    pvitChassis(90, 200, 1);
    drivePD(-20, 500);
    intake.move(-127);
    delay(500);
    drivePD(-10, 300);
    intake.move(127);
    delay(500);
    intakeLift.set_value(1);
    delay(300);

    drivePD(50, 1200);
    pvitChassis(-90, 200, 1);
    drivePD(-30, 1000);
    delay(700);
    intakeLift.set_value(0);
    delay(200);
    intake.move(-127);
    drivePD(5, 200);

}