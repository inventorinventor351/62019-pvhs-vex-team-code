#include "main.h"

Controller master (CONTROLLER_MASTER); //master controller

//V5 Components
Motor leftBase1 (16, MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_DEGREES); //normal motor plugged into port 16 and not reversed
Motor leftBase2 (17, MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_DEGREES); //normal motor plugged into port 17 and reversed
Motor leftBase3 (18, MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_DEGREES); //normal motor plugged into port 18 and not reversed
Motor rightBase1 (13, MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_DEGREES); //normal motor plugged into port 13 and reversed
Motor rightBase2 (14, MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_DEGREES); //normal motor plugged into port 14 and not reversed
Motor rightBase3 (15, MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_DEGREES); //normal motor plugged into port 15 and reversed
Motor intk (20, MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_DEGREES); //normal motor plugged into port 20 and not reversed
Motor cplt (2, MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_DEGREES); //normal motor plugged into port 2 and not reversed

Vision cpltVis (4, VISION_ZERO_CENTER); //vision sensor plugged into port 3 and (0,0) is at the center of the screen


//Legacy Components
ADIDigitalIn whichTeam (1); //jumper plugged into port 1
ADIDigitalIn fatalBall(2); //limit switch that detects a fatal ball in catapult into port 2
ADIAnalogIn cpltPot (3); //catapult plugged into port 3
ADIGyro gyro1 (6, 0.09375); //gyro plugged into port 4
ADIGyro gyro2 (7, 0.09375); //gyro plugged into port 5
ADIGyro gyro3 (5, 0.09375);