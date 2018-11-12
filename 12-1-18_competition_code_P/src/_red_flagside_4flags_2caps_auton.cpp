#include "main.h"

void red_flagside_4flags_2caps_auton() {

    driveChassisAbs(40, 200);

    while (getLeftChassisPosition() < inToRot(39) || getLeftChassisPosition() < inToRot(39)) {

        intake.move_velocity(200);

    }

    delay(400);
    intake.move_velocity(0);

    driveChassisAbs(0, 200);

    pivotChassisBAD(90, 200, 1250);

    autonShoot(1.00, 0.01);

    driveChassisRelative(42, 200);

    driveChassisRelative(-24, 200);

    pivotChassisBAD(-90, 200, 1250);

    driveChassisRelative(30, 200);

    resetChassisEncoderValue();

    while (getLeftChassisPosition() < inToRot(29) || getLeftChassisPosition() < inToRot(29)) {

        intake.move_velocity(-200);

    }

    delay(700);
    runintake(200, 500);
    intake.move_velocity(0);

    pivotChassisBAD(-90, 200, 1250);

    driveChassisRelative(-12, 200);

    pivotChassisBAD(-90, 200, 1250);

    runintake(-200, 500);

}