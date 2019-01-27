#include "main.h"

void autonomous() 
{

    if(autonCount == 0)
        blueCapSide();

    if(autonCount == 1)
        blueFlagSide();
    
    if(autonCount == 2)
        redFlagSide();

    if(autonCount == 3)
        redCapSide();

        
        


}
