#include "main.h"

void redFlagSide()
{
    runIntake(70);
    drivePD(3);
    delay(100);
    drivePD(2.9);
    runIntake(0);
    pvitBase(90, 50);
    delay(100);
    drivePD(2.8);

}