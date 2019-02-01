#include "main.h"

void blueCapSide()
{
   runIntake(70);
   driveDist(3, 80);///////////////////////////////////////////////// All Done!!!
   delay(100);
   runIntake(0);
   driveDist(1, -70);
   runLeftBase(-40);
   runRightBase(60);
   delay(330);
   runRightBase(0);
   runLeftBase(0);
   runIntake(-100);
   driveDist(2.6, 70);
   delay(600);
   runIntake(0); //-----------------much good
   driveDist(5, -70);
   runLeftBase(40);
   runRightBase(-80);
   delay(200);
   runRightBase(-50);
   runLeftBase(-50);
   delay(100);
   runRightBase(0);
   runLeftBase(0);
   runIntake(90);
   delay(500);
   driveDist(5, 90);
   delay(300);
   runIntake(0);

   

}