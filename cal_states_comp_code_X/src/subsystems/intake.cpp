#include "main.h"

void runIntk(float voltPerc) {

    intk.move_voltage((voltPerc / 100) * 12000);

}

void yaBoi() {

    armSetPoint -= 1000;
    delay(700);
    moveStraight(-150, 200);
    armSetPoint += 4500;

}

float armSetPoint = 0.0;
bool resetIntkEnc = 0;

void intkArmControl(void* param) {

    std::uint_least32_t now = millis();
    PID moveArm = initPID(1, 0, 0, 1, 0, 0);
    intk.tare_position();

    while(true) {

        moveArm.error = armSetPoint - intk.get_position();
        runIntk(runPID(&moveArm));

        //std::cout << armSetPoint << " | " << intk.get_position() << " | " << moveArm.error << "\n";

        if(resetIntkEnc) {

            armSetPoint = 0;
            intk.tare_position();
            resetIntkEnc = 0;

        }

        if(intk.is_over_temp() || intk.is_over_current())
			intk.set_voltage_limit(0);

		else
			intk.set_voltage_limit(12000);

        Task::delay_until(&now, 1);

    }

}