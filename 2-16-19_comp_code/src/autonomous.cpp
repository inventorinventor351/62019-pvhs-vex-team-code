#include "main.h"

void autonomous() {

    delay(1225);
    initCpltVis();

   switch(autonCount) {

        case 0:
            redFlag();
            break; 

        case 1:
            redCap();
            break;

        case 2:
            blueFlag();
            break;

        case 3:
            blueCap();
            break;

        default:
            break;

    }

}
