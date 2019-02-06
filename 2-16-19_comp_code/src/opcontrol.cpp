#include "main.h"

void opcontrol() {

	std::uint_least32_t now = millis();

	while(true) {

		runLeftBase(((float)master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) / 127.0) * 100);
		runRightBase(((float)master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) / 127.0) * 100);
		
		Task::delay_until(&now, 10);
		
	}

}