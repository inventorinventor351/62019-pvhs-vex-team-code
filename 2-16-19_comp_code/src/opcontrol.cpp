#include "main.h"

void opcontrol() {

	std::uint_least32_t now = millis();

	bool shootAck = 1;
	float leftBaseVal, rightBaseVal;
	
	while(true) {

		leftBaseVal = ((float)master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) / 127.0) * 200;
		rightBaseVal = ((float)master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) / 127.0) * 200;
		leftBaseVal = (PorX(E_CONTROLLER_DIGITAL_R1, E_CONTROLLER_DIGITAL_R2) && (leftBaseVal > 120)) ? 120 : leftBaseVal;
		rightBaseVal = (PorX(E_CONTROLLER_DIGITAL_R1, E_CONTROLLER_DIGITAL_R2) && (rightBaseVal > 120)) ? 120 : rightBaseVal;

		leftBase1.move_velocity((leftBase1.is_over_temp() || leftBase1.is_over_current() || rightBase1.is_over_temp() || rightBase1.is_over_current()) ? 0 : leftBaseVal);
		leftBase2.move_velocity((leftBase2.is_over_temp() || leftBase2.is_over_current() || rightBase2.is_over_temp() || rightBase2.is_over_current()) ? 0 : leftBaseVal);
		leftBase3.move_velocity((leftBase3.is_over_temp() || leftBase3.is_over_current() || rightBase3.is_over_temp() || rightBase3.is_over_current()) ? 0 : leftBaseVal);
		rightBase1.move_velocity((leftBase1.is_over_temp() || leftBase1.is_over_current() || rightBase1.is_over_temp() || rightBase1.is_over_current()) ? 0 : rightBaseVal);
		rightBase2.move_velocity((leftBase2.is_over_temp() || leftBase2.is_over_current() || rightBase2.is_over_temp() || rightBase2.is_over_current()) ? 0 : rightBaseVal);
		rightBase3.move_velocity((leftBase3.is_over_temp() || leftBase3.is_over_current() || rightBase3.is_over_temp() || rightBase3.is_over_current()) ? 0 : rightBaseVal);

		if(master.get_digital(PorX(E_CONTROLLER_DIGITAL_L1, E_CONTROLLER_DIGITAL_L2)))
			runIntake(100);

		else if(master.get_digital(PorX(E_CONTROLLER_DIGITAL_R1, E_CONTROLLER_DIGITAL_R2)))
			runIntake(-100);

		else
			runIntake(0);

		if(master.get_digital(PorX(E_CONTROLLER_DIGITAL_L2, E_CONTROLLER_DIGITAL_L1)))
			flagAim();

		if(!master.get_digital(PorX(E_CONTROLLER_DIGITAL_R2, E_CONTROLLER_DIGITAL_R1)))
			shootAck = 0;

		else if(!shootAck) {

			shoot = true;
			shootAck = 1;

		}

		//std::cout << "gyro1: " << gyro1.get_value() * 0.094 << " | gyro2: " << gyro2.get_value() * 0.094 << " | yaw: " << yaw << "\n";
		
		Task::delay_until(&now, 10);
		
	}

}