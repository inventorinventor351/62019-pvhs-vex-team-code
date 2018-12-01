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
    shooterEye.set_signature(1, &GREENFLAG);

    chassisTransmission.set_value(0);

    /*if(autonCount == 0)
        autonBlueFlag();

    if(autonCount == 1)
        autonBlueCapFlip();
    
    if(autonCount == 2)
        autonRedFlag();

    if(autonCount == 3)
        autonRedCapFlip();*/

}
