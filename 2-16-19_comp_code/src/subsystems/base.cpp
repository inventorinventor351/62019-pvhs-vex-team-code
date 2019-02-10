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

    return ((leftBase1.get_position() + leftBase2.get_position() + leftBase3.get_position() + rightBase1.get_position() + rightBase2.get_position() + rightBase3.get_position()) * 360 / (900 * 6));

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

    delay(1225);
    gyro1.reset();
    gyro2.reset();

    int gyro1prev;
    int gyro2prev;
    bool useGyro1 = 1;
    bool useGyro2 = 1;

    std::uint_least32_t now = millis();

    while(true) {

        if(resetYaw) {

            delay(100);
            gyro1.reset();
            gyro2.reset();
            yaw = 0;
            resetYaw = 0;
        
        }

        if((abs(gyro1.get_value() - gyro1prev)) > 50) 
            useGyro1 = 0;

        if((abs(gyro2.get_value() - gyro2prev)) > 50) 
            useGyro2 = 0;

        gyro1prev = gyro1.get_value();
        gyro2prev = gyro2.get_value();

        yaw = ((useGyro1 ? gyro1.get_value() : 0) + (useGyro2 ? gyro2.get_value() : 0)) * (0.094 / ((useGyro1 + useGyro2) > 0 ? (useGyro1 + useGyro2) : 1));

        Task::delay_until(&now, 1);

    }

}

void moveStraight(float setPoint, int time) {

    float distVal, diffVal;

    PID dist = PorX(initPID(1, 0, 1, 0.1, 0, 0.275), initPID(1, 0, 1, 0.3, 0, 1));
    PID diff = PorX(initPID(1, 0, 0, 0.8, 0, 0), initPID(1, 0, 0, 0.5, 0, 0));

    resetEncs();
    resetYaw = 1;

    for(int i = 0; i < time; i++) {

        dist.error = setPoint - getDist();  
        diff.error = yaw;

        distVal = runPID(&dist);
        distVal = (abs(distVal) > 90) ? (90 * sgn(distVal)) : distVal;
        diffVal = runPID(&diff);

        std::cout << "yaw: " << yaw << "  |  " << "distEnc: " << getDist() << "  |  " << "Err: " << dist.error << "  |  " << "setPnt: " << setPoint << "  |  " << "diffErr: " << diff.error << "  |  " << "distVal: " << distVal << "  |  " << "diffVal: " << diffVal << "  |  " << "ms: " << i << "\n";

        runLeftBase(distVal - diffVal);
        runRightBase(distVal + diffVal);

        delay(1);

    }

    runLeftBase(0);
    runRightBase(0);

}

void pvtBase(float setPoint, int time) {

    float yawVal, dispVal, prevYaw;

    PID YAW = initPID(1, 0, 0, 1.1, 0, 0);
    PID disp = initPID(0, 0, 0, 0, 0, 0);

    resetEncs();
    resetYaw = 1;

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