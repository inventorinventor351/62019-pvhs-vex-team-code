#include "main.h"

void red_flagSide_3flags_1cap_auton() {

    resetChassisEncoderValue();

    move_absoluteLeftChassis(3.5 * 3, 200);
    move_absoluteRightChassis(3.5 * 3, 200);

    while(getLeftChassisPosition() < 3.5 * 3 || getRightChassisPosition() < 3.5 * 3) {


    }

    move_absoluteLeftChassis(3, 200);
    move_absoluteRightChassis(3, 200);

    while(getLeftChassisPosition() > 3 || getRightChassisPosition() > 3) {


    }

    pivotChassis(90 * 3, 200, 1250);

}