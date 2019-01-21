#include "main.h" //DO NOT TOUCH


void opcontrol() {

	Controller master(CONTROLLER_MASTER);


	
    bool transmissionVar = 0, liftVar = 0, tipperVar = 0, atckR2, atckY, atckA, atckUp = 1, finished = 1;
	vision_signature_s_t REDCAP;
    REDCAP.id = 1;
    REDCAP.range = 2.5999999046325684;
    REDCAP.u_min = 8565;
    REDCAP.u_max = 10443;
    REDCAP.u_mean = 9504;
    REDCAP.v_min = -1911;
    REDCAP.u_max = -1203;
    REDCAP.v_mean = -1556;
    REDCAP.type = 0;
    visn.set_signature(1, &REDCAP);

	
	vision_signature_s_t BLUECAP;
    BLUECAP.id = 2;
    BLUECAP.range = 3;
    BLUECAP.u_min = -2477;
    BLUECAP.u_max = -2920;
    BLUECAP.u_mean = 9971;
    BLUECAP.v_min = 11915;
    BLUECAP.u_max = 10942;
    BLUECAP.v_mean = -3801;
    BLUECAP.type = 0;
    visn.set_signature(1, &BLUECAP);


	
	while(true) {

		runRightBase((master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y)) * 200 / 127);
		runLeftBase((master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)) * 200 / 127);

	    if(master.get_digital(E_CONTROLLER_DIGITAL_R1)) 
		{
			runIntake(100);
		}

		else if(master.get_digital(E_CONTROLLER_DIGITAL_R2))
		{
			runIntake(-100);
		}

		 else 
		{
			runIntake(0);

		}

		if(master.get_digital(E_CONTROLLER_DIGITAL_L1))
		{
			runBro(60);
		}

		else if(master.get_digital(E_CONTROLLER_DIGITAL_L2))
		{
			runBro(-60);
		}

		else
		{
			runBro(0);
		}

	}

}