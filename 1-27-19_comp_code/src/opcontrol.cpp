#include "main.h" //DO NOT TOUCH

void opcontrol() {

	std::uint_least32_t now = millis();
	initCpltVis();
	initIntkVis();
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
			flagAimTop();
		if(master.get_digital(!PorX.get_value() ? E_CONTROLLER_DIGITAL_DOWN : E_CONTROLLER_DIGITAL_DOWN))
			flagAimLow();

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

		if(!PorX.get_value() ? 0 : master.get_digital(E_CONTROLLER_DIGITAL_L1))
			master.rumble(".");

		/*if(!(count % 50)) {

			for(int n = 0; n < cpltVis.get_object_count(); n++) {

                if(cpltVis.get_by_size(n).y_middle_coord > topY)
                    topY = cpltVis.get_by_size(n).y_middle_coord;

            }

			for(int n = 0; n < 2; n++) {

                if(cpltVis.get_by_size(n).y_middle_coord < lowY)
                    lowY = cpltVis.get_by_size(n).y_middle_coord;

            }

			std::cout << "1 : " << cpltVis.get_by_size(0).y_middle_coord << " | " << "2 : " << cpltVis.get_by_size(1).y_middle_coord << " | " << "3 : " << cpltVis.get_by_size(2).y_middle_coord << "\n";

			topY = -1000;
			lowY = 1000;

		}
		
		count++;*/

		std::cout << cpltVis.get_by_sig(0, 3).y_middle_coord << "	|	" << cpltVis.get_by_sig(1, 3).y_middle_coord << "	|	" << cpltVis.get_object_count() << "\n";

		Task::delay_until(&now, 1);

	}

}