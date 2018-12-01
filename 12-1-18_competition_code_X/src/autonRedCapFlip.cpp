#include "main.h"

void autonRedCapFlip(){

    drivePD(1.8);
    intake.move_velocity(500);
    drivePD(0.59);
    delay(375);
    drivePD(-1.78);
    intakeLiftCap.set_value(1);
    delay(1201);
    intakeLiftCap.set_value(0);
    
    intake.move_velocity(0);



    pvitChassis(-60, 150);
   //autonAimFlag();
    delay(150);
 
 
 
 
 
 
 
    /*intake.move(90);
    drivePD(40);
    intakeLift.set_value(1);
    delay(1200);
    intakeLift.set_value(0);
    delay(400);
    pvitChassis(-45, 100);
    delay(600);
    intake.move(-90);
    delay(1000);

    drivePD(-0.6);
    drivePD(1.6);
    drivePD(-0.5);
    pvitChassis(130, 150);
    delay(1500);
    drivePD(1.8);
    intake.move(0);*/

}