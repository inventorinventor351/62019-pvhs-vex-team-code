#include "main.h"

void redFlagSide()
{
    
    runIntake(70);
    driveDist(3, 80);
    delay(100);
    runIntake(0);
    driveDist(2.8, -70);
    runLeftBase(-40);
    runRightBase(60);
    delay(300);
    runLeftBase(0);
    runRightBase(0);
    driveDist(2.8, 70);
    delay(200);
    
}