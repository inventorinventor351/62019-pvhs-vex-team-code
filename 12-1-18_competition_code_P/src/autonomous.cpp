#include "main.h" //DO NOT TOUCH

//Runs during the 15 second autonomous period
void autonomous() {

    vision_signature_s_t GREENFLAG;
    GREENFLAG.id = 1;
    GREENFLAG.range = 2.8;
    GREENFLAG.u_min = -3383;
    GREENFLAG.u_max = -2431;
    GREENFLAG.u_mean = -2907;
    GREENFLAG.v_min = -4711;
    GREENFLAG.u_max = -2891;
    GREENFLAG.v_mean = -3801;
    GREENFLAG.type = 0;
    catapultEye.set_signature(1, &GREENFLAG);
    
   if(autonCount == 0) { 

        red_flagSide_3flags_1cap_auton();

    }

    else if(autonCount == 1) {

        red_flagSide_1flags_2caps_auton();

    }

    else if(autonCount == 2) {

        red_capSide_1flags_2caps_auton();

    }


    else if(autonCount == 3) {

        blue_flagSide_3flags_1cap_auton();

    }

    else if(autonCount == 4) {

        blue_flagSide_3flags_1cap_auton();

    }

    else if(autonCount == 5) {

        blue_flagSide_3flags_1cap_auton();

    }

}