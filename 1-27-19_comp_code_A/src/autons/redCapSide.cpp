#include "main.h"

void redCapSide(){
    
    runIntake(70);
    drivePD(2.9);
    delay(500);
    drivePD(-2.4);
    runIntake(0);
    delay(500);

}
