#include "main.h"

void redAutonHordCaps()
{   
     driveAbsLeft(inToRot(45), 200);
     driveAbsRight(inToRot(45), 200);
     delay(1000);
     intake.move(127);
   

     driveAbsLeft(inToRot(40), 200);
     driveAbsRight(inToRot(40), 200);

     driveAbsLeft(inToRot(45), 200);
     driveAbsRight(inToRot(45), 200);

     driveAbsLeft(inToRot(30), 200);
     driveAbsRight(inToRot(30), 200);

     pvitChassis(90, 200, 1);
     driveRelativeLeft(inToRot(40), 200);
     driveRelativeRight(inToRot(40), 200);

     intake.move(0);

     driveRelativeLeft(inToRot(-24), 200);
     driveRelativeRight(inToRot(-24), 200);
     pvitChassis(-90, 200, 1);

     intake.move(-127);

     driveRelativeLeft(inToRot(20), 200);
     driveRelativeRight(inToRot(20), 200);
     intake.move(0);

     delay(500);

     driveRelativeLeft(inToRot(5), 200);
     driveRelativeRight(inToRot(5), 200);

     pvitChassis(90, 200, 1);
     driveRelativeLeft(inToRot(20), 200);
     driveRelativeRight(inToRot(20), 200);
}

