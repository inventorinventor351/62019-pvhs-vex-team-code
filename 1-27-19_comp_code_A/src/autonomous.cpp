#include "main.h"

void autonomous() 
{


    leftBase1.tare_position();
    leftBase2.tare_position();
    leftBase3.tare_position();
    rightBase1.tare_position();
    rightBase2.tare_position();
    rightBase3.tare_position();

    if(autonCount == 0)
        blueCapSide();

    if(autonCount == 1)
        blueFlagSide();
    
    if(autonCount == 2)
        redFlagSide();

    if(autonCount == 3)
        redCapSide();

        
        


}
