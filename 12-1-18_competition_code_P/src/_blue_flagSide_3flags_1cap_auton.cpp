#include "main.h"

void blue_flagSide_3flags_1cap_auton() {

    resetChassisEncoderValue();

    move_absoluteLeftChassis(3.38, 200);
    move_absoluteRightChassis(3.38, 200);

    while(getLeftChassisPosition() < 2.75 && getRightChassisPosition() < 2.75) {
    
        intake.move_velocity(200);
        delay(1);

    }
    
    delay(250);
    intake.move_velocity(0);

    while(getLeftChassisPosition() < 3.38 && getRightChassisPosition() < 3.38) {
    
        delay(1);

    }

    move_absoluteLeftChassis(0, 200);
    move_absoluteRightChassis(0, 200);

    while(getLeftChassisPosition() > 0 && getRightChassisPosition() > 0) {
    
        delay(1);

    }

    pivotChassis(-90, 200, 1000);

    resetChassisEncoderValue();

}

}