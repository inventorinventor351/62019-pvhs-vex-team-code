#include "main.h" //DO NOT TOUCH

void opcontrol() {
	
	while(true) {
	    
		leftBase1.move_velocity(((float)master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) / 127.0) * 200);
		leftBase2.move_velocity(((float)master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) / 127.0) * 200);
		leftBase3.move_velocity(((float)master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) / 127.0) * 200);
		rightBase1.move_velocity(((float)master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) / 127.0) * 200);
		rightBase2.move_velocity(((float)master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) / 127.0) * 200);
		rightBase3.move_velocity(((float)master.get_analog(E_CONTROLLER_ANALOG_LEFT_X) / 127.0) * 200);
		
		if(master.get_digital(E_CONTROLLER_DIGITAL_R1)) 
		{
			sendIntake(80);
		}

		else if(master.get_digital(E_CONTROLLER_DIGITAL_R2)) 
		{
			sendIntake(-80);

		}
		 else 
		{
			sendIntake(0);

		}

		if(master.get_digital(E_CONTROLLER_DIGITAL_L1))
		{
			sendLift(70);
		}

		else if(master.get_digital(E_CONTROLLER_DIGITAL_L2))
		{
			sendLift(-70);
		}

		else
		{
			sendLift(0);
		}

	}

}