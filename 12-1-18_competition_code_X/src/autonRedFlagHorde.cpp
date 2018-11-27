#include "main.h"

void autonRedFlagHorde(){

    autonAimFlag();
    pvitChassis(90, 200, 1);

    drivePD(45, 1000);
    intake.move(64);
    drivePD(-10, 300);
    intakeLift.set_value(1);
    delay(100);
    intakeLift.set_value(0);
    drivePD(13, 300);
    delay(300);
    intake.move(0);
    intakeLift.set_value(1);
    intakeLiftCap.set_value(1);

    pvitChassis(90, 200, 1); //Check to see if this flips the lower flag in the middle?
    drivePD(30, 500);
    delay(300);
    intakeLift.set_value(0);
    intakeLiftCap.set_value(0);
    delay(100);
    intake.move(-64);

    drivePD(-6, 100);
    pvitChassis(90, 200, 1);
    drivePD(5, 100);
    intake.move(-64);
    delay(200);
    intake.move(64);
    drivePD(5, 100);
    delay(300);
    intake.move(0);
    intakeLift.set_value(1);
    intakeLiftCap.set_value(1);
    
    drivePD(-5, 100);
    pvitChassis(-90, 200, 1);
    drivePD(6, 100);
    intakeLift.set_value(0);
    intakeLiftCap.set_value(0);
    delay(100);
    intake.move(-64);
    drivePD(-5, 100);

    /*
    pvitChassis(-160, 200, 1.77778);
    drivePD(35, 1000);
    intake.move(64);
    pvitChassis(-20, 200, 0.22222);
    drivePD(-35, 1000);
    intake.move(0);
    intakeLift.set_value(1);
    intakeLiftCap.set_value(1);
    pvitChassis(-140, 200, 1.55556);
    intakeLift.set_value(0);
    intakeLiftCap.set_value(0);
    delay(100);
    intake.move(-64);
    drivePD(-5, 100);
    */

}