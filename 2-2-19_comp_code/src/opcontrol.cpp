#include "main.h"

void opcontrol() {
	
	initCpltVis();
	int count = 0;

	while(true) {

		runLeftBase(((float)master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) / 127.0) * 100);
		runRightBase(((float)master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) / 127.0) * 100);

		if(master.get_digital(!PorX.get_value() ? E_CONTROLLER_DIGITAL_L1 : E_CONTROLLER_DIGITAL_L2))
			runIntake(100);

		else if(master.get_digital(!PorX.get_value() ? E_CONTROLLER_DIGITAL_R1 : E_CONTROLLER_DIGITAL_R2))
			runIntake(-100);

		else
			runIntake(0);
		
	}

}