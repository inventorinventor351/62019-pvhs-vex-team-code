#include "main.h"

void runCplt(float voltPerc) {

    cplt.move_voltage((voltPerc / 100) * 12000);

}

bool shoot = 0;

void cpltControl(void* param) {

    delay(1000);
    PID frame = PorX(initPID(1, 0, 0, 2.25, 0.00005, 5), initPID(1, 0, 0, 2.25, 0.00005, 5));
    PID cpltShoot = frame;
    int setpoint = PorX(2665, 2665);
    float cpltVal;

    std::uint_least32_t now = millis();

    while(true) {

        cpltShoot.error = setpoint - cpltPot.get_value();
        cpltVal = runPID(&cpltShoot);
        runCplt(cpltVal);
        
        if(shoot) {

            runCplt(100);
			delay(300);
			runCplt(0);
			delay(300);
			cpltShoot = frame;
            shoot = 0;
            
        }

        Task::delay_until(&now, 1);

    }
    
}

void initCpltVis() {

    vision_signature_s_t GREENFLAG;
    GREENFLAG.id = 1;
    GREENFLAG.range = 3;
    GREENFLAG.u_min = -3383;
    GREENFLAG.u_max = -2431;
    GREENFLAG.u_mean = -2907;
    GREENFLAG.v_min = -4711;
    GREENFLAG.v_max = -2891;
    GREENFLAG.v_mean = -3801;
    GREENFLAG.type = 0;
    cpltVis.set_signature(1, &GREENFLAG);

}

void flagAim(bool height) {

    

}