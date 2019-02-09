#include "main.h"

Controller master (CONTROLLER_MASTER); //master controller

//V5 Components
Motor leftBase1 (9, MOTOR_GEARSET_18, 0); //normal motor plugged into port 9 and not reversed
Motor leftBase2 (7, MOTOR_GEARSET_18, 1); //normal motor plugged into port 7 and reversed
Motor leftBase3 (8, MOTOR_GEARSET_18, 0); //normal motor plugged into port 8 and not reversed
Motor rightBase1 (18, MOTOR_GEARSET_18, 0); //normal motor plugged into port 18 and reversed
Motor rightBase2 (17, MOTOR_GEARSET_18, 1); //normal motor plugged into port 17 and not reversed
Motor rightBase3 (19, MOTOR_GEARSET_18, 0); //normal motor plugged into port 19 and reversed
Motor intk (15, MOTOR_GEARSET_18, 1); //normal motor plugged into port 15 and not reversed
Motor cplt (16, MOTOR_GEARSET_18, 0); //normal motor plugged into port 16 and not reversed

Vision cpltVis (10, VISION_ZERO_CENTER); //vision sensor plugged into port 9 and (0,0) is at the center of the screen

//Legacy Components
ADIGyro gyro1 (3); //gyro plugged into port 3
ADIGyro gyro2 (4); //gyro plugged into port 4
ADIAnalogIn cpltPot (5); //catapult plugged into port 5
ADIDigitalIn whichTeam (7); //jumper plugged into port 7