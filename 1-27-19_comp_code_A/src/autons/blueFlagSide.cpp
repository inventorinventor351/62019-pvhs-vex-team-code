#include "main.h"

void blueFlagSide()
{
   runIntake(70);
   driveDist(3, 80);
   delay(100);
   runIntake(0);
   driveDist(1.5, -70);
   runLeftBase(60);
   runRightBase(-40);
   delay(500);
   runLeftBase(0);
   runRightBase(0);
   driveDist(4, 70);
   delay(200);
   driveDist(3, -80);
   runIntake(0);
   delay(200);
   runRightBase(-70);
   delay(420);
   runRightBase(0);
   delay(300);
   runIntake(-60);
   driveDist(3.5, 80);
   delay(400);
   runIntake(0);   
   
}