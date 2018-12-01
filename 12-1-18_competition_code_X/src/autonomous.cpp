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

<<<<<<< HEAD
    chassisTransmission.set_value(0);

    if(autonCount == 0)
=======
    chassisTransmission.set_value(1);
    delay(200);
    chassisTransmission.set_value(0);


    /*if(autonCount == 0)
>>>>>>> b14acb4ccd2e441d78c01ce62136f9493d793cd4
        autonBlueFlag();

    if(autonCount == 1)
        autonBlueCapFlip();
    
    if(autonCount == 2)
        autonRedFlag();
<<<<<<< HEAD

    if(autonCount == 3)
        autonRedCapFlip();
=======
    
    if(autonCount == 5)
        autonRedFlagHorde();

    if(autonCount == 6)
        autonRedCapLine();

    if(autonCount == 7)
        autonRedCapFlip();*/
        
  //  autonRedCapFlip();


    
    autonBlueFlag();
    
>>>>>>> b14acb4ccd2e441d78c01ce62136f9493d793cd4

}
