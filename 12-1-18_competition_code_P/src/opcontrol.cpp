#include "main.h" //DO NOT TOUCH

//Runs during the 1 minute and 45 second period of driver control or immediately after initialize() if no competition control is connected
void opcontrol() {

	bool transmissionState;
	bool intakeState;

	//int setPoint = 3;
	
	while(true) {

		move_velocityLeftChassis(((float)master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)/127.0) * 200); 
		move_velocityRightChassis(((float)master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y)/127.0) * 200);

		if(master.get_digital(E_CONTROLLER_DIGITAL_L1)) {

			intake.move(127);

		}

		else if(master.get_digital(E_CONTROLLER_DIGITAL_L2)) {

			intake.move(-127);

		}

		else {

			intake.move(0);

		}

		if(master.get_digital(E_CONTROLLER_DIGITAL_R1)) {

			transmissionState != transmissionState;
			chassisTransmissionPiston.set_value(transmissionState);

		}

		if(master.get_digital(E_CONTROLLER_DIGITAL_R2)) {

			intakeState != intakeState;
			intakePiston1.set_value(intakeState);
			intakePiston2.set_value(intakeState);

		}

		if(master.get_digital(E_CONTROLLER_DIGITAL_X)) {

			catapult.move_relative(1, 200);

		}

		else if(master.get_digital(E_CONTROLLER_DIGITAL_Y)) {

			catapult.move_velocity(200);

		}

		else {

			catapult.move_velocity(0);

		}

		if(master.get_digital(E_CONTROLLER_DIGITAL_UP)) {

			aimAtFlag(1.0, 0.1);

		}

		delay(1);
		
	}

}
