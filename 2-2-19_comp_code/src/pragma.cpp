#include "main.h"

Controller master (CONTROLLER_MASTER); //master controller

//V5 Components
Motor leftBase1 (1, MOTOR_GEARSET_18, 1); //normal motor plugged into port 1 and not reversed
Motor leftBase2 (2, MOTOR_GEARSET_18, 0); //normal motor plugged into port 2 and not reversed
Motor rightBase1 (3, MOTOR_GEARSET_18, 0); //normal motor plugged into port 3 and not reversed
Motor rightBase2 (4, MOTOR_GEARSET_18, 1); //normal motor plugged into port 4 and not reversed
Motor intk (5, MOTOR_GEARSET_18, 0); //normal motor plugged into port 5 and not reversed
Motor cplt (6, MOTOR_GEARSET_18, 0); //normal motor plugged into port 6 and not reversed

Vision cpltVis (7, VISION_ZERO_CENTER); //vision sensor plugged into port 7 and (0,0) is at the center of the screen

Motor leftBase3 (8, MOTOR_GEARSET_18, 0); //normal motor plugged into port 8 and not reversed and only X team has it
Motor rightBase3 (9, MOTOR_GEARSET_18, 1); //normal motor plugged into port 9 and not reversed and only X team has it

//Legacy Components
ADIDigitalIn whichTeam (7); //jumper plugged into legacy port 1
ADIAnalogIn cpltPot (4); //potentiometer plugged into legacy port 2
ADIGyro gyro (3); //gryo plugged into legacy port 3
ADIEncoder distEnc (5, 4, 0); //encoder plugged into legacy ports 4 and 5 and not reversed

ADIDigitalOut descorer (8); //pistons y-cabled and plugged into legacy port 6 and only P team has it
ADIDigitalOut transPstn (2); //piston plugged into port 7 and only P team has it