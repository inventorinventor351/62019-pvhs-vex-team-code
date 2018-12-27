#include "main.h" //DO NOT TOUCH

void opcontrol() {

	std::uint_least32_t now = millis();
	
	while(true) {

		leftBase1.move_velocity((master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) / 127) * 200);
		leftBase1.move_velocity((master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) / 127) * 200);
		rightBase2.move_velocity((master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) / 127) * 200);
		rightBase2.move_velocity((master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) / 127) * 200);

		if(master.get_digital(E_CONTROLLER_DIGITAL_R1)) {

			runIntake(80);

		} else if(master.get_digital(E_CONTROLLER_DIGITAL_R2)) {

			runIntake(-80);

		} else {

			runIntake(0);

		}

		Task::delay_until(&now, 50); //loop driver control 20 times per second
		
	}

}