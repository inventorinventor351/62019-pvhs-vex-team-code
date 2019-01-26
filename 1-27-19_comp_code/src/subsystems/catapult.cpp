#include "main.h"

bool shoot = false;

void runCplt(float voltPerc) {

    cplt.move_voltage((voltPerc / 100) * 12000);

}

void cpltReturn(void* param) {

    PID cpltShoot = initPID(1, 0, 1, 1.63, 0, 5);
    int setpoint = 2830;
    int cpltVal;
    std::cout << cpltVal << "\n";

    while(true) {

        cpltShoot.error = setpoint - cpltPot.get_value();
        cpltVal = runPID(&cpltShoot);
        runCplt(cpltVal);
        
        if(shoot) {

            runCplt(100);
			delay(200);
			runCplt(0);
			delay(200);
			cpltShoot = initPID(1, 0, 0, 1.63, 0, 0);
            shoot = 0;
            
        }

        std::cout << "Error:" << cpltShoot.error << "| PID:" << cpltVal << "\n";

        delay(1);

    }
    
}

void flagAim() {

    delay(10);

    if(abs(cpltVis.get_by_size(0).x_middle_coord) > 320) {

        runLeftBase(0);
        runRightBase(0);

    }

    else {
    
        PID aim = initPID(1, 1, 1, 1.2, 0.0005, 10);
        PID dist = initPID(1, 0, 1, 2, 0, 1);
        double aimVal, distVal, distSetPoint = -47;

        for(int i = 0; i < 1500; i++) {

            if(abs(cpltVis.get_by_size(0).x_middle_coord) > 320)
                break;

            aim.error = -cpltVis.get_by_size(0).x_middle_coord;
            dist.error = (cpltVis.get_by_size(0).y_middle_coord + cpltVis.get_by_size(1).y_middle_coord) / 2 - distSetPoint;

            aimVal = runPID(&aim);
            distVal = runPID(&dist);

            runLeftBase(distVal - aimVal);
            runRightBase(distVal + aimVal);
            
            delay(1);

        }

    }

    runLeftBase(0);
    runRightBase(0);

}

void initCpltVis() {

    vision_signature_s_t GREENFLAG;
    GREENFLAG.id = 2;
    GREENFLAG.range = 2.8;
    GREENFLAG.u_min = -3383;
    GREENFLAG.u_max = -2431;
    GREENFLAG.u_mean = -2907;
    GREENFLAG.v_min = -4711;
    GREENFLAG.v_max = -2891;
    GREENFLAG.v_mean = -3801;
    GREENFLAG.type = 0;
    cpltVis.set_signature(1, &GREENFLAG);

}

void flagAimTop() {

    delay(10);

    if(abs(cpltVis.get_by_size(0).x_middle_coord) > 320) {

        runLeftBase(0);
        runRightBase(0);

    }

    else {
    
        PID aim = initPID(1, 1, 1, 1.2, 0.0005, 10);
        PID dist = initPID(1, 0, 1, 2, 0, 1);
        double aimVal, distVal, distSetPoint = -10, topY = -1000;

        for(int i = 0; i < 1500; i++) {

            if(abs(cpltVis.get_by_size(0).x_middle_coord) > 320)
                break;

            for(int n = 0; n < cpltVis.get_object_count(); n++) {

                if(cpltVis.get_by_size(n).y_middle_coord > topY)
                    topY = cpltVis.get_by_size(n).y_middle_coord;

            }

            aim.error = -cpltVis.get_by_size(0).x_middle_coord;
            dist.error = topY - distSetPoint;

            aimVal = runPID(&aim);
            distVal = runPID(&dist);

            runLeftBase(distVal - aimVal);
            runRightBase(distVal + aimVal);
            
            topY = -1000;
            delay(1);

        }

    }

    runLeftBase(0);
    runRightBase(0);

    master.rumble("-");

}

void flagAimLow() {

    delay(10);

    if(abs(cpltVis.get_by_size(0).x_middle_coord) > 320) {

        runLeftBase(0);
        runRightBase(0);

    }

    else {
    
        PID aim = initPID(1, 1, 1, 1.2, 0.0005, 10);
        PID dist = initPID(1, 0, 1, 2, 0, 1);
        double aimVal, distVal, distSetPoint = -84, lowY = 1000;

        for(int i = 0; i < 1500; i++) {

            if(abs(cpltVis.get_by_size(0).x_middle_coord) > 320)
                break;

            for(int n = 0; n < cpltVis.get_object_count(); n++) {

                if(cpltVis.get_by_size(n).y_middle_coord < lowY)
                    lowY = cpltVis.get_by_size(n).y_middle_coord;

            }

            aim.error = -cpltVis.get_by_size(0).x_middle_coord;
            dist.error = lowY - distSetPoint;

            aimVal = runPID(&aim);
            distVal = runPID(&dist);

            runLeftBase(distVal - aimVal);
            runRightBase(distVal + aimVal);
            
            lowY = 1000;
            delay(1);

        }

    }

    runLeftBase(0);
    runRightBase(0);

    master.rumble("-");

}