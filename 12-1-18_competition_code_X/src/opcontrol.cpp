#include "main.h"

//Runs during the 1 minute and 45 second period of driver control or immediately after initialize() if no competition control is connected
void opcontrol() {

Controller master(CONTROLLER_MASTER);

bool transmissionVar = 0, liftVar = 0, tipperVar = 0, atckL2, atckR2, atckY;

	while(true) //Always running
	{
        
		driveRight((master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y))); //Right side of the base
		driveLeft((master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y))); //Left side of the base

		if(master.get_digital(E_CONTROLLER_DIGITAL_R1)) //If R1 on the master controller is pressed

			intake.move(127); //Then intake rolls balls and caps in
		
		else if(master.get_digital(E_CONTROLLER_DIGITAL_L1)) //If L1 on the master controller is pressed
		
			intake.move(-127); //Then intake flips caps

		else

			intake.move(0);


		if(master.get_digital(E_CONTROLLER_DIGITAL_A)){

			aimFlag();
			
		}

		if(master.get_digital(E_CONTROLLER_DIGITAL_UP)){ //If L2 and R2 on the master controller is pressed
		
			shooter.move_relative(1, 200); //Then shoot and reload

		}

		if(!master.get_digital(E_CONTROLLER_DIGITAL_L2))			
        	atckL2 = false;

        else if(!atckL2){

            atckL2 = true;
            chassisTransmission.set_value(transmissionVar);
            transmissionVar = !transmissionVar;

		}

		if(!master.get_digital(E_CONTROLLER_DIGITAL_R2))			
        	atckR2 = false;

        else if(!atckR2){

            atckR2 = true;
            intakeLift.set_value(liftVar);
            liftVar = !liftVar;

		}


		if(!master.get_digital(E_CONTROLLER_DIGITAL_Y))			
        	atckY = false;

        else if(!atckY){

            atckY = true;
            tipper.set_value(tipperVar);
            tipperVar = !tipperVar;
			
		}

		delay(1);

	}

}