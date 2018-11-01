#include "main"

void autonRedCapFlip(){

    driveAbsLeft(inToRot(45), 200);
    driveAbsRight(inToRot(45), 200);
    delay(500);
    intake.move(127);
    delay(2000);
    intake.move(0);

    driveAbsLeft(inToRot(40), 200);
    driveAbsRight(inToRot(40), 200);

    pvitChassis(-7 * pi / 18, 200, 0.77777777777778);
    driveRelativeLeft(inToRot(20));
    driveRelativeRight(inToRot(20));
    intake.move(-127);
    delay(2000);
    intake.move(0);
    
    pvitChassis(8 * pi / 9, 200, 1.777777777777777778);
    driveRelativeLeft(inToRot(30), 200);
    driveRelativeRight(inToRot(30), 200);

    aimFlag();
    shooter.move_relative(1, 200);

}