#include "main.h"

void autonBlueCapLine(){

    shooter.move_relative(1, 200);

    pvitChassis(90, 200, 1)
    driveAbsLeft(inToRot(45), 200);
    driveAbsRight(inToRot(45), 200);
    delay(500);
    move.intake(127);
    delay(200);

    driveAbsLeft(inToRot(30), 200);
    driveAbsRight(inToRot(30), 200);

    driveAbsLeft(inToRot(48), 200);
    driveAbsRight(inToRot(48), 200);
    
    delay(500);
    move.intake(0);
    intakeLift.set_value(1);
    intakeLift1.set_value(1);

    driveAbsLeft(inToRot(24), 200);
    driveAbsRight(inToRot(24), 200);
    pvitChassis(-90, 200, 1);
    driveRelativeLeft(inToRot(20), 200);
    driveRelativeRight(inToRot(20), 200);
    delay(100);
    intakeLift.set_value(0);
    intakeLift1.set_value(0);
    move.intake(-127);
    driveRelativeLeft(inToRot(-30), 200);
    driveRelativeRight(inToRot(-30), 200);

    pvitChassis(90, 200, 1);
    driveRelativeLeft(inToRot(30), 100);
    driveRelativeRight(inToRot(30), 100);
    move.intake(-127);
    delay(500);
    move.intake(127);
    intakeLift.set_value(0);
    intakeLift1.set_value(0);
    delay(300);

    driveRelativeLeft(inToRot(-50), 200);
    driveRelativeRight(inToRot(-50), 200);
    pvitChassis(-90, 200, 1);
    driveRelativeLeft(inToRot(30), 200);
    driveRelativeRight(inToRot(30), 200);
    intakeLift.set_value(0);
    intakeLift.set_value(0);
    move.intake(-127);
    driveRelativeLeft(inToRot(-10), 200);
    driveRelativeRight(inToRot(-10), 200);

}