#include "main.h"

void opcontrol() {

	std::uint_least32_t now = millis();
	initCpltVis();
	bool transPstnAck = 1, transPstnState = 1, desPstnAck = 1, desPstnState = 0;
	if(!whichTeam.get_value()) {

		transPstn.set_value(transPstnState);
		descorer.set_value(desPstnState);

	}
	
	initCpltVis();
	int count = 0;

	while(true) {

		runLeftBase(((float)master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) / 127.0) * 100);
		runRightBase(((float)master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) / 127.0) * 100);

		if(master.get_digital(!whichTeam.get_value() ? E_CONTROLLER_DIGITAL_L1 : E_CONTROLLER_DIGITAL_L2))
			runIntake(100);

		else if(master.get_digital(!whichTeam.get_value() ? E_CONTROLLER_DIGITAL_R1 : E_CONTROLLER_DIGITAL_R2))
			runIntake(-100);

		else
			runIntake(0);
		
		std::cout << "objects: " << cpltVis.get_object_count() << " | middle x:" << cpltVis.get_by_size(0).x_middle_coord << " | middle y: " << cpltVis.get_by_size(0).y_middle_coord << "\n";

		Task::delay_until(&now, 10);
		
	}

}