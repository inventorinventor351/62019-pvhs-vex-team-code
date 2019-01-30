#include "main.h" //DO NOT TOUCH


void opcontrol() {

	Controller master(CONTROLLER_MASTER);

	
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


		if(master.get_digital(E_CONTROLLER_DIGITAL_A)){

			runBro(70);
			delay(200);
			runBro(0);
			
		}


	}

}