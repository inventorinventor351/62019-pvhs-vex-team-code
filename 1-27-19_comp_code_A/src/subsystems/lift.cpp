#include "main.h"

    void movelift(float voltPerc)
    {
        lift.move_voltage((voltPerc / 100) * 12000); //run the cap de-scorer motor from a % of -100-100
    } 