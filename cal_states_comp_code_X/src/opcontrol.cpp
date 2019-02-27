#include "main.h"

void opcontrol() {

	std::uint_least32_t now = millis();

	bool shootAck = 1;
	resetYaw = 1;
	initCpltVis();
	
	while(true) {

		runLeftBase((master.get_digital(E_CONTROLLER_DIGITAL_R2) && (controllerRemap(master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)) > 45)) ? 45 : controllerRemap(master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)));
		runRightBase((master.get_digital(E_CONTROLLER_DIGITAL_R2) && (controllerRemap(master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y)) > 45)) ? 45 : controllerRemap(master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y)));
		
		if(master.get_digital(E_CONTROLLER_DIGITAL_L2))
			armSetPoint += 13;

		else if(master.get_digital(E_CONTROLLER_DIGITAL_R2))
			armSetPoint -= 13;

		else
			armSetPoint += 0;

		if(master.get_digital(E_CONTROLLER_DIGITAL_L1))
			flagAim();

		if(!master.get_digital(E_CONTROLLER_DIGITAL_R1))
			shootAck = 0;

		else if(!shootAck) {

			shoot = true;
			shootAck = 1;

		}

		if(leftBase1.is_over_temp() || leftBase1.is_over_current())
			leftBase1.set_voltage_limit(0);
		else
			leftBase1.set_voltage_limit(12000);

		if(leftBase2.is_over_temp() || leftBase2.is_over_current())
			leftBase2.set_voltage_limit(0);
		else
			leftBase2.set_voltage_limit(12000);

		if(leftBase3.is_over_temp() || leftBase3.is_over_current())
			leftBase3.set_voltage_limit(0);
		else
			leftBase3.set_voltage_limit(12000);

		if(rightBase1.is_over_temp() || rightBase1.is_over_current())
			rightBase1.set_voltage_limit(0);
		else
			rightBase1.set_voltage_limit(12000);

		if(rightBase2.is_over_temp() || rightBase2.is_over_current())
			rightBase2.set_voltage_limit(0);
		else
			rightBase2.set_voltage_limit(12000);

		if(rightBase3.is_over_temp() || rightBase3.is_over_current())
			rightBase3.set_voltage_limit(0);
		else
			rightBase3.set_voltage_limit(12000);

		if(intk.is_over_temp() || intk.is_over_current())
			intk.set_voltage_limit(0);
		else
			intk.set_voltage_limit(12000);


		//std::cout << "big: " << cpltVis.get_by_sig(0, 1).y_middle_coord << " | small: " << cpltVis.get_by_sig(1, 1).y_middle_coord << " | objects: " << cpltVis.get_object_count() << "\n";
		//std:: cout << gyro1.get_value() << " | " << gyro2.get_value() << " | " << yaw << "\n";

		Task::delay_until(&now, 10);
		
	}

}