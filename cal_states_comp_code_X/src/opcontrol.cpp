#include "main.h"

void opcontrol() {

	std::uint_least32_t now = millis();
	
	while (true) {



		Task::delay_until(&now, 10);
		
	}

}
