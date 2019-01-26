#include "main.h"

void redFlagSide()
{
    runIntake(70);
    drivePD(2.9);
    delay(300);
    drivePD(-2.9);
    delay(300);
    runIntake(0);
    pvitBase(90, 50);
    delay(100);
    drivePD(2.8);

}