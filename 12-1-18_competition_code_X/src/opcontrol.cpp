#include "main.h"

//Runs during the 1 minute and 45 second period of driver control or immediately after initialize() if no competition control is connected
void opcontrol() {

Controller master(CONTROLLER_MASTER);

bool transmissionVar = 0, liftVar = 0, tipperVar = 0, atckL2, atckR2, atckY, atckA;
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
    shooterEye.set_signature(1, &GREENFLAG);

	while(true) //Always running
	{
        
		driveVelocityRight((master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y)) * 200 / 127); //Right side of the base
		driveVelocityLeft((master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)) * 200 / 127); //Left side of the base


		if(master.get_digital(E_CONTROLLER_DIGITAL_R1)) //If R1 on the master controller is pressed
			intake.move(127); //Then intake rolls balls and caps in
		
		else if(master.get_digital(E_CONTROLLER_DIGITAL_L1)) //If L1 on the master controller is pressed
			intake.move(-127); //Then intake flips caps

		else
			intake.move(0);


		if(!master.get_digital(E_CONTROLLER_DIGITAL_A))
			atckA = false;
		
		else if(master.get_digital(E_CONTROLLER_DIGITAL_A)){
			atckA = true;
			aimFlag;
		}


		if(finished){

			if(master.get_digital(E_CONTROLLER_DIGITAL_UP))
				atckUp = 0;

			else if(!master.get_digital(E_CONTROLLER_DIGITAL_UP)){
				atckUp = 1;
				shooter.move_relative(3, 200);
				finished = 0;
			}

			else if(master.get_digital(E_CONTROLLER_DIGITAL_Y))
				shooter.move(-127);

			else
				shooter.move(0);

		}

		if(shooter.get_position() >= shooter.get_target_position())
			finished = 1;


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
		

		delay(1);

	}

}