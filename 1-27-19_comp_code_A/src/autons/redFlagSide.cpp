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
   delay(400);
   runLeftBase(0);
   runRightBase(0);
   runIntake(-60);
   driveDist(2.8, 70);
   delay(200);
   driveDist(2.8, -80);
   runIntake(0);
   delay(200);
   runLeftBase(-70);
   delay(400);
   runLeftBase(0);
   delay(300);
   driveDist(4, 80);
    
}