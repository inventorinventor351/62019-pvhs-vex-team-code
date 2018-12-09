#include "main.h" //DO NOT TOUCH

//Runs during the 1 minute and 45 second period of driver control or immediately after initialize() if no competition control is connected
void opcontrol() {

	vision_signature_s_t GREENFLAG;
  	GREENFLAG.id = 1;
  	GREENFLAG.range = 2.8;
  	GREENFLAG.u_min = -3383;
  	GREENFLAG.u_max = -2431;
  	GREENFLAG.u_mean = -2907;
  	GREENFLAG.v_min = -4711;
  	GREENFLAG.u_max = -2891;
  	GREENFLAG.v_mean = -3801;
  	GREENFLAG.type = 0;
  	catapultEye.set_signature(1, &GREENFLAG);

	bool aimAtFlagToggle, catapultLaunchToggle, intakePistonsToggle, intakePistonsState = 1, chassisTransmissionToggle, chassisTransmissionState = 0, finished = 1;
	
	while(true) {

		move_velocityLeftChassis(((float)master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)/127.0) * 200); 
		move_velocityRightChassis(((float)master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y)/127.0) * 200);

		if(!master.get_digital(E_CONTROLLER_DIGITAL_B))
			aimAtFlagToggle = 0;

		else if(!aimAtFlagToggle) {

			aimAtFlagToggle = 1;
			aimAtFlag();

		}

		if(finished) {

			if(!master.get_digital(E_CONTROLLER_DIGITAL_Y))
				catapultLaunchToggle = 0;

			else if(!catapultLaunchToggle) {

				catapultLaunchToggle = 1;
				catapult.move(127);
				delay(350);
				finished = 0;
 
			}

			else if(master.get_digital(E_CONTROLLER_DIGITAL_RIGHT))
				catapult.move(-127);

			else
				catapult.move(0);

		}

		else {

			catapult.move(100);

			if(catabut.get_value()) {

				catapult.move(0);
				finished = 1;

			}
		
		}		

		if(!master.get_digital(E_CONTROLLER_DIGITAL_L1))
			intakePistonsToggle = 0;

		else if(!intakePistonsToggle) {

			intakePistonsToggle = 1;
			intakePiston1.set_value(intakePistonsState);
			intakePiston2.set_value(intakePistonsState && is_cap.get_value());
			intakePistonsState = !intakePistonsState;

		}

		if(!master.get_digital(E_CONTROLLER_DIGITAL_L2))
			chassisTransmissionToggle = 0;
		
		else if(!chassisTransmissionToggle) {

			chassisTransmissionToggle = 1;
			chassisTransmissionPiston.set_value(chassisTransmissionState);
			chassisTransmissionState = !chassisTransmissionState;

		}

		if(master.get_digital(E_CONTROLLER_DIGITAL_R1))
			intake.move(127);

		else if(master.get_digital(E_CONTROLLER_DIGITAL_R2))
			intake.move(-127);

		else
			intake.move(0);

		delay(1);
		
	}

}