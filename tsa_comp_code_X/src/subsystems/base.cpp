#include "main.h"

void runLeftBase(float voltPerc) {

    leftBase1.move_voltage((voltPerc / 100) * 12000);
    leftBase2.move_voltage((voltPerc / 100) * 12000);
    leftBase3.move_voltage((voltPerc / 100) * 12000);

}

void runRightBase(float voltPerc) {

    rightBase1.move_voltage((voltPerc / 100) * 12000);
    rightBase2.move_voltage((voltPerc / 100) * 12000);
    rightBase3.move_voltage((voltPerc / 100) * 12000);

}

float getDist() {

    return ((leftBase1.get_position() + leftBase2.get_position() + leftBase3.get_position() + rightBase1.get_position() + rightBase2.get_position() + rightBase3.get_position()) / 6);

}

float getDiff() {

    return ((leftBase1.get_position() + leftBase2.get_position() + leftBase3.get_position() - rightBase1.get_position() - rightBase2.get_position() - rightBase3.get_position()) / 6);

}

void resetEncs() {

    leftBase1.tare_position();
    leftBase2.tare_position();
    leftBase3.tare_position();
    rightBase1.tare_position();
    rightBase2.tare_position();
    rightBase3.tare_position();

}

float yaw = 0.0;
bool resetYaw = 0;

void getYaw(void* param) {

    float rawYaw = 0.0, prevYaw = 0.0, drift = 0.0;
    bool useGyro1 = 1, useGyro2 = 1;
    std::uint_least32_t now = millis();

    while(true) {

        if(resetYaw) {

            gyro1.reset();
            gyro2.reset();
            useGyro1 = 1;
            useGyro2 = 1;

            rawYaw = 0;
            drift = 0;
            yaw = 0;
            prevYaw = 0;

            resetYaw = 0;
        
        }

        if(abs(prevYaw - gyro1.get_value()) > 10)
            useGyro1 = 0;

        if(abs(prevYaw + gyro2.get_value()) > 10)
            useGyro2 = 0;

        rawYaw = ((gyro1.get_value() * useGyro1) - (gyro2.get_value() * useGyro2)) / (useGyro1 + useGyro2);
        prevYaw = rawYaw;

        if((useGyro1 + useGyro2) == 2) 
            drift = (useGyro1 * gyro1.get_value() + useGyro2 * gyro2.get_value()) / 2;
        else
            drift = 0;

        yaw = drift - rawYaw;
        prevYaw = rawYaw;

        //std::cout << gyro1.get_value() << " | " << gyro2.get_value() << " | " << gyro3.get_value() << " | " << rawYaw << " | " << drift << " | " << yaw << "\n";

        Task::delay_until(&now, 1);

    }

}

void moveStraight(float setPoint, int time) {

    float distVal, diffVal;
    setPoint *= 0.678788;

    PID dist = initPID(1, 0, 1, 0.5, 0, 1);
    PID diff = initPID(1, 0, 0, 2, 0, 0);

    resetEncs();
    resetYaw = 1;
    delay(1);

    for(int i = 0; i < time; i++) {

        dist.error = setPoint - getDist();  
        diff.error = yaw;

        distVal = runPID(&dist);
        distVal = (abs(distVal) > 90) ? (90 * sgn(distVal)) : distVal;
        diffVal = runPID(&diff);

        if(i < 50) {
            distVal *= 0.5;
            diffVal *= 0.5;
        }


        if(!(i % 10))
            std::cout << "yaw: " << yaw << "  |  " << "distEnc: " << getDist() << "  |  " << "Err: " << dist.error << "  |  " << "setPnt: " << setPoint << "  |  " << "diffErr: " << diff.error << "  |  " << "distVal: " << distVal << "  |  " << "diffVal: " << diffVal << "  |  time: " << i << "\n";

        runLeftBase(distVal - diffVal);
        runRightBase(distVal + diffVal);

        delay(1);

    }

    runLeftBase(0);
    runRightBase(0);

}

void pvtBase(float setPoint, int time) {

    float yawVal, dispVal, prevYaw;
    setPoint *= -1;

    PID YAW = initPID(1, 0, 0, 1.3, 0, 0);
    PID disp = initPID(1, 0, 0, 1, 0, 0);

    resetEncs();
    resetYaw = 1;
    delay(1);

    for(int i = 0; i < time; i++) {

        YAW.error = yaw - setPoint;
        disp.error = getDist();

        yawVal = runPID(&YAW);
        dispVal = runPID(&disp);

        std::cout << "yaw: " << yaw << "  |  " << "Err: " << YAW.error << "  |  " << "setPnt: " << setPoint << "  |  " << "dispErr: " << disp.error << "  |  " << "yawVal: " << yawVal << "  |  " << "dispVal: " << dispVal << "  |  " << "ms: " << i << "\n";

        runLeftBase(-yawVal - dispVal);
        runRightBase(yawVal - dispVal);

        delay(1);

    }

    runLeftBase(0);
    runRightBase(0);

}



void turn(float setPoint, int time) {

    float yawVal, dispVal, prevYaw;
    //setPoint *= -4.0366;
    setPoint *= -3.3;

    PID YAW = initPID(1, 0, 0, 1.3, 0, 0);
    PID disp = initPID(1, 0, 0, 1, 0, 0);

    resetEncs();
    delay(1);

    for(int i = 0; i < time; i++) {

        YAW.error = setPoint - getDiff();
        disp.error = getDist();

        yawVal = runPID(&YAW);
        dispVal = runPID(&disp);

        std::cout << "yaw: " << getDiff() << " | " << "Err: " << YAW.error << " | " << "setPnt: " << setPoint << " | " << "dispErr: " << disp.error << " | " << "yawVal: " << yawVal << " | " << "dispVal: " << dispVal << " | " << "ms: " << i << "\n";

        runLeftBase(yawVal - dispVal);
        runRightBase(-yawVal - dispVal);

        delay(1);

    }

    runLeftBase(0);
    runRightBase(0);

}