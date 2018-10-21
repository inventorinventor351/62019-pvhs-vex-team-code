#include "main.h" //DO NOT TOUCH

//Runs during the 1 minute and 45 second period of driver control or immediately after initialize() if no competition control is connected
void opcontrol() {
	
<<<<<<< HEAD
	while(true) {
		while()
=======
	Controller master(CONTROLLER_MASTER);

>>>>>>> 937d3f78895967d73dfce50026d873ac6210c116

	while(true) 
	{
		driveRight((master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y)));
		driveLeft((master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y)));

		if(master.get.digital(E_CONTROLLER_DIGITAL_R1))
			{
				intake.move(120);
			}
		if(master.get.digital(E_CONTROLLER_DIGITAL_L1))
			{
				intake.move(-120);
			}

		if(master.get.digital(E_CONTROLLER_DIGITAL_L2) && (E_CONTROLLER_DIGITAL_R2))
			{ 
				while()
				shooter.move(110);

			}
		delay(1);
	}

}
