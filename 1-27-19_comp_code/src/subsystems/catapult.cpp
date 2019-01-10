#include "main.h"

void runCplt(float voltPerc) {

    cplt.move_voltage((voltPerc / 100) * 12000);

}

void cpltShoot() {

    int number; 
    int setpoint;
    PID cpltShoot = initPID(1, 1, 0, 132, 132, 132);

    while(cpltPot.get_value() > number) {

        cplt.move_voltage(12000);

    }

    while(cpltPot.get_value() > setpoint) {
        
        cpltShoot.error = setpoint - cpltPot.get_value();
        cplt.move_voltage(runPID(&cpltShoot));

    }

}

void flagAim() {

    double aimVal;

    if(abs(cpltVis.get_by_size(0).x_middle_coord) > 320) {

        runLeftBase(0);

    }

    else{

        PID aim = initPID(0, 0, 0, 0, 0, 0);
        float aimVal;

        for(int i = 0; i < 2000; i++) {

            aim.error = -cpltVis.get_by_size(0).x_middle_coord;

            aimVal = runPID(&aim);

            runLeftBase(-aimVal);
            runRightBase(aimVal);
        
            delay(1);

        }

        runLeftBase(0);
        runRightBase(0);

    }

}

void initCpltVis() {

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
    cpltVis.set_signature(1, &GREENFLAG);

}