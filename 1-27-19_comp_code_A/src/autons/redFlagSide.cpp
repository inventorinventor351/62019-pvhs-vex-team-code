#include "main.h"

void redFlagSide()
{
    
    runIntake(70);
    driveDist(3, 80);
    delay(100);
    runIntake(0);
    driveDist(2.8, -70);
    driveRelativeLeft(1, -100);
    driveRelativeRight(1, 100);
    delay(300);
    


}