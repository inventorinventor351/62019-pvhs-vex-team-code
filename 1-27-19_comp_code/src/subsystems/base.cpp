#include "main.h"

void runLeftBase(float voltPerc) {

    leftBase1.move_voltage((voltPerc / 100) * 12000);
    leftBase2.move_voltage((voltPerc / 100) * 12000);

}

void runRightBase(float voltPerc) {

    rightBase1.move_voltage((voltPerc / 100) * 12000);
    rightBase2.move_voltage((voltPerc / 100) * 12000);
}

int target = 0;

void baseSR() {

    std::uint_least32_t now = millis();
	
	while(true) {



		Task::delay_until(&now, 1); //loop slew rate 1000 times per second
		
	}

}

void getBaseSpeed() {

    std::uint_least32_t now = millis();

	while(true) {



		Task::delay_until(&now, 2); //calculate base angular dist speed 500 times per second
		
	}

}

void basePosPID() {

    std::uint_least32_t now = millis();
	
	while(true) {



		Task::delay_until(&now, 4); //run base position PID 250 times per second
		
	}

}

void baseVelPID() {

    std::uint_least32_t now = millis();
	
	while(true) {



		Task::delay_until(&now, 4); //run base position PID 250 times per second
		
	}

}