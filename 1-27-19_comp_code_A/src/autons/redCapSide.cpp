#include "main.h"

void redCapSide(){
    
   runIntake(70);
   driveDist(3, 80);///////////////////////////////////////////////// All Done!!!
   delay(100);
   runIntake(0);
   driveDist(1.2, -70);
   runLeftBase(60);
   runRightBase(-40);
   delay(330);
   runRightBase(0);
   runLeftBase(0);
   runIntake(-100);
   driveDist(2.6, 70);
   delay(600);
   runIntake(0); //-----------------much good
   driveDist(5, -70);
   runLeftBase(-80);
   runRightBase(40);
   delay(200);
   runLeftBase(0);
   runRightBase(0);
   delay(200);
   runLeftBase(-70);
   runRightBase(-90);
   delay(400);
   runIntake(80);
   driveDist(5, 90);
   delay(200);
   runIntake(0);
   


}
