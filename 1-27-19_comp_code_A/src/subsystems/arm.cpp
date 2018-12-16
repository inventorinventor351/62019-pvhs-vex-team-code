#include "main.h"

    void moveArm(float voltPerc)
    {
        arm.move_voltage((voltPerc / 100) * 12000); //run the cap de-scorer motor from a % of -100-100
    } 