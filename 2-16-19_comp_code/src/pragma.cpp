#include "main.h"

Controller master (CONTROLLER_MASTER); //master controller

//V5 Components
Motor leftBase1 (1, MOTOR_GEARSET_18, 0); //normal motor plugged into port 1 and not reversed
Motor leftBase2 (2, MOTOR_GEARSET_18, 0); //normal motor plugged into port 2 and not reversed
Motor leftBase3 (3, MOTOR_GEARSET_18, 0); //normal motor plugged into port 3 and not reversed
Motor rightBase1 (4, MOTOR_GEARSET_18, 0); //normal motor plugged into port 4 and not reversed
Motor rightBase2 (5, MOTOR_GEARSET_18, 0); //normal motor plugged into port 5 and not reversed
Motor rightBase3 (6, MOTOR_GEARSET_18, 0); //normal motor plugged into port 6 and not reversed
Motor intk (7, MOTOR_GEARSET_18, 0); //normal motor plugged into port 7 and not reversed
Motor cplt (8, MOTOR_GEARSET_18, 0); //normal motor plugged into port 8 and not reversed

Vision cpltVis (9, VISION_ZERO_CENTER); //vision sensor plugged into port 9 and (0,0) is at the center of the screen

//Legacy Components
ADIDigitalIn whichTeam (7);
ADIAnalogIn cpltPot (2); //potentiometer plugged into port 2
ADIGyro gyro (3); //gyro plugged into port 3
ADIEncoder distEnc (5, 6, 0); //shaft encoder plugged into ports 5 and 6, not reversed