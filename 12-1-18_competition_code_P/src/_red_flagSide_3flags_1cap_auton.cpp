#include "main.h"

void red_flagSide_3flags_1cap_auton() {

    resetChassisEncoderValue();

    move_absoluteLeftChassis(3.5, 200);
    move_absoluteRightChassis(3.5, 200);

    while(getLeftChassisPosition() < 3.5 || getRightChassisPosition() < 3.5) {


    }

    move_absoluteLeftChassis(1, 200);
    move_absoluteRightChassis(1, 200);

    while(getLeftChassisPosition() > 1 || getRightChassisPosition() > 1) {


    }

    pivotChassisBAD(90, 200, 1250);

}