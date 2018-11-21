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

	bool aimAtFlagToggle = true;
	bool finished = true;
	bool catapultLaunchToggle = true;
	bool intakePistonsToggle = true;
	bool intakePistonsState;
	bool chassisTransmissionToggle = true;
	bool chassisTransmissionState;
	
	while(true) {

		move_velocityLeftChassis(((float)master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)/127.0) * 200); 
		move_velocityRightChassis(((float)master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y)/127.0) * 200);

		if(master.get_digital())
			aimAtFlagToggle = false;

		else if(!aimAtFlagToggle) {

			aimAtFlagToggle = true;
			aimAtFlag();

		}

		if(finished) {

			if(master.get_digital())
				catapultLaunchToggle = false;

			else if(!catapultLaunchToggle) {

				catapultLaunchToggle = true;
				catapult.move_relative(3, 200);
				finished = false;

			}

			else if(master.get_digital())
				catapult.move(-127);

			else
				catapult.move(0);

		}

		if(catapult.get_position() >= catapult.get_target_position())
			finished = 1;

		if(master.get_digital())
			chassisTransmissionToggle = false;

		else if(!chassisTransmissionToggle) {

			chassisTransmissionToggle = true;
			chassisTransmissionPiston.set_value(chassisTransmissionState);
			chassisTransmissionState != chassisTransmissionState;

		}

		if(master.get_digital())
			intakePistonsToggle = false;

		else if(!chassisTransmissionToggle) {

			intakePistonsToggle = true;
			intakePiston1.set_value(intakePistonsState);
			intakePiston2.set_value(intakePistonsState);
			intakePistonsState != intakePistonsState;

		}

		if(master.get_digital())
			intake.move(127);

		else if(master.get_digital())
			intake.move(-127);

		else
			intake.move(0);

		delay(1);
		
	}

}