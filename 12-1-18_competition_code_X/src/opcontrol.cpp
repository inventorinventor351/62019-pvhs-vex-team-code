#include "main.h"

//Runs during the 1 minute and 45 second period of driver control or immediately after initialize() if no competition control is connected
void opcontrol() {
	
Controller master(CONTROLLER_MASTER);

	while(true) //Always running
	{

		driveRight((master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y))); //Right side of the base
		driveLeft((master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y))); //Left side of the base

		if(master.get_digital(E_CONTROLLER_DIGITAL_R1)){ //If R1 on the master controller is pressed

			intake.move(127); //Then intake rolls balls and caps in

		}
		
		if(master.get_digital(E_CONTROLLER_DIGITAL_L1)){ //If L1 on the master controller is pressed
		
			intake.move(-127); //Then intake lifts up

		}

		if(master.get_digital(E_CONTROLLER_DIGITAL_A)){

			aimFlag();
			
		}

		if(master.get_digital(E_CONTROLLER_DIGITAL_L2) && (E_CONTROLLER_DIGITAL_R2)){ //If L2 and R2 on the master controller is pressed
		
			shooter.move_relative(1, 200); //Then shoot and reload

		}
		
		/*if(master.get.digital(E_CONTROLLER_DIGITAL_B)){ //If R1 on the master controller is pressed
		
			shooter.move(-127); //Activates the tipper

		}*/

		delay(1);

	}

}