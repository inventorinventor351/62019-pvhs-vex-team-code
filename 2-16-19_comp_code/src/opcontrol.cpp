#include "main.h"

void opcontrol() {

	std::uint_least32_t now = millis();

	bool shootAck = 1;
	resetYaw = 1;
	initCpltVis();
	
	while(true) {

		runLeftBase((master.get_digital(PorX(E_CONTROLLER_DIGITAL_R1, E_CONTROLLER_DIGITAL_R2)) && (controllerRemap(master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)) > 45)) ? 45 : controllerRemap(master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)));
		runRightBase((master.get_digital(PorX(E_CONTROLLER_DIGITAL_R1, E_CONTROLLER_DIGITAL_R2)) && (controllerRemap(master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y)) > 45)) ? 45 : controllerRemap(master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y)));
		
		if(master.get_digital(PorX(E_CONTROLLER_DIGITAL_L1, E_CONTROLLER_DIGITAL_L2)))
			runIntk(100);

		else if(master.get_digital(PorX(E_CONTROLLER_DIGITAL_R1, E_CONTROLLER_DIGITAL_R2)))
			runIntk(-100);

		else
			runIntk(0);

		if(master.get_digital(PorX(E_CONTROLLER_DIGITAL_L2, E_CONTROLLER_DIGITAL_L1)))
			flagAim();

		if(!master.get_digital(PorX(E_CONTROLLER_DIGITAL_R2, E_CONTROLLER_DIGITAL_R1)))
			shootAck = 0;

		else if(!shootAck) {

			shoot = true;
			shootAck = 1;

		}

		//std::cout << "big: " << cpltVis.get_by_sig(0, 1).y_middle_coord << " | small: " << cpltVis.get_by_sig(1, 1).y_middle_coord << " | objects: " << cpltVis.get_object_count() << "\n";
		std:: cout << gyro1.get_value() << " | " << gyro2.get_value() << " | " << yaw << "\n";

		Task::delay_until(&now, 10);
		
	}

}