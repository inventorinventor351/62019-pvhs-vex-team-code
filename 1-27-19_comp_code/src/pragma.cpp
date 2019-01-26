#include "main.h"

Motor leftBase1 (1, MOTOR_GEARSET_18, 1); //normal motor plugged into port 1 and not reversed
Motor leftBase2 (2, MOTOR_GEARSET_18, 0); //normal motor plugged into port 2 and not reversed
Motor rightBase1 (3, MOTOR_GEARSET_18, 0); //normal motor plugged into port 3 and reversed
Motor rightBase2 (4, MOTOR_GEARSET_18, 1); //normal motor plugged into port 4 and reversed
Motor intk (5, MOTOR_GEARSET_18, 0); //normal motor plugged into port 5 and not reversed
Motor cplt (6, MOTOR_GEARSET_18, 0); //normal motor plugged into port 6 and not reversed

Vision intkVis (7, VISION_ZERO_CENTER); //vision sensor plugged into port 7 and (0,0) is at the center of the screen
Vision cpltVis (8, VISION_ZERO_CENTER); //vision sensor plugged into port 8 and (0,0) is at the center of the screen

ADIDigitalOut transPstn (2); //piston plugged into port 2
ADIDigitalOut descorer (8); //pistons y-cabled in port 8 to descore high caps
ADIDigitalIn PorX (1); //jumper used to detemine which robot is being used, in port 1

ADIGyro gyro (3); //gryo used for turning in autonomous in port 3
ADIAnalogIn cpltPot (4); //potentiometer plugged into legacy port 4

ADIEncoder distEnc (5, 6, 0); //encoder plugged into legacy ports 5 and 6 and not reversed

Controller master (CONTROLLER_MASTER); //master controller
