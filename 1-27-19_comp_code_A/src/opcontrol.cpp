#include "main.h" //DO NOT TOUCH


void opcontrol() {
	
	while(true) {

		runRightBase((master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y)) * 200 / 127);
		runLeftBase((master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)) * 200 / 127);

	    if(master.get_digital(E_CONTROLLER_DIGITAL_R1)) 
		{
			runIntake(80);
		}

		else if(master.get_digital(E_CONTROLLER_DIGITAL_R2)) 
		{
			runIntake(-80);

		}
		 else 
		{
			runIntake(0);

		}

	}

}