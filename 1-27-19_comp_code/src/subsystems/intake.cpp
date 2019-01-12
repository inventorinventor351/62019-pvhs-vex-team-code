#include "main.h"

void runIntake(float voltPerc) {

    intk.move_voltage((voltPerc / 100) * 12000);

}

void runIntakeTime(float voltPerc, int time) {

    intk.move_voltage((voltPerc / 100) * 12000);
    delay(time);
    intk.move_voltage(0);

}

bool isBall() {

    int i;
    
    if(ballSensor.get_value() < 14) 
        i = 1;
    else
        i = 0;

    return i;
    
}

void getBall() {

    if(intkVis.get_object_count() == 0) {

        runLeftBase(0);
        runRightBase(0);

        master.print(0, 0, "Did not find");

    }

    else {
        
        PID aim = initPID(1, 0, 0, 0.3, 0, 0);
        PID dist = initPID(1, 0, 0, 0.5, 0, 0);
        int lowestY = 1000, objX;
        float aimVal, distVal;
        runIntake(-80);

        for(int i = 0; i < 2000; i++) {

            if(intkVis.get_object_count() == 0) {
                runLeftBase(0);
                runRightBase(0);
                master.print(0, 0, "Lost Ball");
                break;
            }

            for(int n = 0; n < intkVis.get_object_count(); n++) {

                if(intkVis.get_by_size(n).y_middle_coord < lowestY){
                    lowestY = intkVis.get_by_size(n).y_middle_coord;
                    objX = intkVis.get_by_size(n).x_middle_coord;
                }

            }

            std::cout << "Y: " << lowestY << " | " << "X: " << objX << "\n";

            aim.error = -objX;
            dist.error = -200 - lowestY;
            aimVal = runPID(&aim);
            distVal = runPID(&dist);
            lowestY = 1000;

            runLeftBase(-distVal - aimVal);
            runRightBase(-distVal + aimVal);

            delay(1);
            
        }

    }

    delay(200);
    runIntake(0);

}

void initIntkVis() {

    vision_signature_s_t BALL;
    BALL.id = 1;
    BALL.range = 2.3;
    BALL.u_min = 51;
    BALL.u_max = 1795;
    BALL.u_mean = 923;
    BALL.v_min = -5355;
    BALL.v_max = -4649;
    BALL.v_mean = -5002;
    BALL.type = 0;
    intkVis.set_signature(1, &BALL);
    
}