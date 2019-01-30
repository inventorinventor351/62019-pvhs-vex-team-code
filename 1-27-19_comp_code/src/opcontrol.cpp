#include "main.h" //DO NOT TOUCH

void opcontrol() {

	std::uint_least32_t now = millis();
	initCpltVis();
	//initIntkVis();
	gyro.reset();
	descorer.set_value(1);
	bool transPstnAck = 1, transPstnState = 1, desPstnAck = 1, desPstnState = 0;
	int count = 0, topY = -1000, lowY = 1000;
	transPstn.set_value(transPstnState);
	descorer.set_value(desPstnState);

	while(true) {

		runLeftBase(((float)master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) / 127.0) * 100);
		runRightBase(((float)master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) / 127.0) * 100);

		if(master.get_digital(!PorX.get_value() ? E_CONTROLLER_DIGITAL_UP : E_CONTROLLER_DIGITAL_UP))
			flagAim(1);
		if(master.get_digital(!PorX.get_value() ? E_CONTROLLER_DIGITAL_DOWN : E_CONTROLLER_DIGITAL_DOWN))
			flagAim(0);

		if(master.get_digital(!PorX.get_value() ? E_CONTROLLER_DIGITAL_A : E_CONTROLLER_DIGITAL_A))
			shoot = true;

		if(master.get_digital(!PorX.get_value() ? E_CONTROLLER_DIGITAL_Y : E_CONTROLLER_DIGITAL_Y))
			getBall(1500);

		if(master.get_digital(!PorX.get_value() ? E_CONTROLLER_DIGITAL_L1 : E_CONTROLLER_DIGITAL_L2))
			runIntake(100);

		else if(master.get_digital(!PorX.get_value() ? E_CONTROLLER_DIGITAL_R1 : E_CONTROLLER_DIGITAL_R2))
			runIntake(-100);

		else
			runIntake(0);

		if(master.get_digital(!PorX.get_value() ? E_CONTROLLER_DIGITAL_L2 : E_CONTROLLER_DIGITAL_B))
			descorer.set_value(1);

		else
			descorer.set_value(0);

		if(!master.get_digital(!PorX.get_value() ? E_CONTROLLER_DIGITAL_R2 : E_CONTROLLER_DIGITAL_R1))
			transPstnAck = 0;
			
		else if(!transPstnAck) {
			transPstnAck = 1;
			transPstnState = !transPstnState;
			transPstn.set_value(transPstnState);
		}

		if(!PorX.get_value() ? 0 : master.get_digital(E_CONTROLLER_DIGITAL_LEFT))
			master.rumble(".");

		std::cout << cpltVis.get_by_sig(0, 1).y_middle_coord << " | " << cpltVis.get_by_sig(1, 1).y_middle_coord << "\n";

		Task::delay_until(&now, 1);

	}

}