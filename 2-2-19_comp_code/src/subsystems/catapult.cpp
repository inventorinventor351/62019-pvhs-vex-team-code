#include "main.h"

void initCpltVis() {

    vision_signature_s_t GREENFLAG;
    GREENFLAG.id = 1;
    GREENFLAG.range = 3.5;//2.8;
    GREENFLAG.u_min = -3383;
    GREENFLAG.u_max = -2431;
    GREENFLAG.u_mean = -2907;
    GREENFLAG.v_min = -4711;
    GREENFLAG.v_max = -2891;
    GREENFLAG.v_mean = -3801;
    GREENFLAG.type = 0;
    cpltVis.set_signature(1, &GREENFLAG);

    /*vision_signature_s_t BLUEFLAG;
    BLUEFLAG.id = 2;
    BLUEFLAG.range = 1.9;
    BLUEFLAG.u_min = -4097;
    BLUEFLAG.u_max = -1771;
    BLUEFLAG.u_mean = -2934;
    BLUEFLAG.v_min = 5209;
    BLUEFLAG.v_max = 13017;
    BLUEFLAG.v_mean = 9113;
    BLUEFLAG.type = 0;
    cpltVis.set_signature(2, &BLUEFLAG);

    vision_signature_s_t REDFLAG;
    REDFLAG.id = 3;
    REDFLAG.range = 1.9;
    REDFLAG.u_min = 5727;
    REDFLAG.u_max = 13413;
    REDFLAG.u_mean = 9670;
    REDFLAG.v_min = -1171;
    REDFLAG.v_max = -129;
    REDFLAG.v_mean = -650;
    REDFLAG.type = 0;
    cpltVis.set_signature(3, &REDFLAG);*/

}

void runCplt(float voltPerc) {

    cplt.move_voltage((voltPerc / 100) * 12000);

}

bool shoot = 0;

void cpltControl(void* param) {

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

void flagAim(bool height) {

    delay(50);

    PID aim = initPID(0, 0, 0, 0, 0, 0);
    PID dist = initPID(0, 0, 0, 0, 0, 0);

    double aimVal, distVal;
    int aimSum, distSum, distSetPoint, highY = -201, lowY = 201, closestX = 321, offset, time = 2000, Ycount, Xcount;

    for(int i = 0; i < time; i ++) {

        if(abs(cpltVis.get_object_count()) == 0) {
            break;
        }

        for(int j = 0; j < cpltVis.get_object_count(); j ++) {

            if(height == 0) {

                if(cpltVis.get_by_size(j).y_middle_coord < lowY)
                    highY = cpltVis.get_by_size(j).y_middle_coord;

            }
            
            else if(height == 1) {

                if(cpltVis.get_by_size(j).y_middle_coord > highY)
                    highY = cpltVis.get_by_size(j).y_middle_coord;

            }

            if(abs(cpltVis.get_by_size(j).x_middle_coord) < closestX)
                closestX = cpltVis.get_by_size(j).x_middle_coord;

            if(j)
                break;

        }

        if(lowY < 201 || highY > -201)
            Ycount++;
            distSum += (!height ? lowY : highY);

        if(closestX < 321)
            Xcount++;
            aimSum += closestX;
        
        closestX = 201;
        highY = -201;
        lowY = 201;

        if(!(i % 50)) {

            aim.error = -aimSum / Xcount;
            dist.error = (distSum / Ycount) - distSetPoint;

            aimVal = runPID(&aim);
            distVal = runPID(&dist);

            aimSum = 0;
            distSum = 0;

        }

    }

}