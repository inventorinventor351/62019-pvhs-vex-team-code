#include "main.h"

void runBro(float voltPerc) {

    deSr.move_voltage((voltPerc / 100) * 12000); 

}

void flipCap(float distance, int maxSpeed)
{
    distance = inToRot(distance);
    deSr.move_absolute(distance, maxSpeed);
}