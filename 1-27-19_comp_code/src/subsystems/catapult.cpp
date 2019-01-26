#include "main.h"

bool shoot = false;

void runCplt(float voltPerc) {

    cplt.move_voltage((voltPerc / 100) * 12000);

}

void cpltReturn(void* param) {

    PID frame = !PorX.get_value() ? initPID(1, 0, 1, 1.63, 0, 5) : initPID(1, 0, 1, 1.63, 0, 5);
    PID cpltShoot = frame;
    int setpoint = 2830;
    int cpltVal;

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

        //std::cout << "Error:" << cpltShoot.error << "| PID:" << cpltVal << "\n";

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

    vision_signature_s_t BLUEFLAG;
    BLUEFLAG.id = 3;
    BLUEFLAG.range = 1.4;
    BLUEFLAG.u_min = -2935;
    BLUEFLAG.u_max = -885;
    BLUEFLAG.u_mean = -1910;
    BLUEFLAG.v_min = 3409;
    BLUEFLAG.v_max = 10485;
    BLUEFLAG.v_mean = 6947;
    BLUEFLAG.type = 0;
    cpltVis.set_signature(3, &BLUEFLAG);

    vision_signature_s_t REDFLAG;
    REDFLAG.id = 4;
    REDFLAG.range = 2.8;
    REDFLAG.u_min = 5065;
    REDFLAG.u_max = 7193;
    REDFLAG.u_mean = 6129;
    REDFLAG.v_min = -323;
    REDFLAG.v_max = 379;
    REDFLAG.v_mean = 28;
    REDFLAG.type = 0;
    cpltVis.set_signature(4, &REDFLAG);

}

/*void flagAimTop() {

    delay(10);

    if(abs(cpltVis.get_by_size(0).x_middle_coord) > 320) {

        runLeftBase(0);
        runRightBase(0);

    }

    else {
    
        PID aim = initPID(1, 1, 1, 1.2, 0.0005, 10);
        PID dist = initPID(1, 0, 1, 2, 0, 1);
        double aimVal, distVal, distSetPoint = 41, topY = -1000;

        for(int i = 0; i < 1500; i++) {

            if(abs(cpltVis.get_by_size(0).x_middle_coord) > 320)
                break;

            for(int n = 0; n < cpltVis.get_object_count(); n++) {

                if(cpltVis.get_by_size(n).y_middle_coord > topY)
                    topY = cpltVis.get_by_size(n).y_middle_coord;
                    aim.error = -cpltVis.get_by_size(n).x_middle_coord;

            }

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

}*/

void flagAimTop() {

    delay(10);

    PID aim = initPID(1, 1, 1, 1.2, 0.0005, 10);
    PID dist = initPID(1, 0, 1, 2, 0, 1);
    double aimVal, distVal, distSetPoint = 41, highY = -201;

    for(int i = 0; i < 1500; i++) {

        if(cpltVis.get_object_count() == 0)
            break;

        for(int j = 0; j < cpltVis.get_object_count(); j++) {

            if(cpltVis.get_by_sig(j, (autonCount <= 1) ? 3 : 4).y_middle_coord > highY) {

                aim.error = -cpltVis.get_by_sig(j, (autonCount <= 1) ? 3 : 4).x_middle_coord;
                dist.error = cpltVis.get_by_sig(j, (autonCount <= 1) ? 3 : 4).y_middle_coord - distSetPoint;

            }

            if(j == 1)
                break;

        }

        aimVal = runPID(&aim);
        distVal = runPID(&dist);

        runLeftBase(distVal - aimVal);
        runRightBase(distVal + aimVal);

        delay(1);

    }

    runLeftBase(0);
    runRightBase(0);

    master.rumble("-");

}

/*void flagAimLow() {

    delay(10);

    if(abs(cpltVis.get_by_size(0).x_middle_coord) > 320) {

        runLeftBase(0);
        runRightBase(0);

    }

    else {
    
        PID aim = initPID(1, 1, 1, 1.2, 0.0005, 10);
        PID dist = initPID(1, 0, 1, 2, 0, 1);
        double aimVal, distVal, distSetPoint = -26, lowY = 1000;

        for(int i = 0; i < 1500; i++) {

            if(abs(cpltVis.get_by_size(0).x_middle_coord) > 320)
                break;

            for(int n = 0; n < 2; n++) {

                if(cpltVis.get_by_size(n).y_middle_coord < lowY)
                    lowY = cpltVis.get_by_size(n).y_middle_coord;
                    aim.error = -cpltVis.get_by_size(n).x_middle_coord;

            }

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

}*/

void flagAimLow() {

    delay(10);

    PID aim = initPID(1, 1, 1, 1.2, 0.0005, 10);
    PID dist = initPID(1, 0, 1, 2, 0, 1);
    double aimVal, distVal, distSetPoint = -26, lowY = 201;

    for(int i = 0; i < 1500; i++) {

        if(cpltVis.get_object_count() == 0)
            break;

        for(int j = 0; j < cpltVis.get_object_count(); j++) {

            if(cpltVis.get_by_sig(j, (autonCount <= 1) ? 3 : 4).y_middle_coord < lowY) {

                aim.error = -cpltVis.get_by_sig(j, (autonCount <= 1) ? 3 : 4).x_middle_coord;
                dist.error = cpltVis.get_by_sig(j, (autonCount <= 1) ? 3 : 4).y_middle_coord - distSetPoint;

            }

            if(j == 1)
                break;

        }

        aimVal = runPID(&aim);
        distVal = runPID(&dist);

        runLeftBase(distVal - aimVal);
        runRightBase(distVal + aimVal);

        delay(1);

    }

    runLeftBase(0);
    runRightBase(0);

    master.rumble("-");

}