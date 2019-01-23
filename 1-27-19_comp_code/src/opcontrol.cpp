#include "main.h" //DO NOT TOUCH

void opcontrol() {

	std::uint_least32_t now = millis();
	initCpltVis();
	gyro.reset();
	descorer.set_value(1);
	bool transPstnAck = 1, transPstnState = 1, atckR2 = 1;

	transPstn.set_value(transPstnState);

	while(true) {

		runLeftBase(((float)master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) / 127.0) * 100);
		runRightBase(((float)master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) / 127.0) * 100);

		if(master.get_digital(E_CONTROLLER_DIGITAL_UP))
			flagAimTop();

		if(master.get_digital(E_CONTROLLER_DIGITAL_DOWN))
			flagAimLow();

		if(!master.get_digital(E_CONTROLLER_DIGITAL_R2))
			atckR2 = 0;
		else if(atckR2 == 0) {
			atckR2 = 1;
			descorer.set_value(1);
			delay(300);
			descorer.set_value(0);
		}

		std::cout << cpltVis.get_by_size(0).y_middle_coord << " | " << cpltVis.get_by_size(1).y_middle_coord << "\n";

		if(master.get_digital(E_CONTROLLER_DIGITAL_A))
			shoot = true;

		if(master.get_digital(E_CONTROLLER_DIGITAL_R1))
			runIntake(100);

		else if(master.get_digital(E_CONTROLLER_DIGITAL_L1))
			runIntake(-100);

		else
			runIntake(0);

		if(master.get_digital(E_CONTROLLER_DIGITAL_L2))
			descorer.set_value(1);

		else
			descorer.set_value(0);

		if(!master.get_digital(E_CONTROLLER_DIGITAL_R2))
			transPstnAck = 0;

		else if(!transPstnAck) {

			transPstnAck = 1;
			transPstnState = !transPstnState;
			transPstn.set_value(transPstnState);

		}

		if(master.get_digital(E_CONTROLLER_DIGITAL_RIGHT))
			getBall(1500);

		Task::delay_until(&now, 1);

		
	}


}

