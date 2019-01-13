#include "main.h" //DO NOT TOUCH

void opcontrol() {

	std::uint_least32_t now = millis();
	bool atckL2 = false, transPstnVar = 1, atckA = false, is_finished = 1;
	int setpoint = 0001;
	//initCpltVis();
	initIntkVis();
	PID cpltShoot = initPID(1, 1, 0, 132, 132, 0);

	while(true) {

		leftBase1.move_velocity(((float)master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) / 127.0) * 200);
		leftBase2.move_velocity(((float)master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) / 127.0) * 200);
		rightBase1.move_velocity(((float)master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) / 127.0) * 200);
		rightBase2.move_velocity(((float)master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) / 127.0) * 200);
        
        cpltShoot.error = setpoint - cpltPot.get_value();
        runCplt(runPID(&cpltShoot));

		if(master.get_digital(E_CONTROLLER_DIGITAL_Y) && is_finished) {

			is_finished = 0;
			cplt.move_voltage(12000);
			delay(200);
			cplt.move_voltage(0);
			delay(200);
			cpltShoot = initPID(1, 1, 0, 132, 132, 0);
			is_finished = 1;
		}

		if(master.get_digital(E_CONTROLLER_DIGITAL_R1)) {

			runIntake(80);

		} else if(master.get_digital(E_CONTROLLER_DIGITAL_L1)) {

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
            getBall(2000);
			delay(200);
			runIntake(0);
		}

		std::cout << cpltVis.get_by_size(0).x_middle_coord << " | " << intkVis.get_by_size(0).x_middle_coord << "\n";

		Task::delay_until(&now, 1); //loop driver control 500 times per second
		
	}


}

