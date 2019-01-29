#include "main.h"

void opcontrol() {

	std::uint_least32_t now = millis();
	initCpltVis();
	bool transPstnAck = 1, transPstnState = 1, desPstnAck = 1, desPstnState = 0;
	if(!whichTeam.get_value()) {

		transPstn.set_value(transPstnState);
		descorer.set_value(desPstnState);

	}
	
	while(true) {

		runLeftBase(((float)master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) / 127.0) * 100);
		runRightBase(((float)master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) / 127.0) * 100);

		

		Task::delay_until(&now, 10);
		
	}

}