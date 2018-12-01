#include "main.h"

void autonRedCapFlip(){

    intake.move(90);
    drivePD(2.39);
    delay(375);
    drivePD(-1);
    intakeLift.set_value(1);
    delay(2000);
    intakeLift.set_value(0);
    delay(400);
    pvitChassis(-45, 100);
    delay(600);
    intake.move(-90);
    delay(1000);

    drivePD(-0.6);
    drivePD(1.8);
    drivePD(-0.7);
    pvitChassis(130, 150);
    delay(1500);
<<<<<<< HEAD
    chassisTransmission.set_value(1);
    intake.move(0);
    driveRelativeLeft(3, 200);
    driveRelativeRight(3, 200);
=======
    drivePD(1.8);
    intake.move(0);*/
>>>>>>> 6fe301e85b36d675a757a45d537865480611f916

}