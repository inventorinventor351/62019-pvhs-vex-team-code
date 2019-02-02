#include "main.h"

void blueFlagSide()
{
   runIntake(70);
   driveDist(3, 80);
   delay(100);
   runIntake(0);
   driveDist(2.8, -70);
   runLeftBase(60);
   runRightBase(-40);
   delay(400);
   runLeftBase(0);
   runRightBase(0);
   runIntake(-60);
   driveDist(2.8, 70);
   delay(200);
   driveDist(2.8, -80);
   runIntake(0);
   delay(200);
   runRightBase(-70);
   delay(400);
   runRightBase(0);
   delay(300);
   driveDist(4, 80);
   
   
   

}