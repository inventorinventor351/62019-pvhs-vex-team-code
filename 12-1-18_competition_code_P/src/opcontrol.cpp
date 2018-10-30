#include "main.h" //DO NOT TOUCH

//Runs during the 1 minute and 45 second period of driver control or immediately after initialize() if no competition control is connected
void opcontrol() {

	bool transmissionState;
	bool intakeState;

	//int setPoint = 3;
	
	while(true) {

		move_velocityLeftChassis((master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)/127) * 200); 
		move_velocityRightChassis((master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y)/127) * 200);

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

			aimAtFlag();

		}

		/*move_absoluteLeftChassis(setPoint, 200);
		move_absoluteRightChassis(setPoint, 200);

		std::cout << "Left Error: " << (setPoint - getLeftChassisPosition());
		std::cout << "Right Error: " << (setPoint - getRightChassisPosition());*/

		delay(1);
		
	}

}
