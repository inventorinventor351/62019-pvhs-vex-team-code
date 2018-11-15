#include "main.h" //DO NOT TOUCH

//Runs during the 1 minute and 45 second period of driver control or immediately after initialize() if no competition control is connected
void opcontrol() {
	
	while(true) {

		move_velocityLeftChassis(((float)master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)/127.0) * 200); 
		move_velocityRightChassis(((float)master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y)/127.0) * 200);

		if(master.get_digital(E_CONTROLLER_DIGITAL_L1)) {

			intake.move(127);

		}

		else if(master.get_digital(E_CONTROLLER_DIGITAL_L2)) {

			intake.move(-127);

		}

		else {

			intake.move(0);

		}

		delay(1);
		
	}

}
