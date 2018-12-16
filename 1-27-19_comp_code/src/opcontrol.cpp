#include "main.h" //DO NOT TOUCH

//Runs during the 1 minute and 45 second period of driver control or immediately after initialize() if no competition control is connected
void opcontrol() {

	std::uint_least32_t now = millis();
	
	while(true) {



		Task::delay_until(&now, 50); //loop driver control 20 times per second
		
	}

}