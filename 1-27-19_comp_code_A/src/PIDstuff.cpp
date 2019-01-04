#include "main.h"

float Pi = 3.1415926535897932384;

float rotToIn(float Rotations) 
{
    return (Rotations * 6.875 * Pi);
}

float inToRot(float Inches)
{
    return (Inches / 2.475 / Pi);
}

float inToRotHS(float Inches)
{
    return (Inches / 5.775 / Pi);
}

void drivePD(float setPoint) {

    float distError, distDerivative, distPrevError, distSpeed, kDistP = 11700, kDistD = 0;
    float diffError, diffDerivative, diffPrevError, diffSpeed, kDiffP = 317500, kDiffD = 11000;
    float leftSpeed = 1200, rightSpeed = 1200;

    resetChassisEncoderValue();

    while(abs(leftSpeed) > 1000) {

        distError = setPoint - ((getLeftChassisPosition() + getRightChassisPosition()) / 2.0);
        distDerivative = distError - distPrevError;
        distPrevError = distError;
        distSpeed = (kDistP * distError) + (kDistD * distDerivative);

        diffError = (getLeftChassisPosition() - getRightChassisPosition()) / 2.0;
        diffDerivative = diffError - diffPrevError;
        diffPrevError = diffError;
        diffSpeed = (kDiffP * diffError) + (kDiffD * diffDerivative);

        leftSpeed = distSpeed - diffSpeed;
        rightSpeed = distSpeed + diffSpeed;

        runLeftBase(rightSpeed > 12000 ? 12000 : rightSpeed);
        runRightBase(leftSpeed > 12000 ? 12000 : leftSpeed);

        delay(1);

    }

    runLeftBase(0);
    runRightBase(0);

}

void resetChassisEncoderValue() {

    leftBase1.tare_position();
    leftBase2.tare_position();
    leftBase3.tare_position();
    rightBase1.tare_position();
    rightBase2.tare_position();
    rightBase3.tare_position();

    

}