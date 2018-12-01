#include "main.h"

//Runs during the 1 minute and 45 second period of driver control or immediately after initialize() if no competition control is connected
void opcontrol() {

Controller master(CONTROLLER_MASTER);

bool transmissionVar = 0, liftVar = 0, tipperVar = 0, atckR2, atckY, atckA, atckUp = 1, finished = 1;
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
        
		driveVelocityRight((master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y)) * 200 / -127); //Right side of the base
		driveVelocityLeft((master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)) * 200 / 127); //Left side of the base


		if(master.get_digital(E_CONTROLLER_DIGITAL_R1)) //If R1 on the master controller is pressed
			intake.move(90); //Then intake rolls balls and caps in
		
		else if(master.get_digital(E_CONTROLLER_DIGITAL_L1)) //If L1 on the master controller is pressed
			intake.move(-90); //Then intake flips caps

		else
			intake.move(0);


		if(!master.get_digital(E_CONTROLLER_DIGITAL_A))
			atckA = false;
		
		else if(master.get_digital(E_CONTROLLER_DIGITAL_A)){
			atckA = true;
			aimFlag();
		}


		if(finished){

			if(master.get_digital(E_CONTROLLER_DIGITAL_UP))
				atckUp = 0;

			else if(!atckUp){
				atckUp = 1;
				shooter.move(127);
				delay(400);
				finished = 0;
			}

			else if(master.get_digital(E_CONTROLLER_DIGITAL_DOWN))
				shooter.move(-127);

			else
				shooter.move(0);

		}

		else if(!finished){

			if(!shooterBtn.get_value())
				shooter.move(90);

			else{

				shooter.move(0);
				finished = 1;

			}

		}


		if(!master.get_digital(E_CONTROLLER_DIGITAL_Y))			
        	atckY = false;

        else if(!atckY){
            atckY = true;
            chassisTransmission.set_value(transmissionVar);
            transmissionVar = !transmissionVar;
		}


		if(!master.get_digital(E_CONTROLLER_DIGITAL_R2))			
        	atckR2 = false;

        else if(!atckR2){
            atckR2 = true;
			intakeLift.set_value(liftVar);
			intakeLiftCap.set_value(liftVar /*&& capSensor.get_value()*/);
            liftVar = !liftVar;
		}

		delay(1);
	
	}

}