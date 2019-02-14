#include "main.h"

void skills()
{

  driveDist(3, 90); //forward
  delay(100);
  driveDist(1, -80); //backward
  runLeftBase(60);
  runRightBase(-100); //trun
  delay(350);
  runLeftBase(0);
  runRightBase(0);
  delay(500);
  runLeftBase(-60);
  runRightBase(-60); //back
  delay(300);
  runLeftBase(0);
  runRightBase(0);
  delay(1000);
  runIntake(-80);
  driveDist(2, 80); //forward
  delay(2000);
  runIntake(0);
  runLeftBase(-40); //turn
  runRightBase(60);
  delay(400);
  runLeftBase(0);
  runRightBase(0);
  delay(100); 
  runRightBase(-80); //backward
  runLeftBase(-80);
  delay(400);
  runLeftBase(0);
  runRightBase(0);
  delay(400);
  runRightBase(-60); //turn
  delay(600);
  runRightBase(0);
  delay(200);
  runLeftBase(-40); //backward
  runRightBase(-40);
  delay(1000);
  runLeftBase(0);
  runRightBase(0);
  delay(200);
  runIntake(100);
  driveDist(3, 80); //forward
  delay(3500);




}