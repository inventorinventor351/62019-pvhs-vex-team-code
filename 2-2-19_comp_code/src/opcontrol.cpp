#include "main.h"

void opcontrol() {

	std::uint_least32_t now = millis();
	initCpltVis();
	bool transPstnAck = 1, transPstnState = 1, desPstnAck = 1, desPstnState = 0, shootAck = 1, flagAimAck = 1;
	if(!whichTeam.get_value()) {

		transPstn.set_value(transPstnState);
		descorer.set_value(desPstnState);

	}
	
	initCpltVis();
	int count = 0;

	while(true) {

		runLeftBase(((float)master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) / 127.0) * 100);
		runRightBase(((float)master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) / 127.0) * 100);

		if(master.get_digital(PorX(E_CONTROLLER_DIGITAL_L1, E_CONTROLLER_DIGITAL_L2)))
			runIntake(100);

		else if(master.get_digital(PorX(E_CONTROLLER_DIGITAL_L2, E_CONTROLLER_DIGITAL_R2))) {
			runIntake(-80);
			if(((float)master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) / 127.0) * 100 > 60)
				runLeftBase(60);
			if(((float)master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) / 127.0) * 100 > 80)
				runRightBase(60);
		}

		else
			runIntake(0);

		if(!master.get_digital(PorX(E_CONTROLLER_DIGITAL_A, E_CONTROLLER_DIGITAL_R1)))
			shootAck = 0;

		else if(!shootAck)
			shoot = true;

		if(!master.get_digital(PorX(E_CONTROLLER_DIGITAL_Y, E_CONTROLLER_DIGITAL_L1)))
			flagAimAck = 0;

		else if(!flagAimAck) {

			flagAimAck = 1;
			flagAim(1);
			master.rumble("-");

		}

		if(!whichTeam.get_value()) {

			if(!master.get_digital(E_CONTROLLER_DIGITAL_L2))
				desPstnAck = 0;

			else if(!desPstnAck) {

				desPstnAck = 1;
				desPstnState = !desPstnState;
				descorer.set_value(desPstnState);

			}

			if(!master.get_digital(E_CONTROLLER_DIGITAL_R2))
				transPstnAck = 0;

			else if(!transPstnAck) {

				transPstnAck = 1;
				transPstnState = !transPstnState;
				transPstn.set_value(transPstnState);

			}

			if(master.get_digital(E_CONTROLLER_DIGITAL_B) || master.get_digital(E_CONTROLLER_DIGITAL_X))
				master.rumble(".");

		}

		//std::cout << whichTeam.get_value() << "\n";
		//std::cout << cpltPot.get_value() << "\n";
		//std::cout << "objects: " << cpltVis.get_object_count() << " | bigY: " << cpltVis.get_by_size(0).y_middle_coord << " | smallY: " << cpltVis.get_by_size(1).y_middle_coord << "\n";
		std::cout << getDist() << "   |   " << getYaw() << "\n";
		
		Task::delay_until(&now, 10);
		
	}

}