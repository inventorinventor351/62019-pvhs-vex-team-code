#include "main"

void redFlagAuton()
{
    driveAbsLeft(inToRot(55));
    driveAbsRight(inToRot(55));
    delay(1000);
    while(ballSensor.get_value()<50)
    {
        move.intake(120);
    }

    while(leftChassis1.get_value()>0)
    {
    driveAbsLeft(inToRot(0));
    driveAbsRight(inToRot(0));
    }

    driveAbsLeft(-14);
    driveAbsRight(14);

    //drive forward a specific amount
    //shoot double balls
    //drive forward into flag
    //drive back
    //turn right 90 degrees
    //drive forward a specific amount
    //intake while driving forward (get cap)
    //flip intake (flip cap)
    //drive forward

}