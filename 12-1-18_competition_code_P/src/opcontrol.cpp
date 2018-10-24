#include "main.h" //DO NOT TOUCH

//Runs during the 1 minute and 45 second period of driver control or immediately after initialize() if no competition control is connected
void opcontrol() {

	Controller master(CONTROLLER_MASTER);
	Controller partner(CONTROLLER_PARTNER);

	int setPoint = 3;
	
	while(true) {

		//move_velocityLeftChassis((master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)/127) * 200);
		//move_velocityRightChassis((master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y)/127) * 200);

		move_absoluteLeftChassis(setPoint, 200);
		move_absoluteRightChassis(setPoint, 200);

		std::cout << "Left Error: " << (setPoint - getLeftChassisPosition());
		std::cout << "Right Error: " << (setPoint - getRightChassisPosition());

		delay(1);
		
	}

}
