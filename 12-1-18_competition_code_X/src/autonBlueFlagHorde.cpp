#include "main.h"

void autonBlueFlagHorde(){

    autonAimFlag();
    pvitChassis(-90, 200);

    drivePD(45);
    intake.move(64);
    drivePD(-10);
    intakeLift.set_value(1);
    delay(100);
    intakeLift.set_value(0);
    drivePD(13);
    delay(300);
    intake.move(0);
    intakeLift.set_value(1);
    intakeLiftCap.set_value(1);

    pvitChassis(-90, 200); //Check to see if this flips the lower flag in the middle?
    drivePD(30);
    delay(300);
    intakeLift.set_value(0);
    intakeLiftCap.set_value(0);
    delay(100);
    intake.move(-64);

    drivePD(-6);
    pvitChassis(-90, 200);
    drivePD(5);
    intake.move(-64);
    delay(200);
    intake.move(64);
    drivePD(5);
    delay(300);
    intake.move(0);
    intakeLift.set_value(1);
    intakeLiftCap.set_value(1);
    
    drivePD(-5);
    pvitChassis(90, 200);
    drivePD(6);
    intakeLift.set_value(0);
    intakeLiftCap.set_value(0);
    delay(100);
    intake.move(-64);
    drivePD(-5);

    /*
    pvitChassis(-160, 200);
    drivePD(35);
    intake.move(64);
    pvitChassis(20, 200);
    drivePD(-35);
    intakeLift.set_value(1);
    intakeLiftCap.set_value(1);
    intake.move(0);
    pvitChassis(140, 200);
    intakeLift.set_value(0);
    intakeLiftCap.set_value(0);
    delay(100);
    intake.move(-64);
    drivePD(-5);
    */

}