#include "main.h" //DO NOT TOUCH

void opcontrol() {

	std::uint_least32_t now = millis();
	bool atckL2 = false, transPstnVar = 1, atckA = false, is_finished = 1;
	//initCpltVis();
	initIntkVis();

	while(true) {

		leftBase1.move_velocity(((float)master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) / 127.0) * 200);
		leftBase2.move_velocity(((float)master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) / 127.0) * 200);
		rightBase1.move_velocity(((float)master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) / 127.0) * 200);
		rightBase2.move_velocity(((float)master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) / 127.0) * 200);

		cpltShoot();

		if(master.get_digital(E_CONTROLLER_DIGITAL_Y)) {

			cplt.move_voltage(12000);
			delay(200);
			cplt.move_voltage(0);
			delay(200);
			//cpltshoot = initPID(stuff);

		}

		if(master.get_digital(E_CONTROLLER_DIGITAL_R1)) {

			runIntake(80);

		} else if(master.get_digital(E_CONTROLLER_DIGITAL_R2)) {

			runIntake(-80);

		} else {

			runIntake(0);

		}

		/*if(!master.get_digital(E_CONTROLLER_DIGITAL_L2))			
        	atckL2 = false;

        else if(!atckL2){
            atckL2 = true;
            transPstn.set_value(transPstnVar);
            transPstnVar = !transPstnVar;
		}*/

		if(!master.get_digital(E_CONTROLLER_DIGITAL_A))			
        	atckA = false;

        else if(!atckA){
            atckA = true;
            getBall();
		}

		Task::delay_until(&now, 1);
		
	}


}

