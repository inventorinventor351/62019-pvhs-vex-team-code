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

    if(abs(intkVis.get_by_size(0).x_middle_coord) > 320) {

        runLeftBase(0);
        runRightBase(0);

    }

    else {
        
        PID aim = initPID(0, 0, 0, 0, 0, 0);
        PID dist = initPID(0, 0, 0, 0, 0, 0);
        int lowestY = 1000, ObjX;
        float aimVal, distVal;
        runIntake(80);

        for(int i = 0; i < 3000 && isBall() == 0; i++) {

            for(int n = 1; n <= intkVis.get_object_count(); n++) {

                if(intkVis.get_by_size(n).y_middle_coord < lowestY){
                    lowestY = intkVis.get_by_size(n).y_middle_coord;
                    ObjX = intkVis.get_by_size(n).x_middle_coord;
                }

            }

            aim.error = -ObjX;
            dist.error = -200 - lowestY;
            aimVal = runPID(&aim);
            distVal = runPID(&dist);

            runLeftBase(distVal - aimVal);
            runRightBase(distVal + aimVal);

            delay(1);
            
        }

    }

    runIntake(0);

}

void initIntkVis() {

    vision_signature_s_t BALL;
    BALL.id = 1;
    BALL.range = 2.4;
    BALL.u_min = 1063;
    BALL.u_max = 2177;
    BALL.u_mean = 1620;
    BALL.v_min = -5013;
    BALL.u_max = -4037;
    BALL.v_mean = -4525;
    BALL.type = 0;
    shooterEye.set_signature(1, &BALL);
    
}