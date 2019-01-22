#include "main.h" //DO NOT TOUCH

void opcontrol() {

	std::uint_least32_t now = millis();
	initCpltVis();
	gyro.reset();
	bool atckR2 = 1, descorerVal = 1;

	while(true) {

		runLeftBase(((float)master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) / 127.0) * 100);
		runRightBase(((float)master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) / 127.0) * 100);

		if(master.get_digital(E_CONTROLLER_DIGITAL_UP))
			flagAimTop();
		if(master.get_digital(E_CONTROLLER_DIGITAL_DOWN))
			flagAimLow();

<<<<<<< HEAD
		if(!master.get_digital(E_CONTROLLER_DIGITAL_R2))
			atckR2 = 0;
		else if(atckR2 == 0) {
			atckR2 = 1;
			descorer.set_value(1);
			delay(300);
			descorer.set_value(0);
		}

		std::cout << gyro.get_value() << "\n";

=======
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
>>>>>>> b7e50ec51624b8225170287e537a7d80098d073d
		Task::delay_until(&now, 1);

		
	}


}

