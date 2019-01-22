#include "main.h" //DO NOT TOUCH

void opcontrol() {

	std::uint_least32_t now = millis();
	initCpltVis();

	while(true) {

		runLeftBase(((float)master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) / 127.0) * 100);
		runRightBase(((float)master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) / 127.0) * 100);

		if(master.get_digital(E_CONTROLLER_DIGITAL_UP))
			flagAimTop();

		if(master.get_digital(E_CONTROLLER_DIGITAL_DOWN))
			flagAimLow();

		if(master.get_digital(E_CONTROLLER_DIGITAL_A)) {
			shoot = true;
			PID cpltShoot = initPID(1, 1, 0, 132, 132, 0);
		}

		if(master.get_digital(E_CONTROLLER_DIGITAL_R1))
			runIntake(100);

		else if(master.get_digital(E_CONTROLLER_DIGITAL_L1))
			runIntake(-100);

		else
			runIntake(0);
		Task::delay_until(&now, 1);

		
	}


}

