#include "main.h"

void autonomous() {

    transPstn.set_value(1);
    descorer.set_value(0);
    initCpltVis();
    delay(750);

    if(autonCount == 0)
        redFlag();

    else if(autonCount == 1)
        redCap();

    else if(autonCount == 2)
        blueFlag();

    else if(autonCount == 3)
        blueCap();
    
    else {

        runLeftBase(0);
        runRightBase(0);

    }

}
