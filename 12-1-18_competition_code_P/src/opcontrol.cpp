#include "main.h" //DO NOT TOUCH

//Runs during the 1 minute and 45 second period of driver control or immediately after initialize() if no competition control is connected
void opcontrol() {

	Controller master(CONTROLLER_MASTER);
	Controller partner(CONTROLLER_PARTNER);
	
	while(true) {

		move_velocityLeftChassis((master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)/127) * 200);
		move_velocityRightChassis((master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y)/127) * 200);

		if(master.get_digital(E_CONTROLLER_DIGITAL_L1)) {

			intake.move(127);

		}

		else if(master.get_digital(E_CONTROLLER_DIGITAL_R1)) {

			intake.move(-127);
			
		}

		else {

			intake.move(0);

		}

		if(partner.get_digital(E_CONTROLLER_DIGITAL_L1) && partner.get_digital(E_CONTROLLER_DIGITAL_R1)) {

			catapult.move(127);

		}

		else if(partner.get_digital(E_CONTROLLER_DIGITAL_L2) && partner.get_digital(E_CONTROLLER_DIGITAL_R2)) {

			catapult.move(-127);
			
		}

		else {

			catapult.move(0);

		}

		delay(1);
		
	}

}
