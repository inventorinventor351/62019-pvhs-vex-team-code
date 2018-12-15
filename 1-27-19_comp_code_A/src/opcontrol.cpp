#include "main.h" //DO NOT TOUCH

//Runs during the 1 minute and 45 second period of driver control or immediately after initialize() if no competition control is connected
void opcontrol() {
	
	while(true) {
		//get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
		//controller_get_analog

		runLeftBase((master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)) * 200 / 127); //Left side of the base
		runRightBase((master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y)) * 200 / 127); //Right side of base

		if(master.get_digital(E_CONTROLLER_DIGITAL_R1)) //If R1 on the master controller is pressed
			capFlip.move(90); //Then the ball fliper moves
		

		else
			capFlip.move(0); //if not pressed then nothing happens
		
	}

}