#include "main.h" //DO NOT TOUCH

void opcontrol() {
	
	while(true) {
		//get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
		//controller_get_analog

		runLeftBase((master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)) * 200 / 127); //Left side of the base
		runRightBase((master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y)) * 200 / 127); //Right side of base

		if(master.get_digital(E_CONTROLLER_DIGITAL_R1)) //If R1 on the master controller is pressed
			capFlip.move(90); //Then the cap fliper moves
		

		else
			capFlip.move(0); //if not pressed then nothing happens


		if(master.get_digital(E_CONTROLLER_DIGITAL_L1)) //If L1 on the master controller is pressed
			arm.move(70); //Then the cap descorer extends
		
		else if(master.get_digital(E_CONTROLLER_DIGITAL_L2)) //If L2 on the master controller is pressed
			arm.move(-70); //Then the cap descorer retractes

		else
			arm.move(0); //if not pressed then nothing happens

	}

}