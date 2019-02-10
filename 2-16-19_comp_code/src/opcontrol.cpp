#include "main.h"

void opcontrol() {

	std::uint_least32_t now = millis();

	bool shootAck = 1;
	resetYaw = 1;

	while(true) {

		runLeftBase(pow(((float)master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) / 127.0), 3) * 125);
		runRightBase(pow(((float)master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) / 127.0), 3) * 125);

		if(master.get_digital(PorX(E_CONTROLLER_DIGITAL_L1, E_CONTROLLER_DIGITAL_L2)))
			runIntake(100);

		else if(master.get_digital(PorX(E_CONTROLLER_DIGITAL_R1, E_CONTROLLER_DIGITAL_R2))) {

			runLeftBase(pow(((float)master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) / 127.0), 3) * 125 > 60 ? 60 : pow(((float)master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) / 127.0), 3) * 125);
			runRightBase(pow(((float)master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) / 127.0), 3) * 125 > 60 ? 60 : pow(((float)master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) / 127.0), 3) * 125);
			runIntake(-100);

		}

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