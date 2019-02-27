#include "main.h"

void runIntk(float voltPerc) {

    intk.move_voltage((voltPerc / 100) * 12000);

}

void yaBoi() {

    runIntk(-100);
    delay(300);
    moveStraight(-100, 200);
    moveStraight(100, 200);
    runIntk(100);
    delay(500);
    runIntk(0);

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

        if(resetIntkEnc) {

            armSetPoint = 0;
            intk.tare_position();

        }

        Task::delay_until(&now, 1);

    }

}