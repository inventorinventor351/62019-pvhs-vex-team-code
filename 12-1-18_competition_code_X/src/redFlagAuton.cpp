#include "main"

void redFlagAuton()
{
    driveAbsLeft(inToRot(45), 200);
    driveAbsRight(inToRot(45), 200);
    delay(1000);
    while(ballSensor.get_value()>50)
    {
        move.intake(120);
    }

    driveAbsLeft(inToRot(0), 200);
    driveAbsRight(inToRot(0), 200);

    pvitChassis(0.5 * pi, 200, 1);
    aimFlag();
    shooter.move(200);
    delay(1000);
    while(ADIAnalogOut(potentiometer) > VALUE)
    {
        shooter.move(200);
    }

    driveRelativeLeft(inToRot(50), 200);
    driveRelativeRight(inToRot(50), 200);

    driveRelativeLeft(inToRot(-25), 200);
    driveRelativeLeft(inToRot(-25), 200);

    pvitChassis(-0.5 * pi, 200, 1)

    driveRelativeLeft(inToRot(24), 200);
    driveRelativeRight(intToRot(24), 200);
    intake.move(200);
    delay(2000);

    intake.move(-200);
    delay(500);
    driveRelativeLeft(intToRot(20), 200);
    driveRelativeRight(inToRot(20), 200);

}