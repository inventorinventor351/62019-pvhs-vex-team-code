#include "main.h"

void runCplt(float voltPerc) {

    cplt.move_voltage((voltPerc / 100) * 12000);

}

void cpltReturn(void* param) {

    PID frame = PorX(initPID(1, 0, 1, 1.63, 0, 5), initPID(1, 0, 1, 1.63, 0, 5));
    PID cpltShoot = frame;
    int setpoint = PorX(2810, 2810);
    float cpltVal;

    std::uint_least32_t now = millis();

    while(true) {

        cpltShoot.error = setpoint - cpltPot.get_value();
        cpltVal = runPID(&cpltShoot);
        runCplt(cpltVal);
        
        if(shoot) {

            runCplt(100);
			delay(200);
			runCplt(0);
			delay(200);
			cpltShoot = frame;
            shoot = 0;
            
        }

        Task::delay_until(&now, 1);

    }
    
}

void initCpltVis() {



}

void flagAim(bool height) {



}