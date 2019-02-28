#include "main.h"

void runCplt(float voltPerc) {

    cplt.move_voltage((voltPerc / 100) * 12000);

}

bool shoot = 0;

void cpltControl(void* param) {

    PID frame = initPID(1, 0, 0, 1.5, 0, 1);
    PID cpltShoot = frame;
    int setpoint = 3280;
    float cpltVal;

    std::uint_least32_t now = millis();

    while(!(cplt.is_over_temp() && cplt.is_over_current())) {

        cpltShoot.error = setpoint - cpltPot.get_value();
        cpltVal = runPID(&cpltShoot);
        runCplt(cpltVal);
        
        if(shoot) {

            runCplt(100);
			delay(300);
			cpltShoot = frame;
            shoot = 0;
            
        }

        if(fatalBall.get_value())
            cplt.set_voltage_limit(0);

        else
            cplt.set_voltage_limit(12000);

        Task::delay_until(&now, 1);

    }

    runCplt(0);
    
}

void initCpltVis() {

    vision_signature_s_t GREENFLAG;
    GREENFLAG.id = 1;
    GREENFLAG.range = 3.5;
    GREENFLAG.u_min = -3383;
    GREENFLAG.u_max = -2431;
    GREENFLAG.u_mean = -2907;
    GREENFLAG.v_min = -4711;
    GREENFLAG.v_max = -2891;
    GREENFLAG.v_mean = -3801;
    GREENFLAG.type = 0;
    cpltVis.set_signature(1, &GREENFLAG);

}

void flagAim() {

    delay(50);

    PID aim = initPID(1, 1, 1, 0.65, 0.005, 2);
    PID dist = initPID(1, 0, 0, 1.5, 0, 0);

    double aimVal, distVal;
    int aimSum, distSum, highY = -201, closestX = 321, time = 1000, Ycount, Xcount;
    int offset = autonCount < 2 ? -10 : -20;
    int distSetPoint = -17;

    for(int i = 0; i < time; i ++) {

        if(abs(cpltVis.get_object_count()) == 0)
            break;

        for(int j = 0; j < cpltVis.get_object_count(); j ++) {

            if(cpltVis.get_by_size(j).y_middle_coord > highY)
                highY = cpltVis.get_by_size(j).y_middle_coord;

            if(abs(cpltVis.get_by_size(j).x_middle_coord) + offset < abs(closestX + offset))
                closestX = cpltVis.get_by_size(j).x_middle_coord;
                
            if(j)
                break;

        }

        if(abs(highY) < 201) {

            Ycount++;
            distSum += highY;

        }

        if(closestX < 321) {

            Xcount++;
            aimSum += closestX;

        }
        
        closestX = 321;
        highY = -201;

        if(!(i % 20)) {

            if(Xcount > 0 && Ycount > 0) {

            aim.error = (aimSum / Xcount) + offset;
            dist.error = (distSum / Ycount) - distSetPoint;

            }

            aimVal = runPID(&aim);
            distVal = runPID(&dist);

            runLeftBase(distVal + aimVal);
            runRightBase(distVal - aimVal);

            //std::cout << "aim error: " << aim.error << " | dist error: " << dist.error << " | aimVal: " << aimVal << " | distVal: " << distVal << "\n";

            aimSum = 0;
            distSum = 0;
            Xcount = 0;
            Ycount = 0;

        }

        delay(1);

    }

    runLeftBase(0);
    runRightBase(0);
    
    master.rumble("-");

}